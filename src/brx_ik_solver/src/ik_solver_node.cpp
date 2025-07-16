// trac_ik + kdl 对比联合使用节点
// 原有的 TracIKSolver 基础上添加 KDL 解算输出 + 发布 JointState

#include <ros/ros.h>
#include <urdf/model.h>
#include <trac_ik/trac_ik.hpp>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/PoseStamped.h>
#include <brx_ik_solver/IkControlInput.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>
#include <kdl/frames.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl_parser/kdl_parser.hpp>

class TracIKSolver {
public:
    TracIKSolver(ros::NodeHandle& nh,
                 const std::string& base_link,
                 const std::string& tip_link,
                 const std::string& input_topic,
                 const std::string& output_topic,
                 const std::vector<std::string>& joint_names,
                 const std::string& urdf_param = "/robot_description")
        : nh_(nh), joint_names_(joint_names), base_link_(base_link), tip_link_(tip_link) {

        std::string urdf_string;
        if (!nh_.getParam(urdf_param, urdf_string)) {
            ROS_ERROR("Failed to get URDF from param server");
            return;
        }

        urdf::Model urdf_model;
        if (!urdf_model.initString(urdf_string)) {
            ROS_ERROR("Failed to parse URDF");
            return;
        }

        if (!kdl_parser::treeFromUrdfModel(urdf_model, kdl_tree_)) {
            ROS_ERROR("Failed to construct KDL tree");
            return;
        }

        if (!kdl_tree_.getChain(base_link_, tip_link_, kdl_chain_)) {
            ROS_ERROR("Failed to get KDL chain from %s to %s", base_link_.c_str(), tip_link_.c_str());
            return;
        }

        tracik_solver_ = std::make_shared<TRAC_IK::TRAC_IK>(base_link_, tip_link_, urdf_param, 1, 1);
        ik_solver_kdl_ = std::make_shared<KDL::ChainIkSolverPos_LMA>(kdl_chain_);

        q_init_ = KDL::JntArray(kdl_chain_.getNrOfJoints());
        q_result_ = KDL::JntArray(kdl_chain_.getNrOfJoints());

        input_sub_ = nh_.subscribe(input_topic, 1, &TracIKSolver::inputCallback, this);
        joint_pub_ = nh_.advertise<sensor_msgs::JointState>(output_topic, 1);

        ROS_INFO("✅ Dual IK Solver initialized from [%s] to [%s]", base_link_.c_str(), tip_link_.c_str());
    }

private:
    void inputCallback(const brx_ik_solver::IkControlInput::ConstPtr& msg) {
        const geometry_msgs::Pose& pose = msg->pose;

        tf::Quaternion quat;
        tf::quaternionMsgToTF(pose.orientation, quat);
        double roll, pitch, yaw;
        tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

        KDL::Frame target_pose(KDL::Rotation::RPY(roll, pitch, yaw),
                               KDL::Vector(pose.position.x, pose.position.y, pose.position.z));

        for (size_t i = 0; i < q_init_.rows(); ++i) {
            q_init_(i) = 0.0;
            if (i < msg->lock_joint.size() && msg->lock_joint[i])
                q_init_(i) = msg->lock_values[i];
        }

        ROS_INFO("\n============================\n📌 Solving IK for target pose:");
        ROS_INFO("Position: [%.3f, %.3f, %.3f]", pose.position.x, pose.position.y, pose.position.z);
        ROS_INFO("RPY: [%.3f, %.3f, %.3f]", roll, pitch, yaw);

        // === TRAC-IK ===
        int tracik_result = tracik_solver_->CartToJnt(q_init_, target_pose, q_result_);
        if (tracik_result >= 0) {
            ROS_INFO("✅ TRAC-IK Solved:");
            sensor_msgs::JointState joint_msg;
            joint_msg.header.stamp = ros::Time::now();

            for (size_t i = 0; i < joint_names_.size(); ++i) {
                joint_msg.name.push_back(joint_names_[i]);
                joint_msg.position.push_back(q_result_(i));
                ROS_INFO("  [%s] = %.3f", joint_names_[i].c_str(), q_result_(i));
            }

            joint_pub_.publish(joint_msg);  // ✅ 重要：发布到 joint_states
        } else {
            ROS_WARN("❌ TRAC-IK failed. Code: %d", tracik_result);
        }

        // === KDL-LMA ===
        KDL::JntArray kdl_result(kdl_chain_.getNrOfJoints());
        int kdl_ret = ik_solver_kdl_->CartToJnt(q_init_, target_pose, kdl_result);
        if (kdl_ret >= 0) {
            ROS_INFO("✅ KDL-LMA Solved:");
            for (size_t i = 0; i < joint_names_.size(); ++i)
                ROS_INFO("  [%s] = %.3f", joint_names_[i].c_str(), kdl_result(i));
        } else {
            ROS_WARN("❌ KDL-LMA failed. Code: %d", kdl_ret);
        }
    }

    ros::NodeHandle nh_;
    ros::Subscriber input_sub_;
    ros::Publisher joint_pub_;

    std::vector<std::string> joint_names_;
    std::string base_link_, tip_link_;

    KDL::Tree kdl_tree_;
    KDL::Chain kdl_chain_;
    std::shared_ptr<TRAC_IK::TRAC_IK> tracik_solver_;
    std::shared_ptr<KDL::ChainIkSolverPos_LMA> ik_solver_kdl_;
    KDL::JntArray q_init_, q_result_;
};


int main(int argc, char** argv) {
    ros::init(argc, argv, "trac_ik_dual_solver_node");
    ros::NodeHandle nh;

    std::vector<std::string> left_joint_names = {
        "ArmL02_Joint", "ArmL03_Joint", "ArmL04_Joint",
        "ArmL05_Joint", "ArmL06_Joint", "ArmL07_Joint", "ArmL08_Joint"
    };
    std::vector<std::string> right_joint_names = {
        "ArmR02_Joint", "ArmR03_Joint", "ArmR04_Joint",
        "ArmR05_Joint", "ArmR06_Joint", "ArmR07_Joint", "ArmR08_Joint"
    };

    TracIKSolver left_arm(nh, "ArmL01_Link", "ArmL08_Link",
                          "/left_ik_control_input", "/left_ik_joint_states",
                          left_joint_names);

    TracIKSolver right_arm(nh, "ArmR01_Link", "ArmR08_Link",
                           "/right_ik_control_input", "/right_ik_joint_states",
                           right_joint_names);

    ros::spin();
    return 0;
}

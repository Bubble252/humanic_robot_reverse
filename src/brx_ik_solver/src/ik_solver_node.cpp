#include <ros/ros.h>
#include <kdl_parser/kdl_parser.hpp>
#include <urdf/model.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/PoseStamped.h>
#include <kdl/chain.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/frames.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <tf/transform_datatypes.h>

class IKSolverNode {
public:
    IKSolverNode(ros::NodeHandle& nh,
                 const std::string& base_link,
                 const std::string& tip_link,
                 const std::string& pose_topic,
                 const std::string& joint_topic,
                 const std::vector<std::string>& joint_names,
                 const std::string& urdf_param = "/robot_description")
        : nh_(nh), base_link_(base_link), tip_link_(tip_link), urdf_param_(urdf_param), joint_names_(joint_names) {

        std::string urdf_string;
        if (!nh_.getParam(urdf_param_, urdf_string)) {
            ROS_ERROR("Failed to get URDF from param server.");
            return;
        }

        urdf::Model urdf_model;
        if (!urdf_model.initString(urdf_string)) {
            ROS_ERROR("Failed to parse URDF.");
            return;
        }

        KDL::Tree kdl_tree;
        if (!kdl_parser::treeFromUrdfModel(urdf_model, kdl_tree)) {
            ROS_ERROR("Failed to construct KDL tree.");
            return;
        }

        if (!kdl_tree.getChain(base_link_, tip_link_, kdl_chain_)) {
            ROS_ERROR("Failed to extract KDL chain from %s to %s", base_link_.c_str(), tip_link_.c_str());
            return;
        }

        if (kdl_chain_.getNrOfJoints() != joint_names_.size()) {
            ROS_WARN("Number of joints in KDL chain (%d) and provided joint names (%lu) do not match.",
                     kdl_chain_.getNrOfJoints(), joint_names_.size());
        }

        fk_solver_ = std::make_shared<KDL::ChainFkSolverPos_recursive>(kdl_chain_);
        ik_solver_vel_ = std::make_shared<KDL::ChainIkSolverVel_pinv>(kdl_chain_);
        ik_solver_ = std::make_shared<KDL::ChainIkSolverPos_LMA>(kdl_chain_);

        pose_sub_ = nh_.subscribe(pose_topic, 1, &IKSolverNode::poseCallback, this);
        joint_pub_ = nh_.advertise<sensor_msgs::JointState>(joint_topic, 1);

        ROS_INFO("IK Solver for %s → %s initialized.", base_link_.c_str(), tip_link_.c_str());
    }

private:
    void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg) {
        tf::Quaternion quat;
        tf::quaternionMsgToTF(msg->pose.orientation, quat);
        double roll, pitch, yaw;
        tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

    //    KDL::Frame target_pose(KDL::Rotation::RPY(roll, pitch, yaw),
    //                          KDL::Vector(msg->pose.position.x, msg->pose.position.y, msg->pose.position.z));
                              
         
         
         
KDL::Frame target_world(
    KDL::Rotation::RPY(roll, pitch, yaw),
    KDL::Vector(msg->pose.position.x, msg->pose.position.y, msg->pose.position.z));

// ArmL01_Link 相对 base_link 的姿态补偿（取逆变换）
KDL::Frame base_to_Arm01(
    KDL::Rotation::RPY(1.57, 0, 3.14), 
    KDL::Vector(0, 0, 0)); // 假设只有姿态补偿，没有位置偏移（或者根据TF填充）

// 将目标从 base_link 系转换到 Arm01_Link 系下
KDL::Frame target_pose = base_to_Arm01 * target_world;                     
                              
                              
                              

        KDL::JntArray q_init(kdl_chain_.getNrOfJoints());
        KDL::JntArray q_result(kdl_chain_.getNrOfJoints());

        for (unsigned int i = 0; i < kdl_chain_.getNrOfJoints(); ++i)
            q_init(i) = 0.0;

        int ret = ik_solver_->CartToJnt(q_init, target_pose, q_result);
        if (ret >= 0) {
            sensor_msgs::JointState joint_msg;
            joint_msg.header.stamp = ros::Time::now();

            for (size_t i = 0; i < joint_names_.size(); ++i) {
                joint_msg.name.push_back(joint_names_[i]);
                joint_msg.position.push_back(q_result(i));
            }

            joint_pub_.publish(joint_msg);
        } else {
            ROS_WARN("IK failed for base %s", base_link_.c_str());
        }
    }

    ros::NodeHandle nh_;
    ros::Subscriber pose_sub_;
    ros::Publisher joint_pub_;
    std::string base_link_, tip_link_, urdf_param_;
    KDL::Chain kdl_chain_;
    std::shared_ptr<KDL::ChainFkSolverPos_recursive> fk_solver_;
    std::shared_ptr<KDL::ChainIkSolverVel_pinv> ik_solver_vel_;
    std::shared_ptr<KDL::ChainIkSolverPos_LMA> ik_solver_;
    std::vector<std::string> joint_names_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ik_dual_solver_node");
    ros::NodeHandle nh;

    std::vector<std::string> left_joint_names = {
        "ArmL02_Joint", "ArmL03_Joint", "ArmL04_Joint", 
        "ArmL05_Joint", "ArmL06_Joint", "ArmL07_Joint", "ArmL08_Joint"
    };

    std::vector<std::string> right_joint_names = {
        "ArmR02_Joint", "ArmR03_Joint", "ArmR04_Joint",
        "ArmR05_Joint", "ArmR06_Joint", "ArmR07_Joint", "ArmR08_Joint"
    };

    IKSolverNode left_arm(nh,
                          "ArmL01_Link",
                          "ArmL08_Link",
                          "/target_pose_left",
                          "/left_ik_joint_states",
                          left_joint_names);

    IKSolverNode right_arm(nh,
                           "ArmR01_Link",
                           "ArmR08_Link",
                           "/target_pose_right",
                           "/right_ik_joint_states",
                           right_joint_names);

    ros::spin();
    return 0;
}


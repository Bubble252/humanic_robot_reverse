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
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <algorithm>

class TracIKSolver {
public:
    TracIKSolver(ros::NodeHandle& nh,
                 const std::string& base_link,
                 const std::string& tip_link,
                 const std::string& input_topic,
                 const std::string& output_topic,
                 const std::vector<std::string>& joint_names,
                 const std::string& urdf_param = "/robot_description")
        : nh_(nh),
          base_link_(base_link),
          tip_link_(tip_link),
          joint_names_(joint_names),
          current_joint_positions_(joint_names.size(), 0.0)
    {
        std::string urdf_string;
        if (!nh_.getParam(urdf_param, urdf_string)) {
            ROS_ERROR("Failed to get URDF from param server");
            ros::shutdown();
            return;
        }

        urdf::Model urdf_model;
        if (!urdf_model.initString(urdf_string)) {
            ROS_ERROR("Failed to parse URDF");
            ros::shutdown();
            return;
        }

        if (!kdl_parser::treeFromUrdfModel(urdf_model, kdl_tree_)) {
            ROS_ERROR("Failed to construct KDL tree");
            ros::shutdown();
            return;
        }

        if (!kdl_tree_.getChain(base_link_, tip_link_, kdl_chain_)) {
            ROS_ERROR("Failed to get KDL chain from %s to %s", base_link_.c_str(), tip_link_.c_str());
            ros::shutdown();
            return;
        }

        tracik_solver_ = std::make_shared<TRAC_IK::TRAC_IK>(base_link_, tip_link_, urdf_param, 15, 0.001);
        ik_solver_kdl_ = std::make_shared<KDL::ChainIkSolverPos_LMA>(kdl_chain_);

        q_init_ = KDL::JntArray(kdl_chain_.getNrOfJoints());
        q_result_ = KDL::JntArray(kdl_chain_.getNrOfJoints());

        // 订阅机械臂当前关节状态
        joint_state_sub_ = nh_.subscribe("/joint_states", 10, &TracIKSolver::jointStateCallback, this);

        // 订阅 IK 目标输入
        input_sub_ = nh_.subscribe(input_topic, 1, &TracIKSolver::inputCallback, this);

        // 发布 IK 计算得到的关节状态
        joint_pub_ = nh_.advertise<sensor_msgs::JointState>(output_topic, 1);

        ROS_INFO("TracIKSolver initialized: %s -> %s", base_link_.c_str(), tip_link_.c_str());
    }

private:
    void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        ROS_INFO("\n=============RECEIVE===============");
        // 根据 joint_names_ 找到对应角度，保存最新状态
        for (size_t i = 0; i < joint_names_.size(); ++i) {
            auto it = std::find(msg->name.begin(), msg->name.end(), joint_names_[i]);
            if (it != msg->name.end()) {
                size_t index = std::distance(msg->name.begin(), it);
                current_joint_positions_[i] = msg->position[index];
                ROS_DEBUG("Joint [%s] = %.5f", joint_names_[i].c_str(), current_joint_positions_[i]);
            } else {
                // 找不到关节名，默认 0
                current_joint_positions_[i] = 0.0;
                ROS_WARN("Joint [%s] not found in /joint_states!", joint_names_[i].c_str());

            }
        }
    }

    void inputCallback(const brx_ik_solver::IkControlInput::ConstPtr& msg) {
        const geometry_msgs::Pose& pose = msg->pose;

        // 转换目标姿态为 KDL Frame
        tf::Quaternion quat;
        tf::quaternionMsgToTF(pose.orientation, quat);
        double roll, pitch, yaw;
        tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

        KDL::Frame target_world(KDL::Rotation::RPY(roll, pitch, yaw),
                              KDL::Vector(pose.position.x, pose.position.y, pose.position.z));

        
        // ArmL01_Link 相对 base_link 的姿态补偿（取逆变换）
        KDL::Frame base_to_Arm01(
        KDL::Rotation::RPY(1.57, 0, 3.14), 
        KDL::Vector(0, 0, 0)); // 假设只有姿态补偿，没有位置偏移（或者根据TF填充）



        // 将目标从 base_link 系转换到 Arm01_Link 系下
        KDL::Frame target_pose = base_to_Arm01 * target_world;       



        // 用最新缓存的机械臂关节角度赋初值 q_init_
        for (size_t i = 0; i < q_init_.rows(); ++i) {
            q_init_(i) = current_joint_positions_[i];
        }

        ROS_INFO("\n============================");
        ROS_INFO(" Solving IK for target pose:");
        ROS_INFO(" Position: [%.3f, %.3f, %.3f]", pose.position.x, pose.position.y, pose.position.z);
        ROS_INFO(" RPY: [%.3f, %.3f, %.3f]", roll, pitch, yaw);

        // // === TRAC-IK 求解 ===
        // int tracik_result = tracik_solver_->CartToJnt(q_init_, target_pose, q_result_);
        // if (tracik_result >= 0) {
        //     ROS_INFO("✅ TRAC-IK Solved:");
        //     sensor_msgs::JointState joint_msg;
        //     joint_msg.header.stamp = ros::Time::now();

        //     for (size_t i = 0; i < joint_names_.size(); ++i) {
        //         joint_msg.name.push_back(joint_names_[i]);
        //         joint_msg.position.push_back(q_result_(i));
        //         ROS_INFO("  [%s] = %.3f", joint_names_[i].c_str(), q_result_(i));
        //     }
        //     joint_pub_.publish(joint_msg);
        // } else {
        //     ROS_WARN(" TRAC-IK failed. Code: %d", tracik_result);
        // }

        // // === KDL-LMA 求解 ===
        // KDL::JntArray kdl_result(kdl_chain_.getNrOfJoints());
        // int kdl_ret = ik_solver_kdl_->CartToJnt(q_init_, target_pose, kdl_result);
        // if (kdl_ret >= 0) {
        //     ROS_INFO("KDL-LMA Solved:");
        //     for (size_t i = 0; i < joint_names_.size(); ++i) {
        //         ROS_INFO("  [%s] = %.3f", joint_names_[i].c_str(), kdl_result(i));
        //     }
        // } else {
        //     ROS_WARN(" KDL-LMA failed. Code: %d", kdl_ret);
        // }

            // === KDL-LMA 求解 ===
    KDL::JntArray kdl_result(kdl_chain_.getNrOfJoints());
    int kdl_ret = ik_solver_kdl_->CartToJnt(q_init_, target_pose, kdl_result);
    if (kdl_ret >= 0) {
        ROS_INFO("✅ KDL-LMA Solved:");
        sensor_msgs::JointState joint_msg;
        joint_msg.header.stamp = ros::Time::now();

        for (size_t i = 0; i < joint_names_.size(); ++i) {
            joint_msg.name.push_back(joint_names_[i]);
            joint_msg.position.push_back(kdl_result(i));
            ROS_INFO("  [%s] = %.3f", joint_names_[i].c_str(), kdl_result(i));
        }
        joint_pub_.publish(joint_msg);
    } else {
        ROS_WARN(" KDL-LMA failed. Code: %d", kdl_ret);
    }
        
        
        
        
    }

    ros::NodeHandle nh_;
    ros::Subscriber joint_state_sub_;
    ros::Subscriber input_sub_;
    ros::Publisher joint_pub_;

    std::string base_link_, tip_link_;
    std::vector<std::string> joint_names_;

    KDL::Tree kdl_tree_;
    KDL::Chain kdl_chain_;

    std::shared_ptr<TRAC_IK::TRAC_IK> tracik_solver_;
    std::shared_ptr<KDL::ChainIkSolverPos_LMA> ik_solver_kdl_;

    KDL::JntArray q_init_;
    KDL::JntArray q_result_;

    std::vector<double> current_joint_positions_;
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

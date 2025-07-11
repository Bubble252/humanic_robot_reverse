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
    IKSolverNode(ros::NodeHandle& nh) : nh_(nh) {
        nh_.param<std::string>("base_link", base_link_, "ArmL01_Link");
        nh_.param<std::string>("tip_link", tip_link_, "ArmL08_Link");
        nh_.param<std::string>("urdf_param", urdf_param_, "/robot_description");

        std::string urdf_string;
        if (!nh_.getParam(urdf_param_, urdf_string)) {
            ROS_ERROR("Failed to get URDF from parameter server.");
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

        fk_solver_.reset(new KDL::ChainFkSolverPos_recursive(kdl_chain_));
        ik_solver_vel_.reset(new KDL::ChainIkSolverVel_pinv(kdl_chain_));
        ik_solver_.reset(new KDL::ChainIkSolverPos_LMA(kdl_chain_));

        pose_sub_ = nh_.subscribe("/target_pose", 1, &IKSolverNode::poseCallback, this);
        joint_pub_ = nh_.advertise<sensor_msgs::JointState>("/ik_joint_states", 1);


        ROS_INFO("IK Solver Node initialized.");
    }

private:
    void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    // 将 orientation.x/y/z 解释为欧拉角 roll, pitch, yaw
    //double roll = msg->pose.orientation.x;
    //double pitch = msg->pose.orientation.y;
    //double yaw = msg->pose.orientation.z;
    
    tf::Quaternion quat;
    tf::quaternionMsgToTF(msg->pose.orientation, quat);

    double roll, pitch, yaw;
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);
    
  //  KDL::Frame target_pose(
  //      KDL::Rotation::RPY(roll, pitch, yaw), // 使用欧拉角
   //     KDL::Vector(
   //         msg->pose.position.x,
   //         msg->pose.position.y,
   //         msg->pose.position.z));
   
   // 构造目标姿态（世界坐标系下）
KDL::Frame target_world(
    KDL::Rotation::RPY(roll, pitch, yaw),
    KDL::Vector(msg->pose.position.x, msg->pose.position.y, msg->pose.position.z));

// ArmL01_Link 相对 base_link 的姿态补偿（取逆变换）
KDL::Frame base_to_ArmL01(
    KDL::Rotation::RPY(1.57, 0, 3.14), // 注意取负号
    KDL::Vector(0, 0, 0)); // 假设只有姿态补偿，没有位置偏移（或者根据TF填充）

// 将目标从 base_link 系转换到 ArmL01_Link 系下
KDL::Frame target_pose = base_to_ArmL01 * target_world;





    KDL::JntArray q_init(kdl_chain_.getNrOfJoints());
    KDL::JntArray q_result(kdl_chain_.getNrOfJoints());

    for (unsigned int i = 0; i < kdl_chain_.getNrOfJoints(); ++i)
        q_init(i) = 0.0;

    int ret = ik_solver_->CartToJnt(q_init, target_pose, q_result);
    if (ret >= 0) {
        sensor_msgs::JointState joint_msg;
        joint_msg.header.stamp = ros::Time::now();

    // 你自己设定的关节名列表（确保顺序与KDL chain一致）
    std::vector<std::string> joint_names = {
        "ArmL02_Joint", "ArmL03_Joint", "ArmL04_Joint",
        "ArmL05_Joint", "ArmL06_Joint", "ArmL07_Joint",
        "ArmL08_Joint", "ArmL09_Joint"
    };


         for (unsigned int i = 0; i < kdl_chain_.getNrOfJoints(); ++i) {
          //  joint_msg.name.push_back("ArmL0" + std::to_string(i + 2) + "_Joint");
           joint_msg.name.push_back(joint_names[i]);
           joint_msg.position.push_back(q_result(i));

         }

        joint_pub_.publish(joint_msg);
    } else {
        ROS_WARN("IK solver failed to find a solution.");
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
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "ik_solver_node");
    ros::NodeHandle nh("~");

    IKSolverNode solver(nh);
    ros::spin();
    return 0;
}


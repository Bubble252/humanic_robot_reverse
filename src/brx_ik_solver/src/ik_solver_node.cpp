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
        KDL::Frame target_pose(
            KDL::Rotation::Quaternion(
                msg->pose.orientation.x,
                msg->pose.orientation.y,
                msg->pose.orientation.z,
                msg->pose.orientation.w),
            KDL::Vector(
                msg->pose.position.x,
                msg->pose.position.y,
                msg->pose.position.z));

        KDL::JntArray q_init(kdl_chain_.getNrOfJoints());
        KDL::JntArray q_result(kdl_chain_.getNrOfJoints());

        for (unsigned int i = 0; i < kdl_chain_.getNrOfJoints(); ++i)
            q_init(i) = 0.0;

        int ret = ik_solver_->CartToJnt(q_init, target_pose, q_result);
        if (ret >= 0) {
            sensor_msgs::JointState joint_msg;
            joint_msg.header.stamp = ros::Time::now();

            for (unsigned int i = 0; i < kdl_chain_.getNrOfJoints(); ++i) {
                joint_msg.name.push_back("ArmL0" + std::to_string(i + 2) + "_Joint");  // 名字需与 URDF 一致
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


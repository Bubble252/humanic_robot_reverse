#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <map>

class JointStateMerger {
public:
    JointStateMerger() {
        sub_ik_ = nh_.subscribe("/ik_joint_states", 1, &JointStateMerger::ikCallback, this);
        sub_gui_ = nh_.subscribe("/joint_states_gui", 1, &JointStateMerger::guiCallback, this);
        pub_ = nh_.advertise<sensor_msgs::JointState>("/joint_states", 1);
    }

private:
    sensor_msgs::JointState latest_ik_;
    sensor_msgs::JointState latest_gui_;
    ros::Time last_ik_time_, last_gui_time_;

    void ikCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        latest_ik_ = *msg;
        last_ik_time_ = ros::Time::now();
        publishMerged();
    }

    void guiCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        latest_gui_ = *msg;
        last_gui_time_ = ros::Time::now();
        publishMerged();
    }

    void publishMerged() {
        std::map<std::string, double> joint_map;

        for (size_t i = 0; i < latest_gui_.name.size(); ++i)
            joint_map[latest_gui_.name[i]] = latest_gui_.position[i];

        for (size_t i = 0; i < latest_ik_.name.size(); ++i)
            joint_map[latest_ik_.name[i]] = latest_ik_.position[i];

        sensor_msgs::JointState merged;
        merged.header.stamp = ros::Time::now();

        for (const auto& kv : joint_map) {
            merged.name.push_back(kv.first);
            merged.position.push_back(kv.second);
        }

        pub_.publish(merged);
    }

    ros::NodeHandle nh_;
    ros::Subscriber sub_ik_, sub_gui_;
    ros::Publisher pub_;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "joint_state_merger_node");
    JointStateMerger merger;
    ros::spin();
    return 0;
}


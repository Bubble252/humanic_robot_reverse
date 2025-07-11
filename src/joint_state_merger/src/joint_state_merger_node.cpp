#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <map>

class JointStateMerger {
public:
    JointStateMerger() {
        sub_gui_ = nh_.subscribe("/joint_states_gui", 1, &JointStateMerger::guiCallback, this);
        sub_left_ = nh_.subscribe("/left_ik_joint_states", 1, &JointStateMerger::leftCallback, this);
        sub_right_ = nh_.subscribe("/right_ik_joint_states", 1, &JointStateMerger::rightCallback, this);
        pub_ = nh_.advertise<sensor_msgs::JointState>("/joint_states", 1);
    }

private:
    ros::NodeHandle nh_;
    ros::Subscriber sub_gui_, sub_left_, sub_right_;
    ros::Publisher pub_;

    sensor_msgs::JointState latest_gui_, latest_left_, latest_right_;
    ros::Time last_gui_time_, last_left_time_, last_right_time_;

    void guiCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        latest_gui_ = *msg;
        last_gui_time_ = ros::Time::now();
        publishMerged();
    }

    void leftCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        latest_left_ = *msg;
        last_left_time_ = ros::Time::now();
        publishMerged();
    }

    void rightCallback(const sensor_msgs::JointState::ConstPtr& msg) {
        latest_right_ = *msg;
        last_right_time_ = ros::Time::now();
        publishMerged();
    }

    void publishMerged() {
        std::map<std::string, double> joint_map;

        // 优先级顺序：GUI → Left → Right
// 先写GUI（最低优先级）
for (size_t i = 0; i < latest_gui_.name.size(); ++i)
    joint_map[latest_gui_.name[i]] = latest_gui_.position[i];

// 再写Left，覆盖GUI相同关节
for (size_t i = 0; i < latest_left_.name.size(); ++i)
    joint_map[latest_left_.name[i]] = latest_left_.position[i];

// 再写Right，覆盖GUI和Left相同关节
for (size_t i = 0; i < latest_right_.name.size(); ++i)
    joint_map[latest_right_.name[i]] = latest_right_.position[i];

        sensor_msgs::JointState merged;
        merged.header.stamp = ros::Time::now();

        for (const auto& kv : joint_map) {
            merged.name.push_back(kv.first);
            merged.position.push_back(kv.second);
        }

        pub_.publish(merged);
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "joint_state_merger_node");
    JointStateMerger merger;
    ros::spin();
    return 0;
}


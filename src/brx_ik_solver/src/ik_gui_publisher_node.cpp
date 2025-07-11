#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Quaternion.h>

#include "ui_ik_gui.h"

class IKGuiNode : public QWidget {
    Q_OBJECT
public:
    IKGuiNode(ros::NodeHandle& nh, QWidget* parent = nullptr);
private slots:
    void sendLeftPose();
    void sendRightPose();
private:
    ros::NodeHandle nh_;
    ros::Publisher arm1_pub_;
    ros::Publisher arm2_pub_;
    Ui::IKGui ui_;
};

IKGuiNode::IKGuiNode(ros::NodeHandle& nh, QWidget* parent)
    : QWidget(parent), nh_(nh)
{
    ui_.setupUi(this);

    arm1_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/target_pose_left", 1);
    arm2_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/target_pose_right", 1);

    connect(ui_.sendButton_left, &QPushButton::clicked, this, &IKGuiNode::sendLeftPose);
    connect(ui_.sendButton_right, &QPushButton::clicked, this, &IKGuiNode::sendRightPose);
}

void IKGuiNode::sendLeftPose() {
    geometry_msgs::PoseStamped pose;
    pose.header.stamp = ros::Time::now();
    pose.header.frame_id = "ArmL01_Link";  // 可根据 TF 设置

    pose.pose.position.x = ui_.xSpinBox1->value();
    pose.pose.position.y = ui_.ySpinBox1->value();
    pose.pose.position.z = ui_.zSpinBox1->value();

    tf2::Quaternion q;
    q.setRPY(ui_.rollSpinBox1->value(), ui_.pitchSpinBox1->value(), ui_.yawSpinBox1->value());
    pose.pose.orientation.x = q.x();
    pose.pose.orientation.y = q.y();
    pose.pose.orientation.z = q.z();
    pose.pose.orientation.w = q.w();

    arm1_pub_.publish(pose);
}

void IKGuiNode::sendRightPose() {
    geometry_msgs::PoseStamped pose;
    pose.header.stamp = ros::Time::now();
    pose.header.frame_id = "ArmR01_Link";

    pose.pose.position.x = ui_.xSpinBox2->value();
    pose.pose.position.y = ui_.ySpinBox2->value();
    pose.pose.position.z = ui_.zSpinBox2->value();

    tf2::Quaternion q;
    q.setRPY(ui_.rollSpinBox2->value(), ui_.pitchSpinBox2->value(), ui_.yawSpinBox2->value());
    pose.pose.orientation.x = q.x();
    pose.pose.orientation.y = q.y();
    pose.pose.orientation.z = q.z();
    pose.pose.orientation.w = q.w();

    arm2_pub_.publish(pose);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "ik_gui_node");
    ros::NodeHandle nh;

    QApplication app(argc, argv);
    IKGuiNode gui(nh);
    gui.show();

    QTimer ros_timer;
    QObject::connect(&ros_timer, &QTimer::timeout, [] { ros::spinOnce(); });
    ros_timer.start(10);

    return app.exec();
}

#include "ik_gui_publisher_node.moc"


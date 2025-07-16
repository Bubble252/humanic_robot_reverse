#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <brx_ik_solver/IkControlInput.h>  // 自定义消息

#include "ui_ik_gui.h"

class IKGuiNode : public QWidget {
    Q_OBJECT
public:
    IKGuiNode(ros::NodeHandle& nh, QWidget* parent = nullptr);

private slots:
    void sendLeftPose();
    void sendRightPose();

private:
    void updateJointUI(const sensor_msgs::JointState::ConstPtr& msg, int offset);
    void leftJointCallback(const sensor_msgs::JointState::ConstPtr& msg);
    void rightJointCallback(const sensor_msgs::JointState::ConstPtr& msg);

    ros::NodeHandle nh_;
    ros::Publisher arm1_pub_;
    ros::Publisher arm2_pub_;
    ros::Subscriber left_joint_sub_;
    ros::Subscriber right_joint_sub_;

    Ui::IKGui ui_;
};

IKGuiNode::IKGuiNode(ros::NodeHandle& nh, QWidget* parent)
    : QWidget(parent), nh_(nh)
{
    ui_.setupUi(this);

    arm1_pub_ = nh_.advertise<brx_ik_solver::IkControlInput>("/left_ik_control_input", 1);
    arm2_pub_ = nh_.advertise<brx_ik_solver::IkControlInput>("/right_ik_control_input", 1);

    // 用成员函数代替 lambda 作为回调
    left_joint_sub_ = nh_.subscribe("/left_ik_joint_states", 1, &IKGuiNode::leftJointCallback, this);
    right_joint_sub_ = nh_.subscribe("/right_ik_joint_states", 1, &IKGuiNode::rightJointCallback, this);

    connect(ui_.sendButton_left, &QPushButton::clicked, this, &IKGuiNode::sendLeftPose);
    connect(ui_.sendButton_right, &QPushButton::clicked, this, &IKGuiNode::sendRightPose);
}

void IKGuiNode::updateJointUI(const sensor_msgs::JointState::ConstPtr& msg, int offset) {
    for (int i = 0; i < msg->position.size() && i + offset < 14; ++i) {
        QString name = QString("jointSpinBox_%1").arg(i + offset + 1);
        QDoubleSpinBox* box = findChild<QDoubleSpinBox*>(name);
        QString lockName = QString("jointLock_%1").arg(i + offset + 1);
        QCheckBox* lock = findChild<QCheckBox*>(lockName);

        if (box && lock && !lock->isChecked()) {
            box->blockSignals(true);
            box->setValue(msg->position[i]);
            box->blockSignals(false);
        }
    }
}

void IKGuiNode::leftJointCallback(const sensor_msgs::JointState::ConstPtr& msg) {
    updateJointUI(msg, 0);
}

void IKGuiNode::rightJointCallback(const sensor_msgs::JointState::ConstPtr& msg) {
    updateJointUI(msg, 7);
}

void IKGuiNode::sendLeftPose() {
    brx_ik_solver::IkControlInput msg;
    msg.header.stamp = ros::Time::now();
    msg.pose.position.x = ui_.xSpinBox1->value();
    msg.pose.position.y = ui_.ySpinBox1->value();
    msg.pose.position.z = ui_.zSpinBox1->value();
    msg.header.frame_id ="ArmL01_Link";

    tf2::Quaternion q;
    q.setRPY(ui_.rollSpinBox1->value(), ui_.pitchSpinBox1->value(), ui_.yawSpinBox1->value());
    msg.pose.orientation.x = q.x();
    msg.pose.orientation.y = q.y();
    msg.pose.orientation.z = q.z();
    msg.pose.orientation.w = q.w();

    msg.solve_type = ui_.solveTypeCombo->currentText().toStdString();
    msg.lock_joint.resize(7);
    msg.lock_values.resize(7);

    for (int i = 0; i < 7; ++i) {
        auto spin = findChild<QDoubleSpinBox*>(QString("jointSpinBox_%1").arg(i + 1));
        auto check = findChild<QCheckBox*>(QString("jointLock_%1").arg(i + 1));
        msg.lock_joint[i] = check->isChecked();
        msg.lock_values[i] = spin->value();
    }

    arm1_pub_.publish(msg);
}

void IKGuiNode::sendRightPose() {
    brx_ik_solver::IkControlInput msg;
    msg.header.stamp = ros::Time::now();
    msg.pose.position.x = ui_.xSpinBox2->value();
    msg.pose.position.y = ui_.ySpinBox2->value();
    msg.pose.position.z = ui_.zSpinBox2->value();
    msg.header.frame_id ="ArmR01_Link";

    tf2::Quaternion q;
    q.setRPY(ui_.rollSpinBox2->value(), ui_.pitchSpinBox2->value(), ui_.yawSpinBox2->value());
    msg.pose.orientation.x = q.x();
    msg.pose.orientation.y = q.y();
    msg.pose.orientation.z = q.z();
    msg.pose.orientation.w = q.w();

    msg.solve_type = ui_.solveTypeCombo->currentText().toStdString();
    msg.lock_joint.resize(7);
    msg.lock_values.resize(7);

    for (int i = 0; i < 7; ++i) {
        auto spin = findChild<QDoubleSpinBox*>(QString("jointSpinBox_%1").arg(i + 8));
        auto check = findChild<QCheckBox*>(QString("jointLock_%1").arg(i + 8));
        msg.lock_joint[i] = check->isChecked();
        msg.lock_values[i] = spin->value();
    }

    arm2_pub_.publish(msg);
}

int main(int argc, char** argv) {
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

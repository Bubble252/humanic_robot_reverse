// ik_gui_publisher_node.cpp
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDoubleSpinBox>
#include <QPushButton>

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Quaternion.h>

class IKGuiNode : public QWidget {
    Q_OBJECT
public:
    IKGuiNode(ros::NodeHandle& nh, QWidget *parent = nullptr) : QWidget(parent), nh_(nh) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        xSpinBox = new QDoubleSpinBox(this); xSpinBox->setRange(-1.0, 1.0); layout->addWidget(xSpinBox);
        ySpinBox = new QDoubleSpinBox(this); ySpinBox->setRange(-1.0, 1.0); layout->addWidget(ySpinBox);
        zSpinBox = new QDoubleSpinBox(this); zSpinBox->setRange(-1.0, 1.0); layout->addWidget(zSpinBox);
        rollSpinBox = new QDoubleSpinBox(this); rollSpinBox->setRange(-3.14, 3.14); layout->addWidget(rollSpinBox);
        pitchSpinBox = new QDoubleSpinBox(this); pitchSpinBox->setRange(-3.14, 3.14); layout->addWidget(pitchSpinBox);
        yawSpinBox = new QDoubleSpinBox(this); yawSpinBox->setRange(-3.14, 3.14); layout->addWidget(yawSpinBox);
        QPushButton *sendButton = new QPushButton("发送目标姿态", this); layout->addWidget(sendButton);
        connect(sendButton, &QPushButton::clicked, this, &IKGuiNode::sendPose);

        pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/target_pose", 1);
    }

private slots:
    void sendPose() {
        geometry_msgs::PoseStamped msg;
        msg.header.stamp = ros::Time::now();
        msg.header.frame_id = "ArmL01_Link";
        msg.pose.position.x = xSpinBox->value();
        msg.pose.position.y = ySpinBox->value();
        msg.pose.position.z = zSpinBox->value();
        // 欧拉角转四元数
        double roll = rollSpinBox->value();
        double pitch = pitchSpinBox->value();
        double yaw = yawSpinBox->value();
        tf2::Quaternion q;
        q.setRPY(roll, pitch, yaw);
        msg.pose.orientation.x = q.x();
        msg.pose.orientation.y = q.y();
        msg.pose.orientation.z = q.z();
        msg.pose.orientation.w = q.w();

        pose_pub_.publish(msg);
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher pose_pub_;
    QDoubleSpinBox *xSpinBox, *ySpinBox, *zSpinBox;
    QDoubleSpinBox *rollSpinBox, *pitchSpinBox, *yawSpinBox;
};

#include "ik_gui_publisher_node.moc"  // MOC 支持

int main(int argc, char **argv) {
    ros::init(argc, argv, "ik_gui_publisher_node");
    ros::NodeHandle nh;
    QApplication app(argc, argv);
    IKGuiNode gui(nh);
    gui.show();
    return app.exec();
}


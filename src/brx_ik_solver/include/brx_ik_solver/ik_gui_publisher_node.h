#ifndef IK_GUI_PUBLISHER_NODE_H
#define IK_GUI_PUBLISHER_NODE_H

#include <QWidget>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

namespace Ui {
    class IKGui;
}

class IKGuiNode : public QWidget {
    Q_OBJECT

public:
    IKGuiNode(QWidget *parent = nullptr);
    ~IKGuiNode();

private slots:
    void sendTargetPose();

private:
    Ui::IKGui *ui;
    ros::Publisher pose_pub_;
    ros::NodeHandle nh_;
};

#endif // IK_GUI_PUBLISHER_NODE_H


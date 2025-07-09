# humanic_robot_reverse
运行方法见下方链接# source到底是啥

source devel/setup.bash

这条命令的主要功能是将 ROS Noetic 环境的配置加载到当前的终端会话中。在 ROS 里，不同的发行版（如 Noetic、Melodic 等）都有各自独立的环境变量和路径配置，**只有加载了这些配置，你才能在终端中使用 ROS 的各种工具和命令。**

总结一下运行流程

首先运行roscore

```jsx
ubuntu@ubuntu-virtual-machine:~/桌面$ docker exec -it kdl_env bash
root@ubuntu-virtual-machine:/# source /opt/ros/noetic/setup.bash
root@ubuntu-virtual-machine:/# roscore
... logging to /root/.ros/log/5d19e750-5c71-11f0-a7af-000c297dc33e/roslaunch-ubuntu-virtual-machine-144.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://ubuntu-virtual-machine:39787/
ros_comm version 1.17.4

SUMMARY
========

PARAMETERS
 * /rosdistro: noetic
 * /rosversion: 1.17.4

NODES

auto-starting new master
process[master]: started with pid [152]
ROS_MASTER_URI=http://ubuntu-virtual-machine:11311/

setting /run_id to 5d19e750-5c71-11f0-a7af-000c297dc33e
process[rosout-1]: started with pid [162]
started core service [/rosout]

```

然后运行节点IK

```jsx
root@ubuntu-virtual-machine:~/arm/BRX042501# cd /root/arm/reverse_ws
root@ubuntu-virtual-machine:~/arm/reverse_ws# source devel/setup.bash
root@ubuntu-virtual-machine:~/arm/reverse_ws# rosrun brx_ik_solver ik_solver_node
[WARN] [1752030751.929161602]: The root link base_link has an inertia specified in the URDF, but KDL does not support a root link with an inertia.  As a workaround, you can add an extra dummy link to your URDF.
[INFO] [1752030751.934182897]: IK Solver Node initialized.

```

然后再发布解算消息

```jsx
^Croot@ubuntu-virtual-machine:~/arm/reverse_ws# rostopic pub /target_pose geometry_msgs/PoseStamped -r 10 "header:
>   stamp: {secs: 0, nsecs: 0}
>   frame_id: 'ArmL01_Link'
> pose:
>   position:
>     x: 0.2
>     y: 0.1
>     z: 0.3
>   orientation:
>     x: 0.0
>     y: 0.0
>     z: 0.0
>     w: 1.0"

```

然后再监听

```jsx
rostopic echo /joint_states

```

下面是GPT的回答

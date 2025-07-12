
用dockerfile构建docker环境 安装ros-noetic
实现映射
```
docker build -t kdl_env:latest .

xhost +local:docker

docker run -it --rm \
  --net=host \
  -e DISPLAY=$DISPLAY \
  -e QT_X11_NO_MITSHM=1 \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v $HOME/桌面/arm:/root/arm \
  --name ros_noetic \
  osrf/ros:noetic-desktop-full
```

source devel/setup.bash
将 ROS Noetic 环境的配置加载到当前的终端会话中



首先开启docker容器 并启动roscore
```
docker start -ai kdl_env
source /opt/ros/noetic/setup.bash
roscore
... 

```
新开一个终端 转到工作目录 并运行launch文件
```
docker exec -it kdl_env bash
cd /root/arm/reverse_ws
source devel/setup.bash
roslaunch reverse_bringup all_nodes.launch
```







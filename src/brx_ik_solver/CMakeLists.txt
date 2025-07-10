cmake_minimum_required(VERSION 3.0.2)
project(brx_ik_solver)

## 查找 ROS 和 Qt5 所需组件
find_package(catkin REQUIRED COMPONENTS
  roscpp
  urdf
  kdl_parser
  geometry_msgs
  sensor_msgs
  tf
)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

## 启用 Qt 的自动 MOC 支持
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)  # 如果你以后用 .ui 文件会用到
set(CMAKE_AUTORCC ON)  # 若使用 .qrc 资源文件也需要
set(CMAKE_INCLUDE_CURRENT_DIR ON)  # 为 MOC/UIC 提供当前路径

## 声明 catkin 包
catkin_package()

## 包含头文件目录
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

## IK求解节点
add_executable(ik_solver_node src/ik_solver_node.cpp)
target_link_libraries(ik_solver_node ${catkin_LIBRARIES})

## GUI发布节点（包含 Q_OBJECT、信号槽）
add_executable(ik_gui_publisher_node src/ik_gui_publisher_node.cpp)
target_link_libraries(ik_gui_publisher_node
  ${catkin_LIBRARIES}
  Qt5::Widgets
)


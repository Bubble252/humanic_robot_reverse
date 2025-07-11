cmake_minimum_required(VERSION 3.0.2)
project(brx_ik_solver)

## ROS & Qt
find_package(catkin REQUIRED COMPONENTS
  roscpp
  urdf
  kdl_parser
  geometry_msgs
  sensor_msgs
  tf
)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

## Qt MOC/UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

## catkin
catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

## IK Solver Node
add_executable(ik_solver_node src/ik_solver_node.cpp)
target_link_libraries(ik_solver_node ${catkin_LIBRARIES})

## IK GUI Node
add_executable(ik_gui_publisher_node
  src/ik_gui_publisher_node.cpp
  ui/ik_gui.ui
)

target_link_libraries(ik_gui_publisher_node
  ${catkin_LIBRARIES}
  Qt5::Widgets
)


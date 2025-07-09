cmake_minimum_required(VERSION 3.0.2)
project(joint_state_merger)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(joint_state_merger_node src/joint_state_merger_node.cpp)
target_link_libraries(joint_state_merger_node ${catkin_LIBRARIES})


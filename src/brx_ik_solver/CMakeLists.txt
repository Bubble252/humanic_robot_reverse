cmake_minimum_required(VERSION 3.0.2)
project(brx_ik_solver)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  urdf
  kdl_parser
  geometry_msgs
  sensor_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ik_solver_node src/ik_solver_node.cpp)
target_link_libraries(ik_solver_node ${catkin_LIBRARIES})


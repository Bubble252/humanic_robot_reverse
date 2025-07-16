cmake_minimum_required(VERSION 3.0.2)
project(brx_ik_solver)

## -------------------
## 依赖设置
## -------------------

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  geometry_msgs
  urdf
  tf
  message_generation
  kdl_parser
)

# 设置trac_ik_lib路径，确保CMake能找到包
set(trac_ik_lib_DIR "/opt/ros/noetic/share/trac_ik_lib/cmake")
find_package(trac_ik_lib REQUIRED)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

## Qt MOC/UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

## -------------------
## 消息声明
## -------------------

add_message_files(
  FILES
  IkControlInput.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

## -------------------
## catkin 包配置
## -------------------

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs geometry_msgs urdf tf kdl_parser trac_ik_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${trac_ik_lib_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

## -------------------
## 可执行文件
## -------------------

add_executable(ik_solver_node src/ik_solver_node.cpp)
add_dependencies(ik_solver_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ik_solver_node
  ${catkin_LIBRARIES}
  ${trac_ik_lib_LIBRARIES}
)

add_executable(ik_gui_publisher_node
  src/ik_gui_publisher_node.cpp
  ui/ik_gui.ui
)
add_dependencies(ik_gui_publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ik_gui_publisher_node
  ${catkin_LIBRARIES}
  Qt5::Widgets
)


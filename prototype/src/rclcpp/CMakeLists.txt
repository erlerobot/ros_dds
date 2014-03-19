cmake_minimum_required(VERSION 2.8.3)
project(rclcpp)

find_package(opensplice REQUIRED)
find_package(catkin REQUIRED)

ospl_add_idl(idl/ROSMsg.idl)

include_directories(include ${OPENSPLICE_INCLUDE_DIRS})
link_directories(${OPENSPLICE_LIBRARY_DIRS})

add_library(rclcpp src/rclcpp/rclcpp.cpp src/rclcpp/node/node.cpp)
target_link_libraries(rclcpp ${OPENSPLICE_LIBRARIES})

add_executable(example src/main.cpp)
target_link_libraries(example rclcpp ${OPENSPLICE_LIBRARIES})
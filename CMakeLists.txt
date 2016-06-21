cmake_minimum_required(VERSION 2.8.3)
project(rosintro)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  std_srvs
)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES rosintro
#  CATKIN_DEPENDS roscpp std_msgs std_srvs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tickle_service_server_node 
  src/tickle_service_server/main.cpp)

target_link_libraries(tickle_service_server_node
  ${catkin_LIBRARIES}
)

add_executable(tickle_service_client_node 
  src/tickle_service_client/main.cpp)

target_link_libraries(tickle_service_client_node
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

#############
## Testing ##
#############


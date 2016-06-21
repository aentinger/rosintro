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
#  CATKIN_DEPENDS roscpp geometry_msgs std_srvs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# point_publisher_node

add_executable(point_publisher_node 
  src/point_publisher/main.cpp)

target_link_libraries(point_publisher_node 
  ${catkin_LIBRARIES}
)

# point_subscriber_node

add_executable(point_subscriber_node 
  src/point_subscriber/main.cpp)

target_link_libraries(point_subscriber_node 
  ${catkin_LIBRARIES}
)

# tickle_service_server_node 

add_executable(tickle_service_server_node 
  src/tickle_service_server/main.cpp)

target_link_libraries(tickle_service_server_node
  ${catkin_LIBRARIES}
)

# tickle_service_client_node 

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


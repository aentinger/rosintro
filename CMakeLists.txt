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

## Declare a C++ executable
# add_executable(rosintro_node src/rosintro_node.cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(rosintro_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

#############
## Testing ##
#############


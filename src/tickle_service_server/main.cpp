/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <iostream>

#include <ros/ros.h>
#include <ros/console.h>

#include <std_srvs/Empty.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

bool tickleRequestReceived(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res); 

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tickle_service_server_node");
  
  ros::NodeHandle node_handle;

  ros::ServiceServer tickle_service_server = node_handle.advertiseService("/tickle", tickleRequestReceived);
  
  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

bool tickleRequestReceived(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
  ROS_INFO("Hihi");
}

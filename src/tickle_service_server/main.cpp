/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <ros/ros.h>
#include <ros/console.h>

#include <std_srvs/Trigger.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

bool tickleRequestReceived(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res); 

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tickle_service_server_node");
  
  ros::NodeHandle node_handle;

  ros::ServiceServer tickle_service_server = node_handle.advertiseService("/tickle", tickleRequestReceived);

  ros::spin();
  
  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

bool tickleRequestReceived(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res)
{
  res.success = true;
  res.message = "Hihi";

  ROS_INFO("Service server was just tickled");

  return res.success;
}

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <sstream>

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
  static size_t tickle_cnt = 0;

  ROS_INFO("Tickle service server was just tickled");

  tickle_cnt++;

  std::stringstream tickle_stream;
  for(size_t t = 0; t < tickle_cnt; t++)
  {
    tickle_stream << "Hi";
  }

  res.success = true;
  res.message = tickle_stream.str();

  return res.success;
}

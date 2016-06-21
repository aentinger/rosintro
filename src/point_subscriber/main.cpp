/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <sstream>

#include <ros/ros.h>
#include <ros/console.h>

#include <geometry_msgs/Point.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void pointMessageReceivedCallback(const geometry_msgs::Point::ConstPtr& msg);

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point_subsriber_node");
  
  ros::NodeHandle node_handle;

  ros::Subscriber point_subscriber = node_handle.subscribe("/point", 10, pointMessageReceivedCallback);

  ros::spin();
  
  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void pointMessageReceivedCallback(const geometry_msgs::Point::ConstPtr& msg)
{
  ROS_INFO("Point(X, Y, Z) = ( %f , %f, %f )", msg->x, msg->y, msg->z);
}

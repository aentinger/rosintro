/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <sstream>

#include <ros/ros.h>

#include <geometry_msgs/Point.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void handleExit        ();
void handleInvalidValue();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point_publisher_node");
  
  ros::NodeHandle node_handle;

  /* Create the publisher for publishing Point messages */

  ros::Publisher point_publisher = node_handle.advertise<geometry_msgs::Point>("/point", 10);

  /* Provide a crude menu for selecting which service one wants to invoke */

  char cmd = 0;

  do
  {
    std::cout << "Move" << std::endl;
    std::cout << "  [u]p" << std::endl;
    std::cout << "  [d]own" << std::endl;
    std::cout << "  [l]eft" << std::endl;
    std::cout << "  [r]righ" << std::endl;
    std::cout << "[q]uit" << std::endl;

    std::cout << ">>"; std::cin >> cmd;

    switch(cmd)
    {
    case 'q': handleExit                 ();                       break;
    default:  handleInvalidValue         ();                       break;
    }
  } while(cmd != 'q');

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void handleExit()
{
  std::cout << "Exiting point_publisher_node" << std::endl;
}

void handleInvalidValue()
{
  std::cout << "Invalid input value" << std::endl;
}


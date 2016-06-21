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

void handleUp             (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleDown           (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleLeft           (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleRight          (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleIncreaseHeight (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleDecreaseHeight (ros::Publisher &point_publisher, double &x, double &y, double &z);
void handleExit           ();
void handleInvalidValue   ();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point_publisher_node");
  
  ros::NodeHandle node_handle;

  /* Create the publisher for publishing Point messages */

  ros::Publisher point_publisher = node_handle.advertise<geometry_msgs::Point>("/point", 10);

  /* The coordinates of the current point */

  double x = 0.0,
         y = 0.0,
         z = 0.0;

  /* Provide a crude menu for selecting which service one wants to invoke */

  std::cout << "Move" << std::endl;
  std::cout << "  [u]p" << std::endl;
  std::cout << "  [d]own" << std::endl;
  std::cout << "  [l]eft" << std::endl;
  std::cout << "  [r]right" << std::endl;
  std::cout << "  [i]ncrease height" << std::endl;
  std::cout << " d[e]crease height" << std::endl;
  std::cout << "[q]uit" << std::endl;

  char cmd = 0;

  do
  {
    std::cout << ">>"; std::cin >> cmd;

    switch(cmd)
    {
    case 'u': handleUp              (point_publisher, x, y, z); break;
    case 'd': handleDown            (point_publisher, x, y, z); break;
    case 'l': handleLeft            (point_publisher, x, y, z); break;
    case 'r': handleRight           (point_publisher, x, y, z); break;
    case 'i': handleIncreaseHeight  (point_publisher, x, y, z); break;
    case 'e': handleDecreaseHeight  (point_publisher, x, y, z); break;
    case 'q': handleExit            ();                         break;
    default:  handleInvalidValue    ();                         break;
    }

    ros::spinOnce();

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

void handleUp(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  y++;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}

void handleDown(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  y--;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}

void handleLeft(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  x--;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}

void handleRight(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  x++;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}

void handleIncreaseHeight(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  z++;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}

void handleDecreaseHeight(ros::Publisher &point_publisher, double &x, double &y, double &z)
{
  z--;

  geometry_msgs::Point msg;

  msg.x = x;
  msg.y = y;
  msg.z = z;

  point_publisher.publish(msg);
}


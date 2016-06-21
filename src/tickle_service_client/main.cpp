/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <iostream>

#include <ros/ros.h>
#include <ros/console.h>

#include <std_srvs/Trigger.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void handleTickle      (ros::ServiceClient &tickle_service_client);
void handleExit        ();
void handleInvalidValue();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tickle_service_client_node");
  
  ros::NodeHandle node_handle;

  /* Create the service client for sending tickle service requests to the tickle service server */
  
  ros::ServiceClient tickle_service_client = node_handle.serviceClient<std_srvs::Trigger>("/tickle");

  /* Provide a crude menu for selecting which service one wants to invoke */

  char cmd = 0;

  do
  {
    std::cout << "[t]ickle the service server" << std::endl;
    std::cout << "[q]uit" << std::endl;

    std::cout << ">>"; std::cin >> cmd;

    switch(cmd)
    {
    case 't': handleTickle               (tickle_service_client);  break;
    case 'q': handleExit                 ();                       break;
    default:  handleInvalidValue         ();                       break;
    }
  } while(cmd != 'q');

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void handleTickle(ros::ServiceClient &tickle_service_client)
{
  std_srvs::Trigger srv;

  if(tickle_service_client.call(srv))
  {
    ROS_INFO("Tickle service server responds with '%s'", srv.response.message.c_str());
  }
  else
  {
    ROS_ERROR("Could not reach tickle service server");
  }
}

void handleExit()
{
  std::cout << "Exiting tickle_service_client_node" << std::endl;
}

void handleInvalidValue()
{
  std::cout << "Invalid input value" << std::endl;
}


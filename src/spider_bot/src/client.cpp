#include "ros/ros.h"
#include "spider_bot/move.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client");
  if (argc != 2)
  {
    ROS_INFO("usage: move robot in DIRECTION");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<spider_bot::move>("move");
  spider_bot::move srv;
  srv.request.direction = atoll(argv[1]);
  if (not client.call(srv))
  {
    ROS_ERROR("Failed to call service move");
    return 1;
  }

  return 0;
}

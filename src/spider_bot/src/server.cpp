#include "ros/ros.h"
#include "spider_bot/move.h"
#include <geometry_msgs/Twist.h>
#include <sstream>

int direction = 0;
int count = 0;

bool move(spider_bot::move::Request  &req,
         spider_bot::move::Response &res)
{
  res.success = true;
  direction = req.direction;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("move", move);
  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ROS_INFO("Ready to move robot.");
  ros::Rate rate(10);

  while(ros::ok()){
     geometry_msgs::Twist msg;
     switch (direction){
       case 1:
         msg.linear.x = 3;
         count ++;
         if (count > 40){
           direction = 0;
           count = 0;
         }
         break;
       case 2:
         msg.angular.z = 3.1;
         count ++;
         if (count > 40){
           direction = 0;
           count = 0;
         }
         break;
       case 3:
         msg.angular.z = -3.1;
         count ++;
         if (count > 40){
           direction = 0;
           count = 0;
         }
         break;
       default:
         break;
     }
     cmd_vel_pub.publish(msg);

     rate.sleep();
     ros::spinOnce(); 
  } 

  return 0;
}

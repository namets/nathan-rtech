#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"
#include <sstream>

int main(int argc, char **argv)
{
ros::init(argc, argv, "range_publisher");

ros::NodeHandle n;

ros::Publisher range_publisher= n.advertise<sensor_msgs::Range>("fake_range",1000);	
ros::Rate loop_rate(10);	//Loop rate
	

int count =0;
while(ros::ok())
{
// Make relevant objects and declare ranges
	sensor_msgs::Range sensor;
	std_msgs::Header header;
	header.frame_id="range_test";
	sensor.min_range=0.02;		// In meters
	sensor.max_range=4;		// In meters
	sensor.field_of_view=0.785398; // In radians

//Assign message 
	sensor.header=header;
	sensor.range = ((float)rand()/RAND_MAX)*4; 

	ROS_INFO("%f",sensor.range);

	range_publisher.publish(sensor);

	ros::spinOnce();

	loop_rate.sleep();
	++count;

}

return 0;
}

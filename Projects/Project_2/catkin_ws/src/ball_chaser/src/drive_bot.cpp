#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// geometry_msgs::Twist
geometry_msgs::Twist motor_command;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
                            ball_chaser::DriveToTarget::Response& res)
{
  
  // Set wheel velocities, to desired targets
  motor_command.linear.x = req.linear_x; // both of them are float64
  motor_command.angular.z = req.angular_z; // both of them are float64
  
  // Publish angles to drive the robot
  motor_command_publisher.publish(motor_command);

  // Message feedback
  res.msg_feedback = "Linear velocity target: linear_x = " + std::to_string(motor_command.linear.x) + ", Angular velocity target = " + std::to_string(motor_command.angular.z);
  ROS_INFO_STREAM(res.msg_feedback);
  
  return true;

}

// main loop
int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);

    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}
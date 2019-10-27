#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// Define service to drive the robot
ball_chaser::DriveToTarget srv;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float linear_x, float angular_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    srv.request.linear_x = linear_x;
    srv.request.angular_z = angular_z;

    // Call the drive_bot service and pass the requested velocities
    if (!client.call(srv)) {
    ROS_ERROR("Failed to call service drive_bot!");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    // look for ball
    int ball_position = -1; 
    for (int i = 0; i < img.height * img.step; i++) {
    if ((img.data[i] == white_pixel) and (img.data[i+1] == white_pixel) and (img.data[i+2] == white_pixel)) {
      ball_position = i % img.step; // expessed in ratio (0.5 is centre)
      break;
    } 
    }

    // control linear and angular velocities based on ball position
    float linear_x = 0.0, angular_z = 0.0;
    if (ball_position <= img.step * 0.3 && ball_position >= 0) 
    { // turn left
    angular_z = 0.5;
    } 
    else if (ball_position > img.step * 0.7  && ball_position <= img.step) 
    { // turn right
    angular_z = -0.5;
    } 
    else if (ball_position != -1) 
    { // move forward
    linear_x = 0.5;
    }
    else if (ball_position == -1) 
    { // look around to find the ball - CAN BE FURTHER IMPROVED IN FUTURE
    angular_z = 0.5;
    }
             
    // send request to drive_robot service
    drive_robot(linear_x, angular_z); 


    // Publish some info
  if (ball_position != -1) { 
    ROS_INFO_STREAM("Target detected: driving the bot to the target ...");
  } else {
    ROS_INFO_STREAM("Target missing: Stop the bot for now.");
  }

}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
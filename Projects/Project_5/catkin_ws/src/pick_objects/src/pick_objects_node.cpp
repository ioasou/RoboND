#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <string>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal setGoal(double x, double y, double z, double w) {
	
	move_base_msgs::MoveBaseGoal goal;

	// set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;

  goal.target_pose.pose.orientation.w = w;
  goal.target_pose.pose.orientation.z = z;

	return goal;
}


int main(int argc, char** argv){

  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach (pick up)
  goal.target_pose.pose.position.x = 3.53;
  goal.target_pose.pose.position.y = 3.10;
  goal.target_pose.pose.orientation.w = 0.68;
  goal.target_pose.pose.orientation.z = 0.74;
  ROS_INFO("Sending pickup goal");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("%s", "Hooray, at pickup point");
  }
  else
    ROS_INFO("%s", "Oops, PROBLEM :-)");

  // Sleep for 5 seconds
	ROS_INFO("Picking up...");
	ros::Duration(5.0).sleep();

  // Define a position and orientation for the robot to reach (drop off)
  goal.target_pose.pose.position.x = -1.00;
  goal.target_pose.pose.position.y = 0.00;
  goal.target_pose.pose.orientation.w = -0.99;
  goal.target_pose.pose.orientation.z = 0.03;
  ROS_INFO("Sending dropoff goal");
  ac.sendGoal(goal);
  ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("%s", "Hooray, at dropoff point");
  }
  else
    ROS_INFO("%s", "Oops, PROBLEM :-)");
	ros::Duration(5.0).sleep();

  return 0;
}
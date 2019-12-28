#!/bin/sh

# setup gazebo world
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/user/workspace/RoboND/Projects/Project_5/catkin_ws/src/World/project_1_ball.world

# start gazebo world
roslaunch turtlebot_gazebo turtlebot_world.launch & /

sleep 5 && roslaunch turtlebot_gazebo gmapping_demo.launch

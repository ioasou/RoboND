#!/bin/bash

# setup gazebo world
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/user/workspace/RoboND/Projects/Project_5/catkin_ws/src/World/simple_u.world

# start gazebo world
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" & 

# start gmapping
sleep 5 && xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" & 

# start visualisations (rviz)
sleep 5 && xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" & 

# start teleoperation
sleep 5 && xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"

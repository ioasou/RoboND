#!/bin/bash

# setup gazebo world
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/user/workspace/RoboND/Projects/Project_5/catkin_ws/src/map/simple_u.world

# start gazebo world
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" & 

# start gmapping
sleep 5 && xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/user/workspace/RoboND/Projects/Project_5/catkin_ws/src/map/simple_u.yaml" & 

# start manual navigation
sleep 5 && xterm -e "roslaunch turtlebot_rviz_launchers view_navigation_home_service.launch" &

# start pick objects node
sleep 10 && xterm -e "rosrun pick_objects pick_objects_node" &

# start add markers node
sleep 10 && xterm -e "rosrun add_markers add_markers_node" 
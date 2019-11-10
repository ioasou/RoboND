#!/bin/bash
xhost +
docker exec -it ros-kinetic-gazebo-container $SHELL

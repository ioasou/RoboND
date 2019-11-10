#!/bin/bash
xhost +
docker run -it --rm\
    --net=host \
    --env="DISPLAY" \
    --env=TERM="xterm-color"\
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --volume="$HOME:/home/user:rw"\
    --workdir="/home/user/workspace/RoboND"\
    --name="ros-kinetic-gazebo-container"\
    --privileged=True \
    ros-kinetic-gazebo $SHELL

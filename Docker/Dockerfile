FROM ros:kinetic-ros-base

# install additional ros packages
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-gazebo-* ros-kinetic-rviz ros-kinetic-xacro ros-kinetic-navigation ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-amcl\
  && rm -rf /var/lib/apt/lists/*

# install matplotlib for c++
RUN apt-get update && apt-get install --no-install-recommends -y \
    python-matplotlib python-numpy python2.7-dev \
  && rm -rf /var/lib/apt/lists/*

 # install additional ros packages
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-robot-state-publisher ros-kinetic-joint-state-publisher \
  && rm -rf /var/lib/apt/lists/*

# install protobuf
RUN apt-get update && apt-get install --no-install-recommends -y \
    libignition-math2-dev protobuf-compiler \
  && rm -rf /var/lib/apt/lists/*

# install rtabmap-ros
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-rtabmap-ros \
  && rm -rf /var/lib/apt/lists/*

# install gmapping
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-gmapping \
  && rm -rf /var/lib/apt/lists/*

# fix realsense issues
COPY fix_librealsense.sh /
RUN chmod +x /fix_librealsense.sh && /fix_librealsense.sh

# install turtlebot packages
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-turtlebot* \
  && rm -rf /var/lib/apt/lists/*

# install xterm
RUN apt-get update && apt-get install --no-install-recommends -y \
    xterm \
  && rm -rf /var/lib/apt/lists/*

# install actionlib
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-actionlib* \
  && rm -rf /var/lib/apt/lists/*

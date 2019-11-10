FROM ros:kinetic-ros-base

# install bootstrap tools
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-gazebo-* \
  && rm -rf /var/lib/apt/lists/*

# install rviz
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-rviz \
  && rm -rf /var/lib/apt/lists/*

# install xacro
RUN apt-get update && apt-get install --no-install-recommends -y \
    ros-kinetic-xacro \
  && rm -rf /var/lib/apt/lists/*

# final update
RUN apt-get update
# RoboND-Project 5
The purpose of this project is to build a home service virtual robot in [Gazebo](http://gazebosim.org/), using [TurtleBot](https://www.turtlebot.com/) and ROS functionalities such as [gmapping](http://wiki.ros.org/gmapping) for mapping, [amcl](http://wiki.ros.org/amcl) for localisation, and [move_base](http://wiki.ros.org/move_base?distro=melodic) for navigation.

![home_service_demo](https://github.com/ioasou/RoboND/blob/master/Projects/Project_5/results/home_service_demo.gif)

### Directory Structure
```
├── catkin_ws
│   └── src
│       ├── add_markers
│       │   ├── CMakeLists.txt
│       │   ├── include
│       │   ├── package.xml
│       │   └── src
│       ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
│       ├── map
│       │   ├── simple_u.pgm
│       │   ├── simple_u.world
│       │   └── simple_u.yaml
│       ├── pick_objects
│       │   ├── CMakeLists.txt
│       │   ├── include
│       │   ├── package.xml
│       │   └── src
│       ├── rvizConfig
│       │   └── home_service.rviz
│       ├── scripts
│       │   ├── add_markers.sh
│       │   ├── home_service.sh
│       │   ├── pick_objects.sh
│       │   ├── test_navigation.sh
│       │   └── test_slam.sh
│       ├── slam_gmapping
│       │   ├── gmapping
│       │   └── slam_gmapping
│       ├── turtlebot
│       │   ├── LICENSE
│       │   ├── README.md
│       │   ├── setup_create.sh
│       │   ├── setup_kobuki.sh
│       │   ├── turtlebot
│       │   ├── turtlebot_bringup
│       │   ├── turtlebot_capabilities
│       │   ├── turtlebot_capabilities.rosinstall
│       │   ├── turtlebot_description
│       │   ├── turtlebot.rosinstall
│       │   └── turtlebot_teleop
│       ├── turtlebot_interactions
│       │   ├── README.md
│       │   ├── turtlebot_dashboard
│       │   ├── turtlebot_interactions
│       │   ├── turtlebot_interactive_markers
│       │   └── turtlebot_rviz_launchers
│       └── turtlebot_simulator
│           ├── README.md
│           ├── turtlebot_gazebo
│           ├── turtlebot_simulator
│           ├── turtlebot_simulator.rosinstall
│           ├── turtlebot_stage
│           └── turtlebot_stdr
├── README.md
└── results
    └── home_service_demo.gif
```

### Steps to launch

#### Step 1 Compile the code
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_5/catkin_ws
source /opt/ros/kinetic/setup.bash
$ catkin_make
```

#### Step 2 Run Home Service functionality
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_5/catkin_ws
$ source devel/setup.bash
$ ./src/scripts/home_service.sh
```

##### Important Note
[Dockerfile](https://github.com/ioasou/RoboND/blob/master/Docker/Dockerfile) can be used for setting up ROS and all required dependencies. 
# RoboND-Project 3
The purpose of this project is to utilise AMCL (Adaptive Monte Carlo Localization) ROS package to localize a robot given a map and sensor readings (odometry and laser scan).  

### Directory Structure
```
	├── catkin_ws
	│   └── src
	│       ├── localization
	│       │   ├── CMakeLists.txt
	│       │   ├── config
	│       │   │   ├── base_local_planner_params.yaml
	│       │   │   ├── costmap_common_params.yaml
	│       │   │   ├── global_costmap_params.yaml
	│       │   │   ├── local_costmap_params.yaml
	│       │   │   ├── __MACOSX
	│       │   │   └── rviz_viewer.rviz
	│       │   ├── launch
	│       │   │   └── amcl.launch
	│       │   ├── maps
	│       │   │   ├── map.pgm
	│       │   │   └── map.yaml
	│       │   └── package.xml
	│       ├── my_robot
	│       │   ├── CMakeLists.txt
	│       │   ├── launch
	│       │   │   ├── robot_description.launch
	│       │   │   └── world.launch
	│       │   ├── meshes
	│       │   │   └── hokuyo.dae
	│       │   ├── package.xml
	│       │   ├── urdf
	│       │   │   ├── my_robot.gazebo
	│       │   │   └── my_robot.xacro
	│       │   └── worlds
	│       │       ├── empty.world
	│       │       ├── project_1_ball.world
	│       │       └── project_1.world
	│       └── teleop_twist_keyboard
	│           ├── CHANGELOG.rst
	│           ├── CMakeLists.txt
	│           ├── package.xml
	│           ├── README.md
	│           └── teleop_twist_keyboard.py
	├── README.md
	└── results
	    ├── rviz_t0.png
	    ├── rviz_t1.png
	    └── rviz_t2.png
```

### Steps to launch

#### Step 1 Compile the code
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_3/catkin_ws
source /opt/ros/kinetic/setup.bash
$ catkin_make
```

#### Step 2 Run Gazebo world
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_3/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

#### Step 3 Run AMCL package
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_3/catkin_ws
$ source devel/setup.bash
$ roslaunch localization amcl.launch
```

#### Step 4 Run Rviz and select navigation goal
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_3/catkin_ws
$ source devel/setup.bash
$ rviz -d src/localization/config/rviz_viewer.rviz
```

Notice that as the robot moves the particles converge towards the true location of the robot, see images below:

![rviz_t0](https://github.com/ioasou/RoboND/blob/master/Projects/Project_3/results/rviz_t0.png)
![rviz_t1](https://github.com/ioasou/RoboND/blob/master/Projects/Project_3/results/rviz_t1.png)
![rviz_t2](https://github.com/ioasou/RoboND/blob/master/Projects/Project_3/results/rviz_t2.png)

##### Important Note
[Dockerfile](https://github.com/ioasou/RoboND/blob/master/Docker/Dockerfile) can be used for setting up ROS and all required dependencies. 

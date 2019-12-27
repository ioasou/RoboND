# RoboND-Project 4
The purpose of this project is to utilise RTAB-MAP ROS package for SLAM.  

### Directory Structure
```
	├── catkin_ws
	│   └── src
	│       ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
	│       ├── mapping
	│       │   ├── CMakeLists.txt
	│       │   ├── database
	│       │   │   └── rtabmap.db
	│       │   ├── include
	│       │   │   └── mapping
	│       │   ├── launch
	│       │   │   ├── localisation.launch
	│       │   │   ├── mapping.launch
	│       │   │   └── teleop.launch
	│       │   ├── package.xml
	│       │   └── src
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
	│       │       └── project_1_ball.world
	│       └── teleop_twist_keyboard
	│           ├── CHANGELOG.rst
	│           ├── CMakeLists.txt
	│           ├── package.xml
	│           ├── README.md
	│           └── teleop_twist_keyboard.py
	├── README.md
	└── results
	    ├── gazebo.png
	    ├── gazebo_topview.png
	    ├── localisation.png
	    ├── map_generation.png
	    └── map_inspect.png
```

### Steps to launch

#### Step 1 Compile the code
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
source /opt/ros/kinetic/setup.bash
$ catkin_make
```

#### Step 2 Run Gazebo world
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
![gazebo_topview](https://github.com/ioasou/RoboND/blob/master/Projects/Project_4/results/gazebo_topview.png)

#### Step 3 Run Teleopeation package
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
$ source devel/setup.bash
$ roslaunch mapping teleop.launch
```

#### Step 4 Run RTAB-MAP and visualisation
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
$ source devel/setup.bash
$ roslaunch mapping mapping.launch
```
![map_generation](https://github.com/ioasou/RoboND/blob/master/Projects/Project_4/results/map_generation.png)

#### Step 5 Download RTAB-MAP database
```sh
https://drive.google.com/drive/folders/1LfdMRXcmPCp4X2uoTFLUWBLP_yMux8H9
```

#### Step 6 Inspect map using rtabmap-databaseViewer
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
$ source devel/setup.bash
$ rtabmap-databaseViewer <rtab_map_name.db>
```
![map_inspect](https://github.com/ioasou/RoboND/blob/master/Projects/Project_4/results/map_inspect.png)

#### Step 6 (Optional) Run Localisation
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_4/catkin_ws
$ source devel/setup.bash
$ roslaunch mapping localisation.launch
```
![map_inspect](https://github.com/ioasou/RoboND/blob/master/Projects/Project_4/results/localisation.png)

![map_inspect](https://github.com/ioasou/RoboND/blob/master/Projects/Project_4/results/gazebo.png)

##### Important Note
[Dockerfile](https://github.com/ioasou/RoboND/blob/master/Docker/Dockerfile) can be used for setting up ROS and all required dependencies. 
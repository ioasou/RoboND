# RoboND-Project 2
The purpose of this project is to develop a robot that can chase a white ball in Gazebo world.  

### Directory Structure
```
	    ├───catkin_ws
		├───src
		    ├── my_robot                       # my_robot package                   
		    │   ├── launch                     # launch folder for launch files   
		    │   │   ├── robot_description.launch
		    │   │   ├── world.launch
		    │   ├── meshes                     # meshes folder for sensors
		    │   │   ├── hokuyo.dae
		    │   ├── urdf                       # urdf folder for xarco files
		    │   │   ├── my_robot.gazebo
		    │   │   ├── my_robot.xacro
		    │   ├── world                      # world folder for world files
		    │   │   ├── project_1_ball.world
	    	    │   │   ├── project_1.world
		    │   │   ├── empty.world
		    │   ├── CMakeLists.txt             # compiler instructions
		    │   ├── package.xml                # package info
		    ├── ball_chaser                    # ball_chaser package                   
		    │   ├── launch                     # launch folder for launch files   
		    │   │   ├── ball_chaser.launch
		    │   ├── src                        # source folder for C++ scripts
		    │   │   ├── drive_bot.cpp
		    │   │   ├── process_image.cpp
		    │   ├── srv                        # service folder for ROS services
		    │   │   ├── DriveToTarget.srv
		    │   ├── CMakeLists.txt             # compiler instructions
		    │   ├── package.xml                # package info                  
		    └──                                 
```

### Steps to launch

#### Step 1 Compile the code
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_2/catkin_ws
$ catkin_make
```

#### Step 2 Run Gazebo world
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_2/catkin_ws
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

#### Step 3 Run ball chaser
```sh
$ Ctrl+Alt+T
$ cd /home/{user}/workspace/RoboND/Projects/Project_2/catkin_ws
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```

Following launch, move the ball around the robot and see how the robot adjust its linear and angular velocity to chase the ball.

##### Important Note
Installation of ROS Kinetic Gazebo required:
sudo apt-get install ros-kinetic-gazebo9-*

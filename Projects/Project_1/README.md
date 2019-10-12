# RoboND-Project 1
The purpose of this project is to learn how to build a two-wheeled robot model with the Model Editor tool in Gazebo. Include this model in an empty Gazebo World. And, finally write a plugin to interact with this world.  

### Directory Structure
```
    Project_1                           # myrobot lab main folder 
    ├── model                           # Model files of the two-wheeled robot
    │   ├── my_robot
    │   │   ├── model.config
    │   │   ├── model.sdf
    ├── script                         # Gazebo World plugin C++ script      
    │   ├── hello_world.cpp
    ├── world                          # Gazebo main World empty scene
    │   ├── my_world
    ├── CMakeLists.txt                 # Link libraries 
    └──                              
```

### Steps to launch the simulation

#### Step 1 Compile the code
```sh
$ cd /home/{user}/workspace/RoboND/Projects/Project_1/
$ mkdir build
$ cd build/
$ cmake ../
$ make
```

#### Step 2 Add the library path to the Gazebo plugin path  
```sh
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/{user}/workspace/RoboND/Projects/Project_1/build
```

#### Step 3 Run the Gazebo World file  
```sh
$ cd /home/{user}/workspace/RoboND/Projects/Project_1/world/
$ gazebo my_world
```
    
 


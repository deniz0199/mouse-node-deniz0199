## Introduction
Mouse Node is a simple application that uses ROS (C++) and publishes the mouse movement data found in "dev/input/mice" to a publisher called topic_pub on the topic "mouse_node". This program can be used to collect input for applications where mouse movement data is used!

## Instructions
Simply build the project using while in the outer mouse-node-deniz0199 folder using "catkin_make" on a terminal. Afterwards, run source devel/setup.bash. Then, on an other terminal, run roscore. Then, use rosrun mouse-node-deniz0199 publisher_node in the aforementioned directory.

## Safety concerns
As this program cannot directly modify user files, data loss should not be an issue. However, as it has direct access to mouse movements, should this information be classified for the user, it is advised to be careful when running it.
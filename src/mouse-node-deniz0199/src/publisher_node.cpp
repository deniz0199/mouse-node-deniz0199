#include "ros/ros.h"
#include "std_msgs/Char.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;

    ros::Publisher topic_pub = nh.advertise<std_msgs::Char>("mouse_node",999);
    ros::Rate loop_rate(1);

    char mouseMvmData[3];

    int file = open("/dev/input/mice", O_RDONLY);

    while(ros::ok()) {

        read(file, mouseMvmData, 3);

        std_msgs::Char x;
        std_msgs::Char y;

        x.data = mouseMvmData[1];
        y.data = mouseMvmData[2];

        topic_pub.publish(x);
        ros::spinOnce();
        loop_rate.sleep();
    }
}



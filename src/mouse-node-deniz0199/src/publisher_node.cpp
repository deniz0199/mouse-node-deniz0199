#include "publisher_node.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;
    ros::Rate loop_rate(2);
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("mouse_node",9999);

    char mouseMvmData[3];

    int file = open("/dev/input/mice", O_RDONLY);

    while(ros::ok()) {

        read(file, mouseMvmData, 3);

        std_msgs::String x;
        std_msgs::String y;

        std::stringstream sx;
        std::stringstream sy; 
        sx << (int)mouseMvmData[1];
        sy << (int)mouseMvmData[2];


        x.data = sx.str();
        y.data = sy.str();

        topic_pub.publish(x);
        topic_pub.publish(y);

        ros::spinOnce();
        loop_rate.sleep();
    }
}



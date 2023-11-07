#include "publisher_node.h"

int main(int argc, char **argv) {
    //Initiliazes the publisher node.
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;
    
    //Publishes new data every 2 seconds.
    ros::Rate loop_rate(2);
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("mouse_node",9999);

    //Array to store mice movement data.
    char mouseMvmData[3];

    //Opens the mouse event file.
    int file = open("/dev/input/mice", O_RDONLY);

    if (file < 0) {
        std::cout<< "File was not opened.";
        return -1;
    }

    //Initializes the strings that will be sent to the publisher.
    std::stringstream sx;
    std::stringstream sy; 

    while(ros::ok()) {

        //Reads the first three bytes of the file.
        read(file, mouseMvmData, 3);

        std_msgs::String x;
        std_msgs::String y;

        //Converts the data into strings.
        sx << (int)mouseMvmData[1];
        sy << (int)mouseMvmData[2];

        x.data = sx.str();
        y.data = sy.str();

        topic_pub.publish(x);
        topic_pub.publish(y);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}


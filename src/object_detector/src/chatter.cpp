#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "chatter");
    ros::NodeHandle nh;
    ros::Publisher detector_pub = nh.advertise<std_msgs::String>("camera1_ros", 1000);

    int count = 0;
    ros::Rate r(20);
    while(ros::ok()){
        //create the message
        std_msgs::String msg;
        std::stringstream ss;
        ss << "from chatter" << count;
        msg.data = ss.str();
        
        //log the message
        ROS_INFO("%s", msg.data.c_str());

        detector_pub.publish(msg);
        ros::spinOnce();
        ++count;
        r.sleep();
    }
}


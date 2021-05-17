#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void cam0Callback(const std_msgs::String::ConstPtr& msg){
     ROS_INFO("Cam 0 heard: [%s]", msg->data.c_str());
}

void cam1Callback(const std_msgs::String::ConstPtr& msg){
     ROS_INFO("Cam 1 heard: [%s]", msg->data.c_str());
}

void cam2Callback(const std_msgs::String::ConstPtr& msg){
     ROS_INFO("Cam 2 heard: [%s]", msg->data.c_str());
}



int main(int argc, char **argv){
    ros::init(argc, argv, "detector");
    ros::NodeHandle nh;
    ros::Publisher detector_pub = nh.advertise<std_msgs::String>("detector", 1000);
    ros::Subscriber cam0_sub = nh.subscribe("camera0_cv", 1000, cam0Callback);
    ros::Subscriber cam1_sub = nh.subscribe("camera1_cv", 1000, cam1Callback);
    ros::Subscriber cam2_sub = nh.subscribe("camera2_cv", 1000, cam2Callback);

    
    int count = 0;
    ros::Rate r(10);
    while(ros::ok()){
        //create the message
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hey lol" << count;
        msg.data = ss.str();
        
        //log the message
        ROS_INFO("%s", msg.data.c_str());

        detector_pub.publish(msg);

        //wait
        ros::spinOnce();
        ++count;
        r.sleep();
    }
}

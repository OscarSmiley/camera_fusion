#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

//displacement from cam0 
const int XDISP = 10;
const int YDISP = 0;
const int ZDISP = 0;

void cam0_callback(const std_msgs::String::ConstPtr& msg){
    //call back for cam0 data
    ROS_INFO("I heard: %s", msg->data.c_str());
    
}

void cam0_to_cam1(int * in, int * out){
    //TODO: add cam0 -> cam1 co-ordinate transform
    
}

void cam1_to_cam0(int * in, int * out){
    //TODO: add cam1 -> cam0 co-ordinate transform
    
}

int main(int argc, char **argv){
    ros::init(argc, argv, "camera1");
    ros::NodeHandle nh;
    ros::Publisher cam1_pub = nh.advertise<std_msgs::String>("camera1_cv", 1000);
    ros::Subscriber cam0_sub = nh.subscribe("camera0_cv", 1000, cam0_callback);
    
    std::string testinput;

    int count = 0;
    ros::Rate r(5);
    while(ros::ok()){
        //create the message
        std_msgs::String msg;
        std::string testinput;
        std::stringstream ss;
        
        //log the message
        //ROS_INFO("%s", testinput);
        //ROS_INFO("%s", msg.data.c_str());

        //cam1_pub.publish(msg);
        ros::spinOnce();
        ++count;
        r.sleep();
    }
    return 0;
}

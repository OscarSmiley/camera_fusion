#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


int main(int argc, char **argv){
    ros::init(argc, argv, "camera0");
    ros::NodeHandle nh;
    ros::Publisher cam1_pub = nh.advertise<std_msgs::String>("camera0_cv", 1000);

    if(argc < 1){
         ROS_INFO("not enough arguments");
        return -1;
    }

    std::ifstream fstrm(argv[1]);
    if(!fstrm.is_open()){
        ROS_INFO("could not open test file");
        return -1;
    }
    std::string testinput;

    int count = 0;
    ros::Rate r(5);
    while(ros::ok()){
        //create the message
        std_msgs::String msg;
        std::string testinput;
        std::stringstream ss;
        if(getline(fstrm, testinput)){
            msg.data = testinput;
        }
        else{
            break;
        }
        
        //log the message
        //ROS_INFO("%s", testinput);
        ROS_INFO("%s", msg.data.c_str());

        cam1_pub.publish(msg);
        ros::spinOnce();
        ++count;
        r.sleep();
    }
}

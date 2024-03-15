#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "uvinterfaces/msg/uv_status.hpp"
/// @brief a class for unmanned vehicle
class UV
{
public:
    /// @brief declare a uv object
    /// @param name_ name of the vehicle
    /// @param ip_ ipv4 address of the vehicle
    /// @param id_ id num
    UV(std::string name_,std::string ip_,int id_);
    /// @brief callback to update status
    /// @param msg 
    void statusUpdateCallback(const uvinterfaces::msg::UvStatus::SharedPtr msg);
    /// @brief callback to update image
    void imgUpdateCallback();
public:
/// Identity information  

    //name of the vehicle
    std::string name;
    //ipv4 address of the vehicle 
    std::string ip;
    //id num
    int id;
/// status infomation

    //Communication establishment flag 
    bool isUp;
    //Voltage of battery
    float voltage;
/// Low level motion information 

    //Arm position
    uint16_t armHand,armArm,armBase;
    //wheel speed
    float wheelSpeedLeft,wheelSpeedRight;
    //tripod degree
    float tripod;
    //motion infomation
    float acc_x,acc_y,acc_z;
    float vel_x,vel_y,vel_z;
    float pos_x,pos_y,pos_z;
    float pitch,yaw,roll;

/// image
    cv::Mat image;
};

#include "uv.hpp"

UV::UV(std::string name_, std::string ip_, int id_)
    :name(name_),ip(ip_),id(id_)
{
    isUp = false;
    voltage = 0;
    armHand = 0;
    armArm = 0;
    armBase = 0;
    wheelSpeedLeft = 0;
    wheelSpeedRight = 0;
    tripod = 0;
    acc_x = 0;
    acc_y = 0;
    acc_z = 0;
    vel_x = 0;
    vel_y = 0;
    vel_z = 0;
    pos_x = 0;
    pos_y = 0;
    pos_z = 0;
    pitch = 0;
    yaw = 0;
    roll = 0;
    //image = new cv::Mat();
}

void UV::statusUpdateCallback(const uvinterfaces::msg::UvStatus::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("uv"),"callback");
    voltage = msg->voltage;
    armHand = msg->arm_hand;
    armArm = msg->arm_arm;
    armBase = msg->arm_base;
    wheelSpeedLeft = msg->wheelspeed_left;
    wheelSpeedRight = msg->wheelspeed_right;
    tripod = msg->tripod;
    acc_x = msg->acc_x;
    acc_y = msg->acc_y;
    acc_z = msg->acc_z;
    vel_x = msg->vel_x;
    vel_y = msg->vel_y;
    vel_z = msg->vel_z;
    pos_x = msg->pos_x;
    pos_y = msg->pos_y;
    pos_z = msg->pos_z;
    pitch = msg->pitch;
    yaw = msg->yaw;
    roll = msg->roll;
}

void UV::imgUpdateCallback()
{
}

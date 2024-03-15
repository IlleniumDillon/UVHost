#pragma once
#include <chrono>
#include <functional>
#include "uv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "uvinterfaces/msg/uv_command.hpp"
#include "uvinterfaces/msg/uv_status.hpp"
#include "joystick.hpp"

using namespace std::chrono_literals;

class UV;

class UVHostNode    :   public rclcpp::Node
{
public:
    UVHostNode();

    void waitForConnect(std::chrono::milliseconds timeout);
    void freshConnectStatus();

    void pubCommandTo(int id, std::shared_ptr<Joystick> j);

protected:

private:
    void timerCallback();

public:
    bool isUp = false;
    rclcpp::TimerBase::SharedPtr timer;
    std::vector<UV*> uvList;
    std::vector<rclcpp::Subscription<uvinterfaces::msg::UvStatus>::SharedPtr> subStatusList;
    ///TODO: subImgList
    std::vector<rclcpp::Publisher<uvinterfaces::msg::UvCommand>::SharedPtr> pubList;

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subImg = nullptr;

    //rclcpp::Publisher<>
};

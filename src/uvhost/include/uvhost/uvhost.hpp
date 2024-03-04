#pragma once
#include <chrono>
#include <functional>
#include "uv.hpp"
#include "rclcpp/rclcpp.hpp"
#include "uvinterfaces/msg/uv_command.hpp"
#include "uvinterfaces/msg/uv_status.hpp"

using namespace std::chrono_literals;

class UV;

class UVHostNode    :   public rclcpp::Node
{
public:
    UVHostNode();

    void waitForConnect(std::chrono::milliseconds timeout);
protected:

private:
    void timerCallback();
public:

protected:

private:
    bool isUp = false;
    rclcpp::TimerBase::SharedPtr timer;
    std::vector<UV*> uvList;
    std::vector<rclcpp::Subscription<uvinterfaces::msg::UvStatus>::SharedPtr> subStatusList;
    ///TODO: subImgList
    std::vector<rclcpp::Publisher<uvinterfaces::msg::UvCommand>::SharedPtr> pubList;
    //rclcpp::Publisher<>
};
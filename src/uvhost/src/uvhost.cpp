#include "uvhost.hpp"
#include <string>
#include <regex>
#include <thread>

UVHostNode::UVHostNode()
    :Node("uvhost")
{
    this->declare_parameter("uvList",std::vector<std::string>());
    std::vector<std::string> uvListStringList = this->get_parameter("uvList").as_string_array();
    for(auto str : uvListStringList)
    {
        std::vector<std::string> params;
        //boost::split(params,str,";");
        std::regex reg("@");
        std::sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
        decltype(pos) end;
        for (; pos != end; ++pos)
        {
            params.push_back(pos->str());
        }

        RCLCPP_INFO(this->get_logger(),"try to connect:%s@%s",params.at(0).c_str(),params.at(1).c_str());

        UV* temp = new UV(params.at(0),params.at(1),uvList.size());
        uvList.push_back(temp);
        pubList.push_back(
            this->create_publisher<uvinterfaces::msg::UvCommand>("/"+temp->name+"/hostcommand",10)
        );
        subStatusList.push_back(
            this->create_subscription<uvinterfaces::msg::UvStatus>("/"+temp->name+"/status",10,std::bind(&UV::statusUpdateCallback,temp,std::placeholders::_1))
        );
    }
    
    timer = this->create_wall_timer(100ms, std::bind(&UVHostNode::timerCallback, this));
}

void UVHostNode::waitForConnect(std::chrono::milliseconds timeout)
{
    bool ok = false;
    std::chrono::system_clock::time_point whenQuit = std::chrono::system_clock::now() + timeout;
    while(std::chrono::system_clock::now() < whenQuit)
    {
        ok = true;
        for(auto uv : uvList)
        {
            if(uv->voltage < 11.1) 
            {
                ok = false; 
                RCLCPP_WARN(this->get_logger(),"%s is not answering",uv->name.c_str());
                break;
            }
        }
        if(ok) break;
    }
    isUp = ok;
}

void UVHostNode::freshConnectStatus()
{
    bool ok = true;
    for(auto uv : uvList)
    {
        if(uv->voltage < 11.1)
        {
            ok = false;
            RCLCPP_WARN(this->get_logger(),"%s is not answering:%f",uv->name.c_str(),uv->voltage);
        }
        else
        {
            uv->isUp = true;
        }
    }
    isUp = ok;
}

void UVHostNode::pubCommandTo(int id, std::shared_ptr<Joystick> j)
{
    uvinterfaces::msg::UvCommand msg;
    msg.time = 0;
    msg.degree = - 130.0 * (float)j->rx / 32767.0;
    msg.vc = - 0.2 * (float)j->ly / 32767.0;
    msg.wc = - 0.5 * (float)j->lx / 32767.0;
    // msg.vc = - 0.45 * (float)j->ly / 32767.0;
    // msg.wc = - 2.0 * (float)j->lx / 32767.0;
    //
    /*msg.vc = - 0.5 * (float)j->yy/ 32767.0;
    msg.wc = - 3.0 * (float)j->xx / 32767.0;*/
    if(j->lbu)
    {
        msg.arm = 2048;
        msg.base = 2048;
    }
    else
    {
        msg.arm = 3500;
        msg.base = 500;
    }
    if(j->lbd)
    {
        msg.hand = 3000;
    }
    else
    {
        msg.hand = 2048;
    }
    pubList.at(id)->publish(msg);
}


void UVHostNode::timerCallback()
{
    //if(isUp == false) return;
    for(auto uv : uvList)
    {
        //if(uv->isUp == false) continue;
        if(uv->voltage < 11.1)
        {
            uv->isUp = false;
            //RCLCPP_ERROR(this->get_logger(),"LOW POWER:%s",uv->name.c_str());
        }
    }
}

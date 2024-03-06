#include "joystick.hpp"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>
#include <linux/input.h>
#include <linux/joystick.h>

Joystick::Joystick(std::string dev)
{
    joyFd = open(dev.c_str(),O_RDONLY);
}

Joystick::~Joystick()
{
    close(joyFd);
}

void Joystick::get()
{
    struct js_event js;
    int len = read(joyFd, &js, sizeof(struct js_event)); 
    if(len < 0) return;
    int type, number, value;

    type = js.type;  
    number = js.number;  
    value = js.value;  
    this->time = js.time;  

    if (type == JS_EVENT_BUTTON)  
    {  
        switch (number)  
        {  
            case XBOX_BUTTON_A:  
                this->a = value;  
                break;  

            case XBOX_BUTTON_B:  
                this->b = value;  
                break;  

            case XBOX_BUTTON_X:  
                this->x = value;  
                break;  

            case XBOX_BUTTON_Y:  
                this->y = value;  
                break;  

            case XBOX_BUTTON_LBU:  
                this->lbu = value;  
                break;  

            case XBOX_BUTTON_RBU:  
                this->rbu = value;  
                break;  

            case XBOX_BUTTON_LBD:  
                this->lbd = value;  
                break;  

            case XBOX_BUTTON_RBD:  
                this->rbd = value;  
                break;  

            case XBOX_BUTTON_START:  
                this->start = value;  
                break;  

            case XBOX_BUTTON_SELECT:  
                this->select = value;  
                break;  

            case XBOX_BUTTON_LO:  
                this->lo = value;  
                break;  

            case XBOX_BUTTON_RO:  
                this->ro = value;  
                break;  

            default:  
                break;  
        }  
    }  
    else if (type == JS_EVENT_AXIS)  
    {  
        switch(number)  
        {  
            case XBOX_AXIS_LX:  
                this->lx = value;  
                break;  

            case XBOX_AXIS_LY:  
                this->ly = value;  
                break;  

            case XBOX_AXIS_RX:  
                this->rx = value;  
                break;  

            case XBOX_AXIS_RY:  
                this->ry = value;  
                break;   

            case XBOX_AXIS_XX:  
                this->xx = value;  
                break;  

            case XBOX_AXIS_YY:  
                this->yy = value;  
                break;  

            default:  
                break;  
        }  
    }  
    else  
    {  
        /* Init do nothing */  
    }  
}

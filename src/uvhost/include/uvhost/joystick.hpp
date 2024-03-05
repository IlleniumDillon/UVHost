#pragma once 
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

///type of joystick frame
#define XBOX_TYPE_BUTTON    0x01  
#define XBOX_TYPE_AXIS      0x02  
///button map
#define XBOX_BUTTON_A       0x00  
#define XBOX_BUTTON_B       0x01  
#define XBOX_BUTTON_X       0x03  
#define XBOX_BUTTON_Y       0x04  
#define XBOX_BUTTON_LBU      0x06  
#define XBOX_BUTTON_LBD      0x08  
#define XBOX_BUTTON_RBU      0x07  
#define XBOX_BUTTON_RBD      0x09 
#define XBOX_BUTTON_SELECT   0x0a  
#define XBOX_BUTTON_START    0x0b  
#define XBOX_BUTTON_LO      0x0d    /* 左摇杆按键 */  
#define XBOX_BUTTON_RO      0x0e    /* 右摇杆按键 */  
///button status
#define XBOX_BUTTON_ON      0x01  
#define XBOX_BUTTON_OFF     0x00  
///axis map
#define XBOX_AXIS_LX        0x00    /* 左摇杆X轴 */  
#define XBOX_AXIS_LY        0x01    /* 左摇杆Y轴 */  
#define XBOX_AXIS_RX        0x02    /* 右摇杆X轴 */  
#define XBOX_AXIS_RY        0x03    /* 右摇杆Y轴 */   
#define XBOX_AXIS_XX        0x06    /* 方向键X轴 */  
#define XBOX_AXIS_YY        0x07    /* 方向键Y轴 */  
///axis value range
#define XBOX_AXIS_VAL_UP        -32767  
#define XBOX_AXIS_VAL_DOWN      32767  
#define XBOX_AXIS_VAL_LEFT      -32767  
#define XBOX_AXIS_VAL_RIGHT     32767  

#define XBOX_AXIS_VAL_MIN       -32767  
#define XBOX_AXIS_VAL_MAX       32767  
#define XBOX_AXIS_VAL_MID       0x00  

/// @brief class to manage joystick
class Joystick
{
public:
    /// @brief open a joystick device
    /// @param dev device file
    /// @example Joystick j("/dev/input/js0");
    Joystick(std::string dev);
    /// @brief close a joystick device
    ~Joystick();
    /// @brief update joystick values
    void get();
public:
    int     time = 0;  

    int     a = 0;  
    int     b = 0;  
    int     x = 0;  
    int     y = 0;  
    int     lbu = 0;  
    int     lbd = 0;  
    int     rbu = 0;  
    int     rbd = 0;  
    int     select = 0;  
    int     start = 0;  
    int     lo = 0;  
    int     ro = 0;  

    int     lx = 0;  
    int     ly = 0;  
    int     rx = 0;  
    int     ry = 0;   
    int     xx = 0;  
    int     yy = 0;  
private :
    /// file of joystick
    int joyFd;
};
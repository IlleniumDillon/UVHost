#include "rclcpp/rclcpp.hpp"
#include "uvhost.hpp"
#include "joystick.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  RCLCPP_INFO(rclcpp::get_logger("main"),"OK");
  std::shared_ptr<UVHostNode> nh= std::make_shared<UVHostNode>();
  rclcpp::spin(nh);
  /*Joystick j("/dev/input/js0");
  while(1)  
  {  
      j.get();  
      
      usleep(1000);

      RCLCPP_INFO(rclcpp::get_logger("main"),"Time:%8d A:%d B:%d X:%d Y:%d LBU:%d RBU:%d LBD:%d RBD:%d start:%d select:%d LO:%d RO:%d XX:%-6d YY:%-6d LX:%-6d LY:%-6d RX:%-6d RY:%-6d",  
              j.time, j.a, j.b, j.x, j.y, j.lbu, j.rbu, j.lbd, j.rbd, j.start, j.select, j.lo, j.ro,  
              j.xx, j.yy, j.lx, j.ly, j.rx, j.ry);  
  } */
  rclcpp::shutdown();
  return 0;
}
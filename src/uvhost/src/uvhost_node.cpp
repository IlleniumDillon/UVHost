#include "rclcpp/rclcpp.hpp"
#include "uvhost.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  RCLCPP_INFO(rclcpp::get_logger("main"),"OK");
  std::shared_ptr<UVHostNode> nh= std::make_shared<UVHostNode>();
  rclcpp::spin(nh);
  rclcpp::shutdown();
  return 0;
}
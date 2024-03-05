echo generate ui and moc file
uic /home/zj/project/ROS2WS/src/uvhost/src/uvui.ui -o /home/zj/project/ROS2WS/src/uvhost/include/uvhost/ui_uvui.hpp
moc /home/zj/project/ROS2WS/src/uvhost/include/uvhost/uvui.h -o /home/zj/project/ROS2WS/src/uvhost/src/moc_uvui.cpp
echo done
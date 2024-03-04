import launch
import launch_ros.actions
import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='uvhost',
            executable='uvhost',
            name='uvhost',
            parameters=[
                {
                    "uvList":["UV01:192.168.50.210",
                              "UV02:192.168.50.211",
                              "UV03:192.168.50.212",
                              "UV04:192.168.50.213",
                              "UV05:192.168.50.214"]
                }
            ]),
  ])
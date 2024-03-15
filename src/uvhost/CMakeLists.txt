cmake_minimum_required(VERSION 3.5)
project(uvhost)

# Default to C99
# if(NOT CMAKE_C_STANDARD)
#   set(CMAKE_C_STANDARD 99)
# endif()

# # Default to C++14
# if(NOT CMAKE_CXX_STANDARD)
#   set(CMAKE_CXX_STANDARD 14)
# endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(OpenCV REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(uvinterfaces REQUIRED)
find_package(sensor_msgs REQUIRED)
set(Qt6_DIR /home/zj/Qt/6.5.3/gcc_64/lib/cmake/Qt6)
set(Qt6Core_DIR /home/zj/Qt/6.5.3/gcc_64/lib/cmake/Qt6Core)
set(Qt6CoreTools_DIR /home/zj/Qt/6.5.3/gcc_64/lib/cmake/Qt6CoreTools)
set(Qt6Gui_DIR /home/zj/Qt/6.5.3/gcc_64/lib/cmake/Qt6Gui)
set(Qt6GuiTools_DIR /home/zj/Qt/6.5.3/gcc_64/lib/cmake/Qt6GuiTools)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
include_directories(
  ${OpenCV_INCLUDE_DIRS} 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
  
  ~/Qt/6.5.3/gcc_64/include/
  ~/Qt/6.5.3/gcc_64/include/QtCore/
  ~/Qt/6.5.3/gcc_64/include/QtGui/
  ~/Qt/6.5.3/gcc_64/include/QtWidgets/

  ~/Qt/Qt-Advanced-Docking-System-4.2.1/src/
)

file(GLOB SOURCEFILE src/*.cpp)
add_executable(uvhost ${SOURCEFILE})
link_directories(~/Qt/6.5.3/gcc_64/lib)
target_link_libraries(uvhost Qt6::Widgets Qt6::Core Qt6::Gui)
ament_target_dependencies(uvhost rclcpp uvinterfaces OpenCV sensor_msgs)
install(TARGETS uvhost DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

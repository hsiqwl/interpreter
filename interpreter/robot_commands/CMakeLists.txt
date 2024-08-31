cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)


add_library(robot_commands STATIC src/robot_commands.cpp)
target_include_directories(robot_commands PUBLIC include)
target_link_libraries(robot_commands command_interface robot)
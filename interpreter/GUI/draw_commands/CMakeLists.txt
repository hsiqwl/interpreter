cmake_minimum_required(VERSION 3.27)
project(robot_GUI)

set(CMAKE_CXX_STANDARD 20)

add_library(draw_commands STATIC src/draw_commands.cpp)
target_include_directories(draw_commands PUBLIC include)
target_link_libraries(draw_commands command_interface map robot)
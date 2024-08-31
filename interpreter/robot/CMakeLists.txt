cmake_minimum_required(VERSION 3.27)
project(robot_env)

set(CMAKE_CXX_STANDARD 20)

add_library(robot STATIC src/robot.cpp)
target_include_directories(robot PUBLIC include)
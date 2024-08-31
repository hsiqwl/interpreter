cmake_minimum_required(VERSION 3.27)
project(robot_env)

set(CMAKE_CXX_STANDARD 20)

add_library(map STATIC src/map.cpp)
target_include_directories(map PUBLIC include)
target_link_libraries(map cell values)
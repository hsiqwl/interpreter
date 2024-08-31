cmake_minimum_required(VERSION 3.27)
project(robot_env)

set(CMAKE_CXX_STANDARD 20)

add_library(loader INTERFACE)
target_include_directories(loader INTERFACE include)
target_link_libraries(loader INTERFACE map robot config++)
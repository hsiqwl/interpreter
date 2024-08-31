cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(command_interface INTERFACE)
target_include_directories(command_interface INTERFACE include)
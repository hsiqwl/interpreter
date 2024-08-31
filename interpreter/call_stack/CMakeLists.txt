cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(call__stack STATIC src/call_stack.cpp)
target_include_directories(call__stack PUBLIC include)
target_link_libraries(call__stack activation_record)
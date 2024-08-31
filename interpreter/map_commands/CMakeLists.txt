cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(map_commands STATIC src/map_commands.cpp)
target_include_directories(map_commands PUBLIC include)
target_link_libraries(map_commands command_interface map robot values)
cmake_minimum_required(VERSION 3.27)
project(robot_env)

set(CMAKE_CXX_STANDARD 20)

add_library(remove_env_handler STATIC src/remote_environment_handler.cpp)
target_include_directories(remove_env_handler PUBLIC include)
target_link_libraries(remove_env_handler singleton robot_commands map_commands draw_commands loader)
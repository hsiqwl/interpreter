cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(interpreter_lib STATIC src/interpreter.cpp)
target_include_directories(interpreter_lib PUBLIC include)
target_link_libraries(interpreter_lib parse_driver semantic_analyzer executor)
cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(exe_context STATIC src/execution_context.cpp)
target_include_directories(exe_context PUBLIC include)
target_link_libraries(exe_context call__stack nodes)

add_library(exe_context_builder STATIC src/execution_context_builder.cpp)
target_include_directories(exe_context_builder PUBLIC include)
target_link_libraries(exe_context_builder exe_context ast)
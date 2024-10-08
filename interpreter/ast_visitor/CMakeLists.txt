cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(visitor INTERFACE)
target_include_directories(visitor INTERFACE include)

add_library(value_getter INTERFACE)
target_include_directories(value_getter INTERFACE include)

add_library(printer STATIC src/printer.cpp)
target_include_directories(printer PUBLIC include)
target_link_libraries(printer visitor node_traits)

add_library(type_resolver STATIC src/type_resolver.cpp)
target_include_directories(type_resolver PUBLIC include)
target_link_libraries(type_resolver visitor node_traits value_getter symbol_table semantic_errors)

add_library(semantic_analyzer STATIC src/semantic_analyzer.cpp src/semantic_analyzer_caller.cpp)
target_include_directories(semantic_analyzer PUBLIC include)
target_link_libraries(semantic_analyzer type_resolver error_context ast)

add_library(executor STATIC src/executor.cpp src/executor_caller.cpp)
target_include_directories(executor PUBLIC include)
target_link_libraries(executor exe_context_builder visitor value_getter node_traits ast remove_env_handler executable_env_ostream)


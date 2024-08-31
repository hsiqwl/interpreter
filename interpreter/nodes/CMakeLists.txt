cmake_minimum_required(VERSION 3.27)
project(interpreter)

set(CMAKE_CXX_STANDARD 20)

add_library(node_traits INTERFACE)
target_include_directories(node_traits INTERFACE include)
target_link_libraries(node_traits INTERFACE locations printable values robot)

add_library(nodes STATIC
        src/binary_op.cpp
        src/unary_op.cpp
        src/signed_literal.cpp
        src/unsigned_literal.cpp
        src/cell_literal.cpp
        src/var_decl.cpp
        src/var_ref.cpp
        src/assign.cpp
        src/statement_list.cpp
        src/initialization.cpp
        src/if_node.cpp
        src/while_node.cpp
        src/func_decl.cpp
        src/func_call.cpp
        src/matrix_elem_ref.cpp
        src/xray_node.cpp
        src/move_robot.cpp
        src/print_node.cpp)
target_include_directories(nodes PUBLIC include)
target_link_libraries(nodes locations printable visitor values robot)
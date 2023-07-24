cmake_minimum_required(VERSION 3.22)

set(CXX_STANDARD C++17)

project(examples)

add_compile_options(${CMAKE_CXX_FLAGS_DEBUG})

add_subdirectory(config)
add_subdirectory(plugin-test)


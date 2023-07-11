cmake_minimum_required(VERSION 3.22)

set(CXX_STANDARD C++17)

project(config_sdk)

add_compile_options(${CMAKE_CXX_FLAGS_DEBUG})

add_subdirectory(src)

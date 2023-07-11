cmake_minimum_required(VERSION 3.22)

set(CXX_STANDARD C++17)

project(plugin_test)

add_compile_options(${CMAKE_CXX_FLAGS_DEBUG})

find_package(Boost 1.74.0 COMPONENTS filesystem system REQUIRED)

add_subdirectory(src)

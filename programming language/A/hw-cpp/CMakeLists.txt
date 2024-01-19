cmake_minimum_required(VERSION 3.22)
project(hw VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(GTest REQUIRED)
include_directories(/usr/local/include/gtest)
link_directories(/usr/local/lib)

add_subdirectory(hw1)


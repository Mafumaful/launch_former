cmake_minimum_required(VERSION 3.0.0)

SET(CMAKE_BUILD_TYPE "Debug")
project(ros_tool)
add_compile_options(-std=c++17)
include_directories(include)
add_executable(test1 src/test1.cpp)
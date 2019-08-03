cmake_minimum_required(VERSION 3.8)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(yelp)
add_subdirectory(amazon)
add_subdirectory(microsoft)


add_executable(Leetcode FindK.cpp)

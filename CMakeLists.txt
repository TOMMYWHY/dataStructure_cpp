cmake_minimum_required(VERSION 3.14)
project(dataStructure_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(dataStructure_cpp main.cpp)
add_executable(dynamicArray dynamicArray/main.c dynamicArray/DynamicArray.h dynamicArray/DynamicArray.c)
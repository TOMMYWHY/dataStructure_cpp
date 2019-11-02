cmake_minimum_required(VERSION 3.14)
project(dataStructure_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(dynamicArray dynamicArray/main.c dynamicArray/DynamicArray.h dynamicArray/DynamicArray.c)
add_executable(selectionSort sort/selectionSort/main.cpp)
add_executable(insertionSort sort/insertionSort/main.cpp)
add_executable(mergeSort sort/mergeSort/main.cpp)
add_executable(mergeSortBU sort/mergeSort/mergeSortBU.cpp)

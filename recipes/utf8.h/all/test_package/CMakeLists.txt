cmake_minimum_required(VERSION 3.15)
project(test_package LANGUAGES CXX)

find_package(utf8.h REQUIRED CONFIG)

add_executable(${PROJECT_NAME} test_package.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE utf8.h::utf8.h)

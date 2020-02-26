cmake_minimum_required(VERSION 3.5)

project(cpp-base64 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(test test.cpp base64.cpp)


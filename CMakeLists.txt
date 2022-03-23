cmake_minimum_required(VERSION 3.21)
project(List)

set(CMAKE_CXX_STANDARD 14)

set (SOURCES
        "main.cpp"
        "Vector.cpp")

add_executable(List ${SOURCES})

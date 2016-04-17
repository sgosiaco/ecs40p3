cmake_minimum_required(VERSION 3.5)
project(ecs40p3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(SOURCE_FILES
    flight.cpp
    flight.h
    main.cpp
    plane.cpp
    plane.h
    utilities.cpp
    utilities.h)

add_executable(ecs40p3 ${SOURCE_FILES})
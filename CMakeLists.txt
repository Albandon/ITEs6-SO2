cmake_minimum_required(VERSION 3.28)
project(PhilosophersDiningProblem)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --static")

add_executable(PhilosophersDiningProblem main.cpp
        Philosoph.cpp
        Philosoph.h
        DiningTable.cpp
        DiningTable.h)

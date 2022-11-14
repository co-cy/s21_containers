cmake_minimum_required(VERSION 3.23)
project(CPPContainers)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(CPPContainers
        tmp.cpp vector/vector.hpp stack/stack.hpp set/set.hpp queue/queue.hpp map/map.h list/list.h)

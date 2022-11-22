cmake_minimum_required(VERSION 3.21)
project(CPPContainers)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(.)

include("GoogleTest")


add_executable(list_test
        s21_containers.h
        list/tests/construct.cc
        list/tests/empty.cc
        list/tests/max_size.cc
        list/tests/size.cc
        list/tests/front.cc
        list/tests/back.cc
        list/tests/clear.cc
        list/tests/swap.cc list/tests/insert.cc list/tests/erase.cc list/tests/push_back.cc list/tests/pop_back.cc list/tests/push_front.cc list/tests/pop_front.cc list/tests/reverse.cc list/tests/unique.cc)
target_link_libraries(list_test gtest gtest_main)

#add_executable(CPPContainers
#        tmp.cpp vector/vector.hpp stack/stack.hpp set/set.hpp queue/queue.hpp map/map.h list/list.h abstract/abstract.h node/node.h list/tests/constract.cc list/tests/empty.cc list/tests/size.cc list/tests/max_size.cc)



cmake_minimum_required(VERSION 3.21)
project(CPPContainers)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(.)

include("GoogleTest")


add_executable(list_test
        node/node.h
        list/list.h
        list/tests/construct.cpp
        list/tests/empty.cpp
        list/tests/max_size.cpp
        list/tests/size.cpp
        list/tests/front.cpp
        list/tests/back.cpp
        list/tests/clear.cpp
        list/tests/swap.cpp
        list/tests/insert.cpp
        list/tests/erase.cpp
        list/tests/push_back.cpp
        list/tests/pop_back.cpp
        list/tests/push_front.cpp
        list/tests/pop_front.cpp
        list/tests/reverse.cpp
        list/tests/unique.cpp
        list/tests/merge.cpp
        list/tests/emplace.cpp
        list/tests/emplace_back.cpp
        list/tests/emplace_front.cpp
        list/tests/splice.cpp list/tests/sort.cpp)
target_link_libraries(list_test gtest gtest_main)

add_executable(vector_test
        vector/vector.h
        vector/tests/construct.cpp
        vector/tests/front.cpp
        vector/tests/back.cpp
        vector/tests/at.cpp
        vector/tests/operator[].cpp
        vector/tests/data.cpp
        vector/tests/empty.cpp
        vector/tests/size.cpp
        vector/tests/max_size.cpp
        vector/tests/capacity.cpp
        vector/tests/shrink_to_fit.cpp
        vector/tests/clear.cpp
        vector/tests/insert.cpp
        vector/tests/erase.cpp
        vector/tests/push_back.cpp
        vector/tests/pop_back.cpp
        vector/tests/swap.cpp
        vector/tests/reserve.cpp
        vector/tests/emplace.cpp
        vector/tests/emplace_back.cpp)
target_link_libraries(vector_test gtest gtest_main)

add_executable(array_test
        array/array.h
        array/tests/construct.cpp
        array/tests/operator[].cpp
        array/tests/at.cpp
        array/tests/back.cpp
        array/tests/front.cpp
        array/tests/empty.cpp
        array/tests/size.cpp
        array/tests/max_size.cpp
        array/tests/data.cpp
        array/tests/swap.cpp
        array/tests/fill.cpp)
target_link_libraries(array_test gtest gtest_main)

add_executable(queue_test
        queue/queue.h
        queue/tests/construct.cpp)
target_link_libraries(queue_test gtest gtest_main)


add_executable(stack_test
        stack/stack.h
        stack/tests/top.cpp
        stack/tests/empty.cpp
        stack/tests/size.cpp
        stack/tests/swap.cpp
        stack/tests/push.cpp
        stack/tests/pop.cpp
        stack/tests/emplace_front.cpp
        stack/tests/construct.cpp)
target_link_libraries(stack_test gtest gtest_main)

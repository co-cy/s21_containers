cmake_minimum_required(VERSION 3.23)
project(CPPContainers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(.)

include("GoogleTest")

enable_testing()

add_executable(map_test
        tree/tree.h
        map/map.h
        map/tests/map_tests.cc)
target_link_libraries(map_test gtest gtest_main)

add_executable(set_test
        tree/tree.h
        set/set.h
        set/tests/set_tests.cc)
target_link_libraries(set_test gtest gtest_main)

add_executable(multiset_test
        tree/tree.h
        multiset/multiset.h
        multiset/tests/multiset_tests.cc)
target_link_libraries(multiset_test gtest gtest_main)

gtest_discover_tests(map_test)
gtest_discover_tests(set_test)
gtest_discover_tests(multiset_test)

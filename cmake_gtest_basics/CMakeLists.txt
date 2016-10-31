project(cmake_basics)
cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
#message(STATUS GTEST_ROOT=$ENV{GTEST_ROOT})
#include_directories($ENV{GTEST_ROOT}/include)
#link_directories($ENV{GTEST_ROOT}/lib)

add_executable(test1 gtest/test1.cpp)
target_link_libraries(test1 ${GTEST_BOTH_LIBRARIES})

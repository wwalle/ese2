project(cmake_basics)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

find_package(Threads)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(test1 gtest/test1.cpp)
target_link_libraries(test1 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

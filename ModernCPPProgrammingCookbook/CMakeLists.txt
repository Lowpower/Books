cmake_minimum_required(VERSION 2.8.12)
project(cppcookbook)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fexceptions -g -Wall")
set(CMAKE_C_COMPILER /usr/local/gcc-12/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/local/gcc-12/bin/g++)
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

SET(BOOST_PATH "" CACHE STRING "Path to the installation path of Boost")
SET(GTEST_PATH "" CACHE STRING "Path to the installation path of Google Test")
SET(GTEST_PATH_LIB "" CACHE STRING "Path to the Google Test libraries directory")
SET(CATCH_PATH "" CACHE STRING "Path to the installation path of Catch2")
SET(RANGES_PATH "" CACHE STRING "Path to the installation path of Ranges-v3")
SET(CPPCORO_PATH "" CACHE STRING "Path to the installation path of cppcoro")
SET(SKIP_TEST_PROJECTS false CACHE BOOL "Flag to prevent the generation of unit test projects")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

#include_directories(${BOOST_PATH})
# 输出实际使用的编译器版本
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
add_executable(10 10.6.cpp)
set_target_properties(10 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
include_directories(${CMAKE_SOURCE_DIR}/include)
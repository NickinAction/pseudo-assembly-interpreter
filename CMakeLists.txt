cmake_minimum_required(VERSION 3.15)
project(pseudo_assembly_interpreter)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)

add_executable(pseudo_assembly_interpreter main.cpp processor.cpp Register.cpp Parser.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(pai_unittest processor.cpp Register.cpp Parser.cpp Parser_test.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(pai_unittest gtest gtest_main)

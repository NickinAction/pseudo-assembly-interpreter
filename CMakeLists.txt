cmake_minimum_required(VERSION 3.15)
project(pseudo_assembly_interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(pseudo_assembly_interpreter main.cpp processor.cpp Register.cpp Register.h)
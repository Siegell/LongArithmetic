cmake_minimum_required(VERSION 3.9)
project(LongArithmetic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(LongArithmetic src/main.cpp src/Digit.cpp src/Digit.h src/Number.cpp src/Number.h)
# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SimpleCalculatorProject VERSION 1.0)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the header files directory
include_directories(include)

# Add the executable for the Calculator implementation
add_library(calc src/calc.cpp)

# Add the directory containing the tests
add_subdirectory(test)

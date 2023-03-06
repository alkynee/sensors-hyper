# Check CMake version.
cmake_minimum_required(VERSION 3.16)

# Includes.
include(FetchContent)

# Define projects.
project(HyperSensors VERSION 23.01.19 DESCRIPTION "" HOMEPAGE_URL https://github.com/VIS4ROB-lab/HyperSensors LANGUAGES CXX)

# Set properties.
if (PROJECT_IS_TOP_LEVEL)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED YES)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -fconcepts -Wall -Wextra -Wnon-virtual-dtor -pedant
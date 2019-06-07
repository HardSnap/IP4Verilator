cmake_minimum_required(VERSION 2.8)

project(simulator_system)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX "/usr/local")

set (CMAKE_CXX_STANDARD 11)

include_directories("include")

add_subdirectory(lib)

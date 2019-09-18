# Only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# Project Name
project(DP)

# Set the C++14 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER clang++)
add_compile_options(-Wall)

# I../includes
include_directories(.)

add_subdirectory (Lib/DP)
add_subdirectory (Lib/GridWorld)

# Executable for PolicyEvaluation
add_executable (PolicyEvaluation PolicyEvaluation.cpp)
target_link_libraries (PolicyEvaluation DP)
target_link_libraries (PolicyEvaluation GridWorld)

# Executable for PolicyIteration

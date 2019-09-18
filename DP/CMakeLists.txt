# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(DP)

# creates the variable EXEC and sets it to hello
set(EXEC PolicyEvaluation)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# I../includes
include_directories(.)

add_subdirectory (Lib/DP)
add_subdirectory (Lib/GridWorld)

# add the executable
add_executable (${EXEC} PolicyEvaluation.cpp)
target_link_libraries (${EXEC} DP)
target_link_libraries (${EXEC} GridWorld)


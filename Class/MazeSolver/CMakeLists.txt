cmake_minimum_required(VERSION 3.10)

project(Maze)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Maze
    src/main.cpp
    src/MazeLoader.cpp
    src/Robot.cpp
)

target_include_directories(Maze PRIVATE include)

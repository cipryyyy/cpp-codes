cmake_minimum_required(VERSION 3.16)

project(Controller)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAZE_SOLVER_DIR ${CMAKE_SOURCE_DIR}/../../Class/MazeSolver)

include_directories(${MAZE_SOLVER_DIR}/include)

set(MAZE_SOLVER_SOURCES
    ${MAZE_SOLVER_DIR}/src/MazeLoader.cpp
    ${MAZE_SOLVER_DIR}/src/Robot.cpp
)

add_executable(Controller Controller.cpp)

target_sources(Controller PRIVATE ${MAZE_SOLVER_SOURCES})

find_library(NCURSES_LIBRARY ncurses)

if(NCURSES_LIBRARY)
    target_link_libraries(Controller ${NCURSES_LIBRARY})
else()
    message(FATAL_ERROR "ncurses library not found")
endif()

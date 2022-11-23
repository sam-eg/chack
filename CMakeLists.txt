cmake_minimum_required(VERSION 3.23)
project(chack)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(chack main.cpp Game.cpp Game.h Level.cpp Level.h Size.cpp Size.h Terminal.cpp Terminal.h Position.cpp Position.h)

target_link_libraries(chack ${CURSES_LIBRARIES})
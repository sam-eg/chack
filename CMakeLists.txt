cmake_minimum_required(VERSION 3.23)
project(chack)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(chack main.cpp Game.cpp Game.h Level.cpp Level.h Terminal.cpp Terminal.h objects/Player.cpp objects/Player.h Position.cpp Position.h Command.h objects/Object.cpp objects/Object.h objects/ObjectType.h objects/Wall.cpp objects/Wall.h objects/Goal.cpp objects/Goal.h screens/Title.cpp screens/Title.h screens/WinScreen.cpp screens/WinScreen.h screens/LoseScreen.cpp screens/LoseScreen.h objects/Obstacle.cpp objects/Obstacle.h objects/Key.cpp objects/Key.h objects/Door.cpp objects/Door.h objects/Coin.cpp objects/Coin.h objects/UpStairs.cpp objects/UpStairs.h objects/DownStairs.cpp objects/DownStairs.h objects/ActiveObject.cpp objects/ActiveObject.h objects/Bouncer.cpp objects/Bouncer.h objects/Rando.cpp objects/Rando.h)

target_link_libraries(chack ${CURSES_LIBRARIES})
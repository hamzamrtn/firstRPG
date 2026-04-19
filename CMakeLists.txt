cmake_minimum_required(VERSION 4.2)
project(myRPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myRPG main.cpp
        Character.cpp
        Character.h
        Weapon.cpp
        Weapon.h)

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

target_link_libraries(myRPG PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)
cmake_minimum_required(VERSION 3.28)
project(myRPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myRPG
        main.cpp
        character.cpp
        character.h
        weapon.cpp
        weapon.h
)

find_package(SFML 3.1 REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(myRPG PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
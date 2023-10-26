cmake_minimum_required(VERSION 3.26)
project(2048Console)

set(CMAKE_CXX_STANDARD 17)

add_executable(2048Console main.cpp
        class/Tile.cpp
        class/Tile.h
        class/Board.cpp
        class/Board.h
        includes.h
        game.cpp
        game.h)

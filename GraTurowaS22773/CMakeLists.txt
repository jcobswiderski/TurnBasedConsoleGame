cmake_minimum_required(VERSION 3.20)
project(GraTurowaS22773)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(GraTurowaS22773 main.cpp Creature.cpp Creature.h CreatureType.h)

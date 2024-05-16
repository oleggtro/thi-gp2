cmake_minimum_required(VERSION 3.28)
project(Praktikum1_1)

set(CMAKE_CXX_STANDARD 20)

include_directories("/opt/homebrew/Cellar/boost/1.85.0/include")

add_executable(Praktikum1_1
        ufo.cpp
        ufo.h
        ballistic.cpp
        ballistic.h
        vertical.h
        vertical.h
        vertical.cpp
        route.cpp
        route.h
        pa3_utest.cpp
        ufosim.h
        ufosim.cpp
)

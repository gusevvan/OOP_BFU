cmake_minimum_required(VERSION 3.26)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab7 main.cpp
        inc/irep.h
        inc/user.h
        src/user.cpp
        inc/mrep.h
        src/mrep.cpp
        src/irep.cpp
)

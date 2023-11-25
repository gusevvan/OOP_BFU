cmake_minimum_required(VERSION 3.25)
project(lab5)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab5 main.cpp controls.h form.h factories.h form.cpp controls.cpp factories.cpp)

cmake_minimum_required(VERSION 3.17)
project(a45_araulo22)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(a45_araulo22
        Movie.h Movie.cpp main.cpp DynamicVector.h DynamicVector.cpp Repository.h Repository.cpp AdminService.cpp AdminService.h UserService.h UserService.cpp UI.h UI.cpp Tests.h Tests.cpp)

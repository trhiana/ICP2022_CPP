cmake_minimum_required(VERSION 3.23)
project(ICP2022_CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ICP2022_CPP
        main.cpp main.h airports.cpp routes.cpp userData.cpp exceptions.h airlines.cpp)

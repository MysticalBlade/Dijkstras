cmake_minimum_required(VERSION 3.29)
project(Djikstra_s)

set(CMAKE_CXX_STANDARD 20)

add_executable(Djikstra_s main.cpp
        GraphBase.hpp
        Graph.cpp
        Graph.hpp)

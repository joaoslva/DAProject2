cmake_minimum_required(VERSION 3.24)
project(Projeto_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto_2 main.cpp data_reading/CvsReader.cpp data_reading/CvsReader.h Graph.cpp Graph.h NodeEdge.cpp NodeEdge.h menus/Menu.cpp menus/Menu.h menus/Menu.cpp menus/Menu.cpp)

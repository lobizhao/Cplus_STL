cmake_minimum_required(VERSION 3.28)
project(Cplus_STL)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cplus_STL main.cpp
        my_vector.h
        my_queue.h
        my_priority_quque.h
)

cmake_minimum_required(VERSION 3.10)
project(vect)

set(CMAKE_CXX_STANDARD 17)

add_executable(vect main.cpp vec.h nvec.h range.h const.h mx.h functors.h nvec.cpp container_stream.h rect.h reduce.h)
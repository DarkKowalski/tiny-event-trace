cmake_minimum_required(VERSION 3.20)
project(tiny_event_trace_test_simple VERSION 0.0.1)

include_directories(../include)

link_directories(../build)
link_libraries(tiny_event_trace)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -O3 -fno-fast-math -ggdb3")

add_executable(test_simple.out main.c another.c)

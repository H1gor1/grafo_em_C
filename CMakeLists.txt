cmake_minimum_required(VERSION 3.22)
project(graphs C)

set(CMAKE_C_STANDARD 11)

add_executable(graphs main.c graph.c graph.h graphVerifications.h graphVerifications.c)

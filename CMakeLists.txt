cmake_minimum_required(VERSION 3.0.0)
project(clox VERSION 0.1.0 LANGUAGES C)

add_executable(clox chunk.c main.c memory.c debug.c value.c)

include(CTest)
enable_testing()


cmake_minimum_required(VERSION 3.5.0)
project(clox VERSION 0.1.0 LANGUAGES C)

add_executable(clox chunk.c main.c memory.c debug.c value.c vm.c compiler.c scanner.c object.c table.c)

include(CTest)
enable_testing()

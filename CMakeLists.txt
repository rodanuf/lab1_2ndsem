cmake_minimum_required(VERSION 3.10)
project(lab1_2ndsem C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra")

file (GLOB SOURCES "sources/*.c")
file (GLOB HEADERS "headers/*.h")

include_directories(headers)

add_executable(lab1_2ndsem
    sources/controller.c 
    sources/errors.c
    sources/lab.c
    sources/matrix.c 
    sources/type_double.c 
    sources/type_int.c 
)

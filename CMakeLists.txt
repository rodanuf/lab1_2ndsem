cmake_minimum_required(VERSION 3.10)
project(lab1_2ndsem LANGUAGES C CXX)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--subsystem,console")
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GTEST_ROOT "C:/Libraries/gtest")
set(CMAKE_C_FLAGS "-Wall -Wextra")

file (GLOB SOURCES "sources/*.c")
file (GLOB HEADERS "headers/*.h")

add_subdirectory(
    "C:/w64devkit/googletest" 
    "${CMAKE_BINARY_DIR}/googletest-build"
)

include_directories("C:/w64devkit/googletest/googletest/include")

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(headers)

add_executable(lab1_2ndsem
    sources/controller.c 
    sources/errors.c
    sources/lab.c
    sources/matrix.c 
    sources/type_double.c 
    sources/type_int.c 
)
target_include_directories(lab1_2ndsem PRIVATE headers)

if(MINGW)
    set_target_properties(lab1_2ndsem PROPERTIES
        LINK_FLAGS "-Wl,--subsystem,console"
    )
endif()

add_executable(googletest
    sources/googletest.cpp
    sources/controller.c 
    sources/errors.c
    sources/matrix.c 
    sources/type_double.c 
    sources/type_int.c 
)

if(MINGW)
    set_target_properties(googletest PROPERTIES
        LINK_FLAGS "-Wl,--subsystem,console"
    )
endif()


target_link_libraries(googletest gtest gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND googletest)
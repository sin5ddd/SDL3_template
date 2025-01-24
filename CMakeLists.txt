cmake_minimum_required(VERSION 3.30)
project(SDL3_template)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

add_executable(SDL3_template WIN32 main.cpp
        AppMain.cpp
        AppMain.h)

target_link_libraries(SDL3_template PRIVATE SDL3::SDL3)
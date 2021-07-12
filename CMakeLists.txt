cmake_minimum_required(VERSION 3.19)
project(OS_Project)
set (EXE_NAME OS_Project)
include_directories(.)

set (input01 "processes.csv")

foreach(file IN LISTS input01)
        configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME}
        main.cpp
        kernel.h
        kernel.cpp
        pcb.h
        pcb.cpp
        pqueue.h
        pqueue.cpp)

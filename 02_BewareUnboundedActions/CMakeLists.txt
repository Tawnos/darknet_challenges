cmake_minimum_required(VERSION 3.10)

project(dcdn30_BewareUnboundedActions)

set(CMAKE_CXX_STANDARD 20)
set(MAIN_SOURCES
    src/main.cpp
    src/records.h
    src/records.cpp
)

add_executable(recordStore ${MAIN_SOURCES})

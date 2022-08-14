cmake_minimum_required(VERSION 3.10)

project(dcdn30_WhatTypeOfProblem)

set(CMAKE_CXX_STANDARD 20)

set(MAIN_SOURCES
    src/main.cpp
    src/messageProcessor.h
    src/messageProcessor.cpp
    src/messages.h
)

add_executable(messageProcessor ${MAIN_SOURCES})


configure_file(npcScripts/cmdc0de.txt cmdc0de.txt COPYONLY)
configure_file(npcScripts/gourry.txt gourry.txt COPYONLY)
configure_file(npcScripts/gulo.txt gulo.txt COPYONLY)
configure_file(npcScripts/flag.txt flag.txt COPYONLY)
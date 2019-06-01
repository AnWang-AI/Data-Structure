cmake_minimum_required(VERSION 3.14)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(DataStructure)

add_executable(DataStructure
        DataStructure/BST.c
        DataStructure/BST.h
        DataStructure/linklist.c
        DataStructure/linklist.h
        DataStructure/main.c
        DataStructure/queue.c
        DataStructure/queue.h
        DataStructure/stack.c
        DataStructure/stack.h)

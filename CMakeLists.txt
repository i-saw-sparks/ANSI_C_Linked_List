cmake_minimum_required(VERSION 3.15)
project(project1 C)

set(CMAKE_C_STANDARD 11)

add_executable(project1 main.c health_record.h health_record.c record_llist.c record_llist.h)
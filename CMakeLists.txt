cmake_minimum_required(VERSION 3.17)
project(project_03 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_03 file.c file.h array.c array.h main.c runtime_type.c runtime_type.h list.c list.h btree.c btree.h heap.c heap.h hashtable.c hashtable.h time/array_time.c time/array_time.h)
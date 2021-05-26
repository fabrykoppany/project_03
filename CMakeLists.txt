cmake_minimum_required(VERSION 3.17)
project(project_03 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_03 file.c file.h int_array.c int_array.h str_array.c str_array.h structures.h main.c runtime_type.c runtime_type.h list.c list.h btree.c btree.h heap.c heap.h hashtable.c hashtable.h)
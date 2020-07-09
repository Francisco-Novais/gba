cmake_minimum_required(VERSION 3.16)
project(template)

set(CMAKE_CXX_STANDARD 14)

add_executable(template
        source/template.c
        Makefile)

#include_directories(C:/devkitPro/libgba/include)
#include_directories(C:/devkitPro/libtonc/include)
include_directories(include)
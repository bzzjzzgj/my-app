cmake_minimum_required(VERSION 3.16)

project(MyApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) 

add_subdirectory(src/my.core)
add_subdirectory(src/my.maths)
add_subdirectory(src/my.tools)
add_subdirectory(src/my.debug)
add_subdirectory(src/my.windowing)
add_subdirectory(src/my.ui)
add_subdirectory(src/my.app)

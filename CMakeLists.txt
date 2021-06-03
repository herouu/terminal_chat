cmake_minimum_required(VERSION 3.19)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_executable(untitled3 main.cpp)
target_link_libraries(untitled3 ${CONAN_LIBS})
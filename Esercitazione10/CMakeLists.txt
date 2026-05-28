cmake_minimum_required(VERSION 3.20)
project(esercitazione10) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

find_package(Eigen3 REQUIRED)

add_executable(test_gc test_gc.cpp)

target_link_libraries(test_gc Eigen3::Eigen)

add_test(NAME test_gc COMMAND test_gc)

enable_testing()


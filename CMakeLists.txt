cmake_minimum_required(VERSION 3.15)
project(number_guesser)

set(CMAKE_CXX_STANDARD 20)

add_executable(number_guesser main.cpp word.cpp word.h generator.cpp generator.h)
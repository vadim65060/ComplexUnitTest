cmake_minimum_required(VERSION 3.23)
project(ComplexUnitTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComplexUnitTest main.cpp Complex.h ComplexTest.cpp ComplexTest.h)

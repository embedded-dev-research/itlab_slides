cmake_minimum_required(VERSION 3.16)
project(HelloCMake LANGUAGES CXX)

add_executable(hello src/main.cpp)
target_compile_features(hello PRIVATE cxx_std_20)


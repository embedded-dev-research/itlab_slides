cmake_minimum_required(VERSION 3.16)
project(DepsFmt LANGUAGES CXX)

add_library(add src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(add PUBLIC cxx_std_20)

find_package(fmt CONFIG REQUIRED)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add fmt::fmt)


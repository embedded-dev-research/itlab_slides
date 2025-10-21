cmake_minimum_required(VERSION 3.16)
project(LibExample LANGUAGES CXX)

add_library(add lib/src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add)
target_compile_features(app PRIVATE cxx_std_20)


cmake_minimum_required(VERSION 3.16)
project(VisualStudioTips LANGUAGES CXX)

add_executable(app src/main.cpp)
target_compile_features(app PRIVATE cxx_std_20)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)


cmake_minimum_required(VERSION 3.16)
project(WithTests LANGUAGES CXX)

add_library(add src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(add PUBLIC cxx_std_20)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
  FetchContent_MakeAvailable(googletest)
  add_executable(app_tests tests/tests.cpp)
  target_link_libraries(app_tests PRIVATE add gtest_main)
  include(GoogleTest)
  gtest_discover_tests(app_tests)
endif()


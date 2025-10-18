cmake_minimum_required(VERSION 3.16)
project(TargetBased LANGUAGES CXX)

add_library(add src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(add PUBLIC cxx_std_20)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add)
target_compile_options(app PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
                                     $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>)


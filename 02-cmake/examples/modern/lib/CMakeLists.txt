add_library(add src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(add PUBLIC cxx_std_20)


cmake_minimum_required(VERSION 3.16)
project(InstallPack LANGUAGES CXX)

add_library(add src/add.cpp)
target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(add PUBLIC cxx_std_20)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add)

install(TARGETS app add EXPORT packTargets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT packTargets NAMESPACE pack:: DESTINATION lib/cmake/pack)

include(CPack)


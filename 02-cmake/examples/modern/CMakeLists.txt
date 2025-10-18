cmake_minimum_required(VERSION 3.16)
project(ModernCMakeExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build unit tests" ON)

add_subdirectory(lib)
add_subdirectory(src)

if(BUILD_TESTS)
  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  FetchContent_MakeAvailable(googletest)
  add_subdirectory(tests)
endif()

install(TARGETS app add EXPORT modernTargets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
)
install(DIRECTORY lib/include/ DESTINATION include)
install(EXPORT modernTargets NAMESPACE modern:: DESTINATION lib/cmake/modern)

include(CPack)


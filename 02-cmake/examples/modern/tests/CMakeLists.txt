add_executable(app_tests tests.cpp)
target_link_libraries(app_tests PRIVATE add gtest_main)

include(GoogleTest)
gtest_discover_tests(app_tests)


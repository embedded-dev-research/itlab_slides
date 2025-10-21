add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE add)
target_compile_features(app PRIVATE cxx_std_20)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)


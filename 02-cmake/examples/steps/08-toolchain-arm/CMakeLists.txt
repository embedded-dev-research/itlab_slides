cmake_minimum_required(VERSION 3.16)
project(ArmToolchainDemo C CXX)

add_executable(app src/main.cpp)
target_compile_features(app PRIVATE cxx_std_20)


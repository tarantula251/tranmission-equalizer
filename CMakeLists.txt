cmake_minimum_required(VERSION 3.14)
project(tranmission_equalizer)

set(CMAKE_CXX_STANDARD 14)

add_executable(tranmission_equalizer src/main.cpp src/encrypter/Encrypter.cpp include/encrypter/Encrypter.hpp)
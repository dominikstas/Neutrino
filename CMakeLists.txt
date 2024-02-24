cmake_minimum_required(VERSION 3.10)

project(Neutrino)

set(CMAKE_CXX_STANDARD 11)

add_executable(Neutrino Terminal/terminal.cpp Terminal/commands.cpp)

target_compile_features(Neutrino PRIVATE cxx_std_17)

cmake_minimum_required(VERSION 3.15)
project(SeirChain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Config)
add_subdirectory(Core)
add_subdirectory(Network)
add_subdirectory(Interface)
add_subdirectory(Tests)

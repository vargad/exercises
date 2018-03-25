cmake_minimum_required(VERSION 2.8)
project(elementary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(say-history "say-history.cpp")
add_executable(correct-sentence "correct-sentence.cpp")
add_executable(first-word "first-word")
add_executable(second-index "second-index.cpp")

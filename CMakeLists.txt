cmake_minimum_required(VERSION 3.1...3.18)

project(
  Webn't
  VERSION 0.1
  DESCRIPTION "A web brwoser 'from scratch' attempt"
  LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
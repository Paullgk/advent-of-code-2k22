# Based on https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html


# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.15...4.0)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  AdventOfCode2k22
  VERSION 1.0
  LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(src)

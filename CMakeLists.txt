# Based on
# https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html
# and https://stackoverflow.com/questions/62910867/how-to-run-tests-and-debug-google-test-project-in-vs-code


# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.15...4.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GOOGLETEST_VERSION 1.17.0)
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)
include(GoogleTest)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  AdventOfCode2k22
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(src)

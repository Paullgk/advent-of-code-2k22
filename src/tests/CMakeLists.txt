# Create a sources variable with a link to all cpp files to compile
if(BUILD_TESTING)
set(SOURCES
    day1_tests.cpp
    ../day1/day1.cpp
    ../day1/elf.cpp
)

add_executable(day1_tests ${SOURCES})
target_link_libraries(day1_tests PRIVATE gtest tools)
gtest_discover_tests(day1_tests)
target_include_directories(day1_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
endif()

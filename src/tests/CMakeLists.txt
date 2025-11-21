# Create a sources variable with a link to all cpp files to compile
if(BUILD_TESTING)
set(SOURCES
    tests.cpp
    ../day1/day1.cpp
    ../day1/elf.cpp
)

add_executable(tests ${SOURCES})
target_link_libraries(tests PRIVATE gtest tools)
gtest_discover_tests(tests)
target_include_directories(tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
endif()

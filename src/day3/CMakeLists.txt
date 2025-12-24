# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    day3.cpp
    main.cpp
)

add_executable(day3 ${SOURCES})

target_include_directories(day3
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(day3
    PRIVATE
        tools
)

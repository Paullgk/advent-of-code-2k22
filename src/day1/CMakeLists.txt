# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    day1.cpp
    elf.cpp
    main.cpp
)

add_executable(day1 ${SOURCES})

target_include_directories(day1
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(day1
    PRIVATE
        tools
)

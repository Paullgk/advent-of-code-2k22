# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    day2.cpp
    main.cpp
    player.cpp
)

add_executable(day2 ${SOURCES})

target_include_directories(day2
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(day2
    PRIVATE
        tools
)

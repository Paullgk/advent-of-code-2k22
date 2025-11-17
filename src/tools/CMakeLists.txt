# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    tools.cpp
)

add_library(tools STATIC ${SOURCES})

target_include_directories(tools
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

cmake_minimum_required(VERSION 3.20)
project(TextEditor VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(MSVC)
    add_compile_options(/W4)
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files
set(CORE_SOURCES
    src/file/FileManager.cpp
)

# Header files
set(CORE_HEADERS
    include/file/FileManager.h
)

# Create static library
add_library(texteditor_core STATIC ${CORE_SOURCES} ${CORE_HEADERS})

target_include_directories(texteditor_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable
add_executable(texteditor main.cpp)

target_link_libraries(texteditor PRIVATE texteditor_core)

# Installation rules
install(TARGETS texteditor texteditor_core
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include/texteditor
    FILES_MATCHING PATTERN "*.h"
)

# Print build info
message(STATUS "TextEditor Core Configuration:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID}")

# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(AddressBook VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output folder for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
set(SOURCES
    main.cpp
    AddressBook.cpp
    Contact.cpp
)

# Add executable target
add_executable(AddressBook ${SOURCES})

# Optional: compiler warnings (good practice)
if(MSVC)
    target_compile_options(AddressBook PRIVATE /W4 /permissive-)
else()
    target_compile_options(AddressBook PRIVATE -Wall -Wextra -Wpedantic)
endif()

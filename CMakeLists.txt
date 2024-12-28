# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(MyProject VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Directories for source and header files
set(SRC_DIR src)
set(TEST_DIR tests)
set(INCLUDE_DIR include)

# Add the include directory to the search path
include_directories(${INCLUDE_DIR})

# Collect source and test files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")
file(GLOB TEST_FILES "${TEST_DIR}/*.cpp")

# Build the test executable
add_executable(runTests ${SRC_FILES} ${TEST_FILES})

# Add warning flags for better code quality
target_compile_options(runTests PRIVATE -Wall -Wextra -Werror -pedantic)

# Enable testing
enable_testing()

# Add a test to verify successful execution
add_test(NAME RunAllTests COMMAND runTests)

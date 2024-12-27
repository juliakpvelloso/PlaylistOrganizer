cmake_minimum_required(VERSION 3.10)
project(PlaylistOrganizer)

# Include directories
include_directories(include)

# Add Google Test
add_subdirectory(third_party/googletest)

# Enable testing
enable_testing()

# Add the test executable
add_executable(runTests tests/song_tests.cpp src/song.cpp)
target_link_libraries(runTests gtest gtest_main pthread)

# Register tests
add_test(NAME runTests COMMAND runTests)

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Ithird_party/googletest/googletest/include -Wall -Wextra -pthread

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
GTEST_DIR = third_party/googletest

# Files
TARGET = runTests
SOURCES = $(wildcard $(SRC_DIR)/*.cpp $(TEST_DIR)/*.cpp)
OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Google Test sources
GTEST_SRCS = $(GTEST_DIR)/googletest/src/gtest-all.cc
GTEST_OBJS = $(patsubst %.cc, $(BUILD_DIR)/%.o, $(GTEST_SRCS))

# Rules
all: $(TARGET)

# Create the target executable
$(TARGET): $(OBJECTS) $(GTEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -pthread

# Compile source and test files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest/include -I$(GTEST_DIR) -c $< -o $@

# Clean build directory and target
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

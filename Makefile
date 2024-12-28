# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -pthread

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Files
TEST_TARGET = runTests
MAIN_TARGET = playlist
MAIN_SOURCE = main.cpp
MAIN_OBJECT = $(BUILD_DIR)/$(MAIN_SOURCE:.cpp=.o)
TEST_SOURCES = $(wildcard $(SRC_DIR)/*.cpp $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(TEST_SOURCES))
MAIN_OBJECTS = $(filter-out $(BUILD_DIR)/$(MAIN_SOURCE:.cpp=.o), $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)))

# Rules
all: $(TEST_TARGET) $(MAIN_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -Wl,-e,__Z12runTestsMainv

$(MAIN_TARGET): $(MAIN_OBJECT) $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TEST_TARGET) $(MAIN_TARGET)

.PHONY: all clean

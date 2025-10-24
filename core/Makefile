CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2
INCLUDES = -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin

# Target executable
TARGET = $(BIN_DIR)/texteditor

# Source files
SOURCES = $(SRC_DIR)/file/FileManager.cpp \
          main.cpp

# Object files
OBJECTS = $(OBJ_DIR)/FileManager.o \
          $(OBJ_DIR)/main.o

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile FileManager.cpp
$(OBJ_DIR)/FileManager.o: $(SRC_DIR)/file/FileManager.cpp include/file/FileManager.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRC_DIR)/file/FileManager.cpp -o $(OBJ_DIR)/FileManager.o

# Compile main.cpp
$(OBJ_DIR)/main.o: main.cpp include/file/FileManager.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp -o $(OBJ_DIR)/main.o

# Clean build artifacts
clean:
	rm -rf build/

# Run the program
run: $(TARGET)
	$(TARGET)

# Rebuild
rebuild: clean all

.PHONY: all clean run rebuild directories

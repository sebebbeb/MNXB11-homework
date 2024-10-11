CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -Wall -Wextra -Werror # Change to c++17, c++20, etc. and flags as needed

SRC_DIR = src
OBJ_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cxx)  # Includes all .cxx files from src
# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cxx, $(OBJ_DIR)/%.o, $(SRCS))

# Output executable
EXEC = main

all: $(EXEC)

# Link objects and create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cxx
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

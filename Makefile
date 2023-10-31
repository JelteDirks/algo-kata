# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I /opt/homebrew/Cellar/check/0.15.2/include -g -Wall

# Library paths
LDFLAGS = -L /opt/homebrew/Cellar/check/0.15.2/lib

# Source files directory
SRC_DIR = src

# Test files directory
TEST_DIR = tests

# Object files directory
OBJ_DIR = obj

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Test files and executables
TEST_FILES = $(wildcard $(TEST_DIR)/*_test.c)
TEST_EXECS = $(patsubst %.c,%,$(TEST_FILES))

.PHONY: all test clean

all: $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

test: $(TEST_EXECS)

$(TEST_EXECS): % : %.c $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -lcheck

clean:
	rm -rf $(OBJ_DIR) $(TEST_EXECS) tests/*.dSYM

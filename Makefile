# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I /opt/homebrew/Cellar/check/0.15.2/include -g -Wall

# Library paths
LDFLAGS = -L /opt/homebrew/Cellar/check/0.15.2/lib

# Source and object files
SRC = src/stack.c
OBJ = stack.o

# Test files
TEST = tests/stack_test.c

# Test executable name
TEST_EXEC = stack_test

all:
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

test: all
	$(CC) $(CFLAGS) $(OBJ) $(TEST) -o $(TEST_EXEC) $(LDFLAGS) -lcheck

clean:
	rm -f $(OBJ) $(TEST_EXEC)

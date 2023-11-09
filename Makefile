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

.PHONY: all test clean stack queue

all: stack queue linkedlist

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

linkedlist: $(OBJ_DIR)/linkedlist.o $(TEST_DIR)/linkedlist_test.c
	$(CC) $(CFLAGS) $(TEST_DIR)/linkedlist_test.c $(OBJ_DIR)/linkedlist.o -o $(TEST_DIR)/linkedlist_test $(LDFLAGS) -lcheck

binsearch: $(OBJ_DIR)/binsearch.o $(TEST_DIR)/binsearch_test.c
	$(CC) $(CFLAGS) $(TEST_DIR)/binsearch_test.c $(OBJ_DIR)/binsearch.o -o $(TEST_DIR)/binsearch_test $(LDFLAGS) -lcheck

minheap: $(OBJ_DIR)/minheap.o $(TEST_DIR)/minheap_test.c
	$(CC) $(CFLAGS) $(TEST_DIR)/minheap_test.c $(OBJ_DIR)/minheap.o -o $(TEST_DIR)/minheap_test $(LDFLAGS) -lcheck

stack: $(OBJ_DIR)/stack.o $(TEST_DIR)/stack_test.c
	$(CC) $(CFLAGS) $(TEST_DIR)/stack_test.c $(OBJ_DIR)/stack.o -o $(TEST_DIR)/stack_test $(LDFLAGS) -lcheck

queue: $(OBJ_DIR)/queue.o $(TEST_DIR)/queue_test.c
	$(CC) $(CFLAGS) $(TEST_DIR)/queue_test.c $(OBJ_DIR)/queue.o -o $(TEST_DIR)/queue_test $(LDFLAGS) -lcheck

clean:
	rm -rf $(OBJ_DIR) $(TEST_EXECS) tests/*.dSYM
	rm ${TEST_DIR}/*_test

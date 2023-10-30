#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct Stack *stack, int data) {}

int pop(struct Stack *stack) { return 0; }

int peek(struct Stack *stack) { return 0; }

int main(int argc, char *argv[]) {
  char *buf = malloc(128 * sizeof(char));

  for (int i = 0; i < argc; i++) {
    sprintf(buf, "%s\n", argv[i]);
    fprintf(stdout, "%s", buf);
  }
}

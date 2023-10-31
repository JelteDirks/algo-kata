#include "stack.h"
#include <stdlib.h>

struct Stack *make_stack(void) {
  struct Stack *s = malloc(sizeof(struct Stack));
  return s;
}

void push(struct Stack *stack, int data) {}

int pop(struct Stack *stack) { return 0; }

int peek(struct Stack *stack) { return 0; }

void free_stack(struct Stack *stack) {
  free(stack);
}

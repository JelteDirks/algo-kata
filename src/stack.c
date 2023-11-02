#include "stack.h"
#include <stdlib.h>

struct Stack *make_stack(void) {
  struct Stack *s = malloc(sizeof(struct Stack));
  s->size = 0;
  s->capacity = 0;
  s->internal = malloc(s->capacity * sizeof(int));
  return s;
}

void push(struct Stack *stack, int data) {
  int size = stack->size;
  int cap = stack->capacity;

  if (size + 1 > cap) {
    long new_cap = 1 + cap * 2;
    stack->internal = realloc(stack->internal, new_cap * sizeof(int));
    stack->capacity = new_cap;
  }

  stack->size += 1;
  stack->internal[stack->size - 1] = data;
}

int pop(struct Stack *stack, int *value) {
  if (stack->size > 0) {
    int data = stack->internal[stack->size - 1];
    *value = data;
    stack->size -= 1;
    return 0;
  }
  return 1;
}

int peek(struct Stack *stack, int *value) {
  if (stack->size > 0) {
    *value = stack->internal[stack->size - 1];
    return 0;
  }
  return 1;
}

void free_stack(struct Stack *stack) {
  free(stack->internal);
  free(stack);
}

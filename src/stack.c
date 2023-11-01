#include "stack.h"
#include <stdlib.h>

struct Stack *make_stack(void) {
  struct Stack *s = malloc(sizeof(struct Stack));
  s->size = 0;
  s->capacity = 20;
  s->internal = malloc(s->capacity * sizeof(int));
  return s;
}

void push(struct Stack *stack, int data) {
  int size = stack->size;
  int cap = stack->capacity;

  if (size + 1 > cap) {
    int new_cap = cap * 2 * sizeof(int);
    stack->internal = realloc(stack->internal, new_cap);
    stack->capacity = new_cap;
  }

  stack->size += 1;
  stack->internal[stack->size] = data;
}

int pop(struct Stack *stack) {
  if (stack->size > 0) {
    int data = stack->internal[stack->size];
    stack->size -= 1;
    return data;
  }
  return (int)NULL;
}

int peek(struct Stack *stack) {
  if (stack->size == 0) {
    return (int)NULL;
  }
  return stack->internal[stack->size];
}

void free_stack(struct Stack *stack) {
  free(stack->internal);
  free(stack);
}

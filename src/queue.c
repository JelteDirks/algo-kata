#include "../src/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_information(struct Queue *q) {
  fprintf(stderr, "capacity:%d\n", q->capacity);
  fprintf(stderr, "size:%d\n", q->size);
  fprintf(stderr, "head:%d\n", q->head);
  fprintf(stderr, "tail:%d\n", q->tail);
  fprintf(stderr, "content:\n");
  for (int a = 0; a < q->capacity; a++) {
    fprintf(stderr, "\t[%d]:%d\n", a, q->internal[a]);
  }
}

struct Queue *make_queue(int initial_capacity) {
  struct Queue *q = malloc(sizeof(struct Queue));
  q->size = 0;
  q->capacity = initial_capacity;
  q->head = 0;
  q->tail = 0;
  q->internal = malloc(q->capacity * sizeof(int));
  return q;
}

void free_queue(struct Queue *q) {
  free(q->internal);
  free(q);
}

int *grow(struct Queue *q) {
  fprintf(stderr, "pre grow:\n");
  print_information(q);
  int old_capacity = q->capacity;
  int new_capacity = 1 + (q->capacity * 2);
  int *new_ptr = realloc(q->internal, new_capacity * sizeof(int));

  if (new_ptr == NULL) {
    return new_ptr;
  }

  if (q->head <= q->tail) {
    memmove(new_ptr + old_capacity, new_ptr, q->head * sizeof(int));
    q->head = q->head + old_capacity;
  }

  q->internal = new_ptr;
  q->capacity = new_capacity;

  fprintf(stderr, "post grow:\n");
  print_information(q);
  return new_ptr;
}

void enqueue(struct Queue *q, int data) {
  fprintf(stderr, "== start enqueue %d ==\n", data);
  if (q->size == q->capacity) {
    grow(q);
  }

  q->size += 1;
  q->internal[q->head] = data;
  q->head = (q->head + 1) % q->capacity;
  fprintf(stderr, "== after queue update ==\n");
  print_information(q);
  fprintf(stderr, "== end enqueue %d ==\n", data);
}

int dequeue(struct Queue *q, int *data) {
  if (q->size > 0) {
    *data = q->internal[q->tail];
    q->internal[q->tail] = 77;
    q->tail = (q->tail + 1) % q->capacity;
    q->size -= 1;
    fprintf(stderr, "== after dequeue %d ==\n", *data);
    print_information(q);
    return 0;
  }
  return 1;
}

int peek(struct Queue *q, int *data) {
  if (q->size > 0) {
    *data = q->internal[q->tail];
    return 0;
  }
  return 1;
}

#include "../src/queue.h"
#include <stdlib.h>

struct Queue *make_queue() {
  struct Queue *q = malloc(sizeof(struct Queue));
  q->size = 0;
  q->capacity = 0;
  q->internal = malloc(q->capacity * sizeof(int));
  return q;
}

void free_queue(struct Queue *q) {
  free(q->internal);
  free(q);
}

void enqueue(struct Queue *q, int data) {}

int dequeue(struct Queue *q, int *data) { return 1; }

int peek(struct Queue *q, int *data) { return 1; }

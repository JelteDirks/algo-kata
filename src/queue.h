#include <stdio.h>
struct Queue {
  int size;

  // -->
  int *internal;
  int capacity;
  int head;
  int tail;
  // <--
};

struct Queue *make_queue(int initial_capacity);
void free_queue(struct Queue *q);
void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q, int *data);
int peek(struct Queue *q, int *data);
void print_information(struct Queue *q);

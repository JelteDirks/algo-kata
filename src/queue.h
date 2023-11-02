struct Queue {
  int size;

  // -->
  int *internal;
  int capacity;
  // <--
};

struct Queue *make_queue();
void free_queue(struct Queue *q);
void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q, int *data);
int peek(struct Queue *q, int *data);

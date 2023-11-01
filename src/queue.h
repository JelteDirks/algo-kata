struct Queue {
  int size;
};

struct Queue *make_queue();
void free_queue(struct Queue *q);
void enqueue(struct Queue *q, int data);
int *dequeue(struct Queue *q);
int *peek(struct Queue *q);

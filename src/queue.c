#include "../src/queue.h"
#include <stdlib.h>

struct Queue *make_queue() {
  struct Queue *q = {0};
  return q;
}

void free_queue(struct Queue *q) { free(q); }

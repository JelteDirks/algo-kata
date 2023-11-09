#include "../src/minheap.h"
#include <stdlib.h>

struct MinHeap *make_minheap() {
  struct MinHeap *heap = {0};
  return heap;
}
void free_minheap(struct MinHeap *heap) { free(heap); }

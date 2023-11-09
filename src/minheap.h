#include <stdio.h>

struct MinHeap {
  int size;
};

struct MinHeap * make_minheap();
void free_minheap(struct MinHeap *heap);

#include <stdio.h>

struct MinHeap {
  int size;
  int capacity;
  int *internal;
};

struct MinHeap *make_minheap(int size);
void free_minheap(struct MinHeap *heap);
void insert(struct MinHeap *heap, int value);
int extract_min(struct MinHeap *heap);
int parent(struct MinHeap *heap, int index);
int left_child(struct MinHeap *heap, int index);
int right_child(struct MinHeap *heap, int index);
void grow(struct MinHeap *heap);
void heap_up(struct MinHeap *heap, int index);
void heap_down(struct MinHeap *heap, int index);
void swap(struct MinHeap *heap, int pos_a, int pos_b);

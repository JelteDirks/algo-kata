#include "../src/minheap.h"
#include <stdlib.h>

struct MinHeap *make_minheap(int capacity) {
  struct MinHeap *heap = malloc(sizeof(struct MinHeap));

  heap->capacity = capacity;
  heap->size = 0;
  heap->internal = malloc(capacity * sizeof(int));

  return heap;
}

void insert(struct MinHeap *heap, int value) {
  if (heap->size == heap->capacity - 1) {
    grow(heap);
  }

  heap->internal[heap->size] = value;
  heap->size += 1;
  heap_up(heap, heap->size - 1);
}

int extract_min(struct MinHeap *heap) {
  swap(heap, 0, heap->size - 1);
  heap->size -= 1;
  heap_down(heap, 0);
  return heap->internal[heap->size];
}

void heap_up(struct MinHeap *heap, int index) {
  int cur = index;
  int par = parent(heap, index);

  while (cur != par) {
    int pv = heap->internal[par];
    int cv = heap->internal[cur];

    if (pv > cv) {
      swap(heap, par, cur);
    } else {
      break;
    }

    cur = par;
    par = parent(heap, cur);
  }
}

void heap_down(struct MinHeap *heap, int index) {
  int cur = index;
  int left = left_child(heap, cur);
  int right = right_child(heap, cur);

  while (left < heap->size) {
    int lv = heap->internal[left];
    int cv = heap->internal[cur];
    int smallest = cur;

    if (lv < cv) {
      smallest = left;
    }

    if (right < heap->size) {
      int rv = heap->internal[right];
      if (rv < cv && rv < lv) {
        smallest = right;
      }
    }

    if (smallest == cur) {
      break;
    }

    swap(heap, smallest, cur);
    cur = smallest;
    left = left_child(heap, cur);
    right = right_child(heap, cur);
  }
}

void grow(struct MinHeap *heap) {
  int new_capacity = heap->capacity * 2;
  int *p = realloc(heap->internal, new_capacity * sizeof(int));
  if (p != NULL) {
    heap->internal = p;
    heap->capacity = new_capacity;
  }
}

void swap(struct MinHeap *heap, int pos_a, int pos_b) {
  int old_a = heap->internal[pos_a];
  heap->internal[pos_a] = heap->internal[pos_b];
  heap->internal[pos_b] = old_a;
}

int right_child(struct MinHeap *heap, int index) { return (index * 2) + 2; }

int left_child(struct MinHeap *heap, int index) { return (index * 2) + 1; }

int parent(struct MinHeap *heap, int index) { return (index - 1) / 2; };

void free_minheap(struct MinHeap *heap) {
  free(heap->internal);
  free(heap);
}

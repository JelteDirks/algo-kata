#include "binsearch.h"

int recursive_bin_search(int *arr, int l, int r, int data) {
  int mid = (l + r) / 2;

  if (r < l) {
    return 0;
  }

  if (data == arr[mid]) {
    return 1;
  }

  if (data < arr[mid]) {
    return recursive_bin_search(arr, l, mid - 1, data);
  }

  if (data > arr[mid]) {
    return recursive_bin_search(arr, mid + 1, r, data);
  }

  return 0;
}

int iterative_bin_search(int *arr, int size, int data) {
  int l = 0;
  int r = size - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (data == arr[mid]) {
      return 1;
    }

    if (data < arr[mid]) {
      r = mid - 1;
      continue;
    }

    if (data > arr[mid]) {
      l = mid + 1;
      continue;
    }
  }

  return 0;
}

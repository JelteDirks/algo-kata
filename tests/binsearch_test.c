#include "../src/binsearch.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  int aa = *((int *)a);
  int bb = *((int *)b);

  if (aa > bb)
    return 1;
  if (bb > aa)
    return -1;
  return 0;
}

int size;
int *data_array;
int values[] = {3, 4902, 444444, 853892};

void setup() {
  size = pow(10, 8);
  data_array = malloc(size * sizeof(int));

  fprintf(stderr, "size of array %d\n", size);
  fprintf(stderr, "max random value: %d\n", RAND_MAX);

  for (int i = 0; i < size; i++) {
    int randy = random();
    data_array[i] = (randy * 23 + 11) % size;
  }

  for (int j = 0; j < (sizeof(values) / sizeof(int)); j++) {
    int index = random() % size;
    data_array[index] = values[j];
  }

  fprintf(stderr, "array seeded, sorting now...\n");

  qsort(data_array, size, sizeof(int), comp);

  fprintf(stderr, "finished setup\n");
}

void teardown() { free(data_array); }

// Test case
START_TEST(test_binsearch) {
  int result;

  for (int i = 0; i < (sizeof(values) / sizeof(int)); i++) {
    result = iterative_bin_search(data_array, size, values[i]);
    ck_assert_int_eq(result, 1);
    result = recursive_bin_search(data_array, 0, size - 1, values[i]);
    ck_assert_int_eq(result, 1);
  }

  result = iterative_bin_search(data_array, size, size + 1);
  ck_assert_int_eq(result, 0);
  result = recursive_bin_search(data_array, 0, size - 1, size + 1);
  ck_assert_int_eq(result, 0);
}
END_TEST

// Test suite
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Binary Search");

  tc_core = tcase_create("Core");

  tcase_add_unchecked_fixture(tc_core, setup, teardown);

  tcase_add_test(tc_core, test_binsearch);
  suite_add_tcase(s, tc_core);

  return s;
}

// Main function
int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = add_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

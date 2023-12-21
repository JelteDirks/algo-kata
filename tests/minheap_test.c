#include "../src/minheap.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

// Test case
START_TEST(test_minheap) {
  struct MinHeap *h = make_minheap(10);

  insert(h, 2);
  insert(h, 4);
  insert(h, 6);
  insert(h, 3);
  insert(h, 5);

  ck_assert_int_eq(h->size, 5);

  ck_assert_int_eq(extract_min(h), 2);
  ck_assert_int_eq(extract_min(h), 3);
  ck_assert_int_eq(extract_min(h), 4);
  ck_assert_int_eq(extract_min(h), 5);

  ck_assert_int_eq(h->size, 1);

  ck_assert_int_eq(extract_min(h), 6);

  ck_assert_int_eq(h->size, 0);

  insert(h, 100);
  insert(h, 20);
  extract_min(h);
  insert(h, 40);
  insert(h, 80);
  insert(h, 80);
  insert(h, 80);
  extract_min(h);

  ck_assert_int_eq(extract_min(h), 80);
  ck_assert_int_eq(extract_min(h), 80);
  ck_assert_int_eq(extract_min(h), 80);
  ck_assert_int_eq(extract_min(h), 100);

  ck_assert_int_eq(h->size, 0);

  int n = pow(2, 20);

  for (int i = 0; i < n; i++) {
    int x_rand = random();
    insert(h, x_rand);
  }

  ck_assert_int_eq(h->size, n);

  int comp_arr[n];

  for (int i = 0; i < n; i++) {
    comp_arr[i] = extract_min(h);
  }

  for (int i = 1; i < n; i++) {
    int a = comp_arr[i - 1];
    int b = comp_arr[i];

    if (a != b) {
      ck_assert_int_lt(a, b);
    }
  }

  ck_assert_int_eq(h->size, 0);

  free_minheap(h);
}
END_TEST

// Test suite
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Min Heap");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_minheap);
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

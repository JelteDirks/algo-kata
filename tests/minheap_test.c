#include "../src/minheap.h"
#include <check.h>
#include <stdio.h>

// Test case
START_TEST(test_minheap) {
  struct MinHeap *h = make_minheap(10);

  insert(h, 2);
  insert(h, 3);
  insert(h, 4);
  insert(h, 5);
  insert(h, 6);

  ck_assert_int_eq(extract_min(h), 2);
  ck_assert_int_eq(extract_min(h), 3);
  ck_assert_int_eq(extract_min(h), 4);

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

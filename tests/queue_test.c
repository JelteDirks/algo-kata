#include "../src/queue.h"
#include <check.h>

// Test case
START_TEST(test_queue) {
  struct Queue *q = make_queue();

  free_queue(q);
}
END_TEST

// Test suite
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Queue");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_queue);
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

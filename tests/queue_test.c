#include "../src/queue.h"
#include <check.h>
#include <stdio.h>

// Test case
START_TEST(test_queue) {
  struct Queue *q = make_queue(1);
  int data = -1;
  int result = -1;

  enqueue(q, 33);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 33);
  ck_assert_int_eq(result, 0);

  enqueue(q, 99);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 99);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(q->capacity, 1);

  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);

  ck_assert_int_eq(q->capacity, 3);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 2);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 3);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 4);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(result, 1);

  enqueue(q, 10);
  enqueue(q, 11);
  enqueue(q, 12);
  enqueue(q, 13);
  enqueue(q, 14);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 10);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 11);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 12);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 13);
  ck_assert_int_eq(result, 0);

  result = dequeue(q, &data);
  ck_assert_int_eq(data, 14);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(q->size, 0);

  for (int i = 0; i < 1000; i++) {
    enqueue(q, i);
  }

  ck_assert_int_eq(q->size, 1000);

  for (int j = 0; j < 1000; j++) {
    result = dequeue(q, &data);
    ck_assert_int_eq(data, j);
    ck_assert_int_eq(result, 0);
  }

  ck_assert_int_eq(q->size, 0);

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

#include "../src/stack.h"
#include <check.h>

// Test case
START_TEST(test_stack) {
  struct Stack *s = make_stack();
  int data = -1;
  int result;

  push(s, 10);
  result = peek(s, &data);
  ck_assert_int_eq(data, 10);
  ck_assert_int_eq(result, 0);

  push(s, 11);
  result = peek(s, &data);
  ck_assert_int_eq(data, 11);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(s->size, 2);

  result = pop(s, &data);
  ck_assert_int_eq(data, 11);
  ck_assert_int_eq(result, 0);

  result = pop(s, &data);
  ck_assert_int_eq(data, 10);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(s->size, 0);

  push(s, 3);
  result = peek(s, &data);
  ck_assert_int_eq(data, 3);
  ck_assert_int_eq(result, 0);

  push(s, 4);
  push(s, 5);
  push(s, 6);
  push(s, 7);

  ck_assert_int_eq(s->size, 5);

  result = pop(s, &data);
  ck_assert_int_eq(data, 7);
  ck_assert_int_eq(result, 0);

  result = pop(s, &data);
  ck_assert_int_eq(data, 6);
  ck_assert_int_eq(result, 0);

  result = pop(s, &data);
  ck_assert_int_eq(data, 5);
  ck_assert_int_eq(result, 0);

  result = pop(s, &data);
  ck_assert_int_eq(data, 4);
  ck_assert_int_eq(result, 0);

  result = pop(s, &data);
  ck_assert_int_eq(data, 3);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(s->size, 0);

  result = pop(s, &data);
  ck_assert_int_eq(result, 1);

  result = pop(s, &data);
  ck_assert_int_eq(result, 1);

  ck_assert_int_eq(s->size, 0);

  push(s, 1);
  result = peek(s, &data);
  ck_assert_int_eq(data, 1);
  ck_assert_int_eq(result, 0);

  ck_assert_int_eq(s->size, 1);

  for (int i = 0; i < 1000; i++) {
    push(s, i);
  }

  ck_assert_int_eq(s->size, 1001);

  for (int i = 999; i >= 0; i--) {
    result = pop(s, &data);
    ck_assert_int_eq(data, i);
    ck_assert_int_eq(result, 0);
  }

  ck_assert_int_eq(s->size, 1);

  free_stack(s);
}
END_TEST

// Test suite
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Stack");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_stack);
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

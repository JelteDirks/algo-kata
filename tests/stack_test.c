#include "../src/stack.h"
#include <check.h>

// Test case
START_TEST(test_stack) {
  struct Stack *s = make_stack();

  push(s, 10);
  ck_assert_int_eq(peek(s), 10);
  push(s, 11);
  ck_assert_int_eq(peek(s), 11);

  ck_assert_int_eq(s->size, 2);

  ck_assert_int_eq(pop(s), 11);
  ck_assert_int_eq(pop(s), 10);

  ck_assert_int_eq(s->size, 0);

  push(s, 3);
  ck_assert_int_eq(peek(s), 3);

  push(s, 4);
  push(s, 5);
  push(s, 6);
  push(s, 7);

  ck_assert_int_eq(s->size, 5);

  ck_assert_int_eq(pop(s), 7);
  ck_assert_int_eq(pop(s), 6);
  ck_assert_int_eq(pop(s), 5);
  ck_assert_int_eq(pop(s), 4);
  ck_assert_int_eq(pop(s), 3);

  pop(s);
  pop(s);

  ck_assert_int_eq(s->size, 0);

  push(s, 1);
  ck_assert_int_eq(peek(s), 1);

  ck_assert_int_eq(s->size, 1);

  for (int i = 0; i < 1000; i++) {
    push(s, i);
  }

  ck_assert_int_eq(s->size, 1001);

  for (int i = 0; i < 1000; i++) {
    pop(s);
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

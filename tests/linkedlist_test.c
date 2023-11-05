#include "../src/linkedlist.h"
#include <check.h>
#include <stdio.h>

// Test case
START_TEST(test_linkedlist) {
  struct LinkedList *list = make_list();
  int data;
  int result;

  ck_assert_ptr_nonnull(list);
  ck_assert_ptr_null(list->head);

  prepend(list, 2);
  ck_assert_int_eq(list->size, 1);
  prepend(list, 3);
  ck_assert_int_eq(list->size, 2);

  ck_assert_str_eq(to_str(list), "3->2->NULL");

  append(list, 14);
  ck_assert_int_eq(list->size, 3);
  append(list, 15);
  ck_assert_int_eq(list->size, 4);

  ck_assert_str_eq(to_str(list), "3->2->14->15->NULL");

  result = head(list, &data);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(data, 3);

  result = tail(list, &data);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(data, 15);

  prepend(list, 23);
  append(list, 55);

  result = head(list, &data);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(data, 23);

  result = tail(list, &data);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(data, 55);

  free_list(list);
}
END_TEST

// Test suite
Suite *add_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("LinkedList");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_linkedlist);
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

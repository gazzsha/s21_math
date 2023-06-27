#include "s21_test.h"

START_TEST(test_s21_math_abs) {  // тесты s21_abs
  for (int i = -2147483647; i < -2147483600; i++) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
  for (int i = -21; i < 21; i++) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
  for (int i = 2147483600; i < 2147483647; i++) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }

  int testValue1 = -0.5;
  ck_assert_int_eq(s21_abs(testValue1), abs(testValue1));
}
END_TEST
Suite *s21_abs_suite() {
  Suite *s;
  TCase *tc_s21_abs;

  s = suite_create("s21_abs");
  tc_s21_abs = tcase_create("s21_abs");
  tcase_add_test(tc_s21_abs, test_s21_math_abs);
  suite_add_tcase(s, tc_s21_abs);
  

  return s;
}

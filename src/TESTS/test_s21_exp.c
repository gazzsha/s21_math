#include "s21_test.h"

START_TEST(test_s21_math_exp) {
  for (double i = 1.7E-308; i < 1.7E-307; i += 0.055) {
    ck_assert_int_eq(s21_exp(i), exp(i));
  }
  for (double i = -1.5; i < 1.5; i += 0.0055) {
    ck_assert_int_eq(s21_exp(i), exp(i));
  }
  for (double i = (1.7E+307) - 0.005; i < 1.7E+307; i += 0.005) {
    ck_assert_int_eq(s21_exp(i), exp(i));
  }

  double testValue1 = 0;
  double testValue2 = INFINITY;
  double testValue3 = -INFINITY;
  double testValue4 = -NAN;
  double testValue5 = NAN;

  ck_assert_ldouble_eq(s21_exp(testValue1), exp(testValue1));
  ck_assert_ldouble_eq(s21_exp(testValue2), exp(testValue2));
  ck_assert_ldouble_eq(s21_exp(testValue3), exp(testValue3));
  ck_assert(s21_is_nan(s21_exp(testValue4)) == s21_is_nan(exp(testValue4)));
  ck_assert(s21_is_nan(s21_exp(testValue5)) == s21_is_nan(exp(testValue5)));
}
END_TEST

Suite *s21_exp_suite() {
  Suite *s;
  TCase *tc_s21_exp;

  s = suite_create("s21_exp");
  tc_s21_exp = tcase_create("s21_exp");
  tcase_add_test(tc_s21_exp, test_s21_math_exp);
  suite_add_tcase(s, tc_s21_exp);

  return s;
}

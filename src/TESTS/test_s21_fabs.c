#include "s21_test.h"

START_TEST(test_s21_math_fabs) {
  for (double i = 1.7E-308; i < 1.7E-307; i += 0.055) {
    ck_assert_int_eq(s21_fabs(i), fabs(i));
  }
  for (double i = -1.5; i < 1.5; i += 0.0055) {
    ck_assert_int_eq(s21_fabs(i), fabs(i));
  }
  for (double i = (1.7E+307) - 0.005; i < 1.7E+307; i += 0.005) {
    ck_assert_int_eq(s21_fabs(i), fabs(i));
  }

  double testValue1 = 0;
  double testValue2 = INFINITY;
  double testValue3 = -INFINITY;
  double testValue4 = -NAN;
  double testValue5 = NAN;

  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
  ck_assert(s21_is_nan(s21_fabs(testValue4)) == s21_is_nan(fabs(testValue4)));
  ck_assert(s21_is_nan(s21_fabs(testValue5)) == s21_is_nan(fabs(testValue5)));
}
END_TEST
Suite *s21_fabs_suite() {
  Suite *s;
  TCase *tc_s21_fabs;

  s = suite_create("s21_fabs");
  tc_s21_fabs = tcase_create("s21_fabs");
  tcase_add_test(tc_s21_fabs, test_s21_math_fabs);
  suite_add_tcase(s, tc_s21_fabs);

  return s;
}

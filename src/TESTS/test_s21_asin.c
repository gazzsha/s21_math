#include "s21_test.h"

START_TEST(test_s21_math_asin) {
  for (double i = -1; i < 1; i += 0.3) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), 0.000001);
  }

  double testValue1 = 0;
  double testValue2 = 1;
  double testValue3 = 2 * 3.14;
  double testValue4 = -PI - 2;
  double testValue5 = -2 * 3.14;
  double testValue6 = PI * PI;
  double testValue7 = -1;
  double testValue8 = PI * 0.5;
  double testValue9 = -PI * 0.5;
  double testValue10 = PI;
  double testValue11 = NAN;
  double testValue12 = -NAN;
  double testValue13 = INFINITY;
  double testValue14 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_asin(testValue1), asin(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(testValue2), asin(testValue2), 0.000001);

  ck_assert(s21_is_nan(s21_asin(testValue3)) == s21_is_nan(asin(testValue3)));
  ck_assert(s21_is_nan(s21_asin(testValue4)) == s21_is_nan(asin(testValue4)));
  ck_assert(s21_is_nan(s21_asin(testValue5)) == s21_is_nan(asin(testValue5)));
  ck_assert(s21_is_nan(s21_asin(testValue6)) == s21_is_nan(asin(testValue6)));
  ck_assert_ldouble_eq_tol(s21_asin(testValue7), asin(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_asin(testValue8)) == s21_is_nan(asin(testValue8)));
  ck_assert(s21_is_nan(s21_asin(testValue9)) == s21_is_nan(asin(testValue9)));
  ck_assert(s21_is_nan(s21_asin(testValue10)) == s21_is_nan(asin(testValue10)));
  ck_assert(s21_is_nan(s21_asin(testValue11)) == s21_is_nan(asin(testValue11)));
  ck_assert(s21_is_nan(s21_asin(testValue12)) == s21_is_nan(asin(testValue12)));
  ck_assert(s21_is_nan(s21_asin(testValue13)) == s21_is_nan(asin(testValue13)));
  ck_assert(s21_is_nan(s21_asin(testValue14)) == s21_is_nan(asin(testValue14)));
}
END_TEST
Suite *s21_asin_suite() {
  Suite *s;
  TCase *tc_s21_asin;

  s = suite_create("s21_asin");
  tc_s21_asin = tcase_create("s21_asin");
  tcase_add_test(tc_s21_asin, test_s21_math_asin);
  suite_add_tcase(s, tc_s21_asin);

  return s;
}

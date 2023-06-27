#include "s21_test.h"

START_TEST(test_s21_math_acos) {
  for (double i = -1; i <= 1; i += 0.3) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 0.000001);
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

  ck_assert_ldouble_eq_tol(s21_acos(testValue1), acos(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(testValue2), acos(testValue2), 0.000001);

  ck_assert(s21_is_nan(s21_acos(testValue3)) == s21_is_nan(acos(testValue3)));
  ck_assert(s21_is_nan(s21_acos(testValue4)) == s21_is_nan(acos(testValue4)));
  ck_assert(s21_is_nan(s21_acos(testValue5)) == s21_is_nan(acos(testValue5)));
  ck_assert(s21_is_nan(s21_acos(testValue6)) == s21_is_nan(acos(testValue6)));
  ck_assert_ldouble_eq_tol(s21_acos(testValue7), acos(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_acos(testValue8)) == s21_is_nan(acos(testValue8)));
  ck_assert(s21_is_nan(s21_acos(testValue9)) == s21_is_nan(acos(testValue9)));
  ck_assert(s21_is_nan(s21_acos(testValue10)) == s21_is_nan(acos(testValue10)));
  ck_assert(s21_is_nan(s21_acos(testValue11)) == s21_is_nan(acos(testValue11)));
  ck_assert(s21_is_nan(s21_acos(testValue12)) == s21_is_nan(acos(testValue12)));
  ck_assert(s21_is_nan(s21_acos(testValue13)) == s21_is_nan(acos(testValue13)));
  ck_assert(s21_is_nan(s21_acos(testValue14)) == s21_is_nan(acos(testValue14)));
}
END_TEST
Suite *s21_acos_suite() {
  Suite *s;
  TCase *tc_s21_acos;

  s = suite_create("s21_acos");
  tc_s21_acos = tcase_create("s21_acos");
  tcase_add_test(tc_s21_acos, test_s21_math_acos);
  suite_add_tcase(s, tc_s21_acos);

  return s;
}

#include "s21_test.h"

START_TEST(test_s21_math_sin) {
  for (double i = -1; i < 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 0.000001);
  }
  ck_assert_float_eq(sin(-13.54), s21_sin(-13.54));
  ck_assert_float_eq(sin(0.01), s21_sin(0.01));
 // ck_assert_float_eq(sin(PI - 0.01), s21_sin(PI - 0.01));
  ck_assert_float_eq(sin(13.54), s21_sin(13.54));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
 // ck_assert_float_eq(sin(PI), s21_sin(PI));
  ck_assert_float_eq(sin(6.28), s21_sin(6.28));
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_ldouble_eq(exp(-INFINITY), s21_exp(-INFINITY));
  for (double i = 1.7E-308; i < 1.7E-307; i += 0.055) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 0.000001);
  }
  // for (double i = 1.7E+305 - 1; i < 1.7E+307; i += 0.055) {
  //   ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), 0.000001);
  // }

  double testValue1 = 0;
  double testValue2 = 1;
  double testValue3 = 2 * 3.14;
  double testValue4 = -PI - 2;
  double testValue5 = -2 * 3.14;
  double testValue6 = PI * PI;
  double testValue7 = 100;
  double testValue8 = PI * 0.5;
  double testValue9 = -PI * 0.5;
  double testValue10 = PI;
  double testValue11 = NAN;
  double testValue12 = -NAN;
  double testValue13 = INFINITY;
  double testValue14 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_sin(testValue1), sin(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(testValue2), sin(testValue2), 0.000001);

  ck_assert(s21_is_nan(s21_sin(testValue3)) == s21_is_nan(sin(testValue3)));
  ck_assert(s21_is_nan(s21_sin(testValue4)) == s21_is_nan(sin(testValue4)));
  ck_assert(s21_is_nan(s21_sin(testValue5)) == s21_is_nan(sin(testValue5)));
  ck_assert(s21_is_nan(s21_sin(testValue6)) == s21_is_nan(sin(testValue6)));
  ck_assert_ldouble_eq_tol(s21_sin(testValue7), sin(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_sin(testValue8)) == s21_is_nan(sin(testValue8)));
  ck_assert(s21_is_nan(s21_sin(testValue9)) == s21_is_nan(sin(testValue9)));
  ck_assert(s21_is_nan(s21_sin(testValue10)) ==
  s21_is_nan(sin(testValue10))); ck_assert(s21_is_nan(s21_sin(testValue11))
  == s21_is_nan(sin(testValue11)));
  ck_assert(s21_is_nan(s21_sin(testValue12)) ==
  s21_is_nan(sin(testValue12))); ck_assert(s21_is_nan(s21_sin(testValue13))
  == s21_is_nan(sin(testValue13)));
  ck_assert(s21_is_nan(s21_sin(testValue14)) ==
  s21_is_nan(sin(testValue14)));
}
END_TEST
Suite *s21_sin_suite() {
  Suite *s;
  TCase *tc_s21_sin;

  s = suite_create("s21_sin");
  tc_s21_sin = tcase_create("s21_sin");
  tcase_add_test(tc_s21_sin, test_s21_math_sin);
  suite_add_tcase(s, tc_s21_sin);

  return s;
}

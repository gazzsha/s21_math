#include "s21_test.h"

START_TEST(test_s21_math_sqrt) {
  for (double i = 0; i < 1.5; i += 0.0055) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }


  double testValue1 = -5;
  double testValue2 = 0;
  double testValue3 = NAN;
  double testValue4 = -NAN;
  double testValue5 = INFINITY;
  double testValue6 = -INFINITY;

  ck_assert(s21_is_nan(s21_sqrt(testValue1)) == s21_is_nan(sqrt(testValue1)));
  ck_assert_ldouble_nan(s21_sqrt(testValue1));
  ck_assert_ldouble_eq_tol(s21_sqrt(testValue2), sqrt(testValue2), 0.000001);
  ck_assert(s21_is_nan(s21_sqrt(testValue3)) == s21_is_nan(sqrt(testValue3)));
  ck_assert(s21_is_nan(s21_sqrt(testValue4)) == s21_is_nan(sqrt(testValue4)));
  ck_assert(s21_sqrt(testValue5) == sqrt(testValue5));
  ck_assert(s21_is_nan(s21_sqrt(testValue6)) == s21_is_nan(sqrt(testValue6)));
    for (double i = (1.7E+305) - 0.05; i < 1.7E+307; i += 0.005) {
    ck_assert_int_eq(s21_sqrt(i), sqrt(i));
  }
}
END_TEST
Suite *s21_sqrt_suite() {
  Suite *s;
  TCase *tc_s21_sqrt;

  s = suite_create("s21_sqrt");
  tc_s21_sqrt = tcase_create("s21_sqrt");
  tcase_add_test(tc_s21_sqrt, test_s21_math_sqrt);
  suite_add_tcase(s, tc_s21_sqrt);

  return s;
}

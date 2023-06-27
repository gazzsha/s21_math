#include "s21_test.h"

START_TEST(test_s21_math_atan) {
  for (double i = -1; i <= 1; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 0.000001);
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
//  double testValue11 = NAN;
  double testValue12 = -NAN;
  double testValue13 = INFINITY;
  double testValue14 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_atan(testValue1), atan(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(testValue2), atan(testValue2), 0.000001);

  ck_assert(s21_is_nan(s21_atan(testValue3)) == s21_is_nan(atan(testValue3)));
  ck_assert(s21_is_nan(s21_atan(testValue4)) == s21_is_nan(atan(testValue4)));
  ck_assert(s21_is_nan(s21_atan(testValue5)) == s21_is_nan(atan(testValue5)));
  ck_assert(s21_is_nan(s21_atan(testValue6)) == s21_is_nan(atan(testValue6)));
  ck_assert_ldouble_eq_tol(s21_atan(testValue7), atan(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_atan(testValue8)) == s21_is_nan(atan(testValue8)));
  ck_assert(s21_is_nan(s21_atan(testValue9)) == s21_is_nan(atan(testValue9)));
  ck_assert(s21_is_nan(s21_atan(testValue10)) == s21_is_nan(atan(testValue10)));
 // ck_assert(s21_is_nan(s21_atan(testValue11)) == s21_is_nan(atan(testValue11)));
  ck_assert(s21_is_nan(s21_atan(testValue12)) == s21_is_nan(atan(testValue12)));
  ck_assert(s21_is_nan(s21_atan(testValue13)) == s21_is_nan(atan(testValue13)));
  ck_assert(s21_is_nan(s21_atan(testValue14)) == s21_is_nan(atan(testValue14)));
}
END_TEST
Suite *s21_atan_suite() {
  Suite *s;
  TCase *tc_s21_atan;

  s = suite_create("s21_atan");
  tc_s21_atan = tcase_create("s21_atan");
  tcase_add_test(tc_s21_atan, test_s21_math_atan);
  suite_add_tcase(s, tc_s21_atan);

  return s;
}

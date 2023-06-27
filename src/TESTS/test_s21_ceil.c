#include "s21_test.h"

START_TEST(test_s21_math_ceil) {
  double testValue1 = -1.5;
  double testValue2 = -1;
  double testValue3 = 0;
  double testValue4 = 1;
  double testValue5 = 1.5;
  double testValue6 = -123456789000000.50604070308020901;
  // double testValue7 = 0.000152474;
  double testValue8 = -156.0544784;
  double testValue9 = 0.5454555;
  double testValue10 = 123456789000000.50604070308020901;
  double testValue11 = INFINITY;
  double testValue12 = -INFINITY;
  double testValue13 = -NAN;
  double testValue14 = NAN;
  ck_assert_ldouble_eq(s21_ceil(testValue1), ceil(testValue1));
  ck_assert_ldouble_eq(s21_ceil(testValue2), ceil(testValue2));
  ck_assert_ldouble_eq(s21_ceil(testValue3), ceil(testValue3));
  ck_assert_ldouble_eq(s21_ceil(testValue4), ceil(testValue4));
  ck_assert_ldouble_eq(s21_ceil(testValue5), ceil(testValue5));
  ck_assert_ldouble_eq(s21_ceil(testValue6), ceil(testValue6));
  // ck_assert_ldouble_eq(s21_ceil(testValue7), ceil(testValue7));
  ck_assert_ldouble_eq(s21_ceil(testValue8), ceil(testValue8));
  ck_assert_ldouble_eq(s21_ceil(testValue9), ceil(testValue9));
  ck_assert_ldouble_eq(s21_ceil(testValue10), ceil(testValue10));
  ck_assert_ldouble_eq(s21_ceil(testValue11), ceil(testValue11));
  ck_assert_ldouble_eq(s21_ceil(testValue12), ceil(testValue12));
  ck_assert(s21_is_nan(s21_ceil(testValue13)) == s21_is_nan(ceil(testValue13)));
  ck_assert(s21_is_nan(s21_ceil(testValue14)) == s21_is_nan(ceil(testValue14)));
}
END_TEST

Suite *s21_ceil_suite() {
  Suite *s;
  TCase *tc_s21_ceil;

  s = suite_create("s21_ceil");
  tc_s21_ceil = tcase_create("s21_ceil");
  tcase_add_test(tc_s21_ceil, test_s21_math_ceil);
  suite_add_tcase(s, tc_s21_ceil);

  return s;
}

#include "s21_test.h"

START_TEST(test_s21_math_floor) {
  double testValue1 = -1.5;
  double testValue2 = -1;
  double testValue3 = 0;
  double testValue4 = 1;
  double testValue5 = 1.5;
  double testValue6 = -123456789000000.50604070308020901;
  double testValue7 = 0.000152474;
  double testValue8 = -156.0544784;
  double testValue9 = 0.5454555;
  double testValue10 = 123456789000000.50604070308020901;
  double testValue11 = INFINITY;
  double testValue12 = -INFINITY;
  double testValue13 = -NAN;
  double testValue14 = NAN;
  ck_assert_ldouble_eq(s21_floor(testValue1), floor(testValue1));
  ck_assert_ldouble_eq(s21_floor(testValue2), floor(testValue2));
  ck_assert_ldouble_eq(s21_floor(testValue3), floor(testValue3));
  ck_assert_ldouble_eq(s21_floor(testValue4), floor(testValue4));
  ck_assert_ldouble_eq(s21_floor(testValue5), floor(testValue5));
  ck_assert_ldouble_eq(s21_floor(testValue6), floor(testValue6));
  ck_assert_ldouble_eq(s21_floor(testValue7), floor(testValue7));
  ck_assert_ldouble_eq(s21_floor(testValue8), floor(testValue8));
  ck_assert_ldouble_eq(s21_floor(testValue9), floor(testValue9));
  ck_assert_ldouble_eq(s21_floor(testValue10), floor(testValue10));
  ck_assert_ldouble_eq(s21_floor(testValue11), floor(testValue11));
  ck_assert_ldouble_eq(s21_floor(testValue12), floor(testValue12));
  ck_assert(s21_is_nan(s21_floor(testValue13)) ==
            s21_is_nan(floor(testValue13)));
  ck_assert(s21_is_nan(s21_floor(testValue14)) ==
            s21_is_nan(floor(testValue14)));
}
END_TEST

Suite *s21_floor_suite() {
  Suite *s;
  TCase *tc_s21_floor;

  s = suite_create("s21_floor");
  tc_s21_floor = tcase_create("s21_floor");
  tcase_add_test(tc_s21_floor, test_s21_math_floor);
  suite_add_tcase(s, tc_s21_floor);

  return s;
}

#include "s21_test.h"

START_TEST(test_s21_math_fmod) {
  double testValue1[2] = {20.823123, PI};
  double testValue2[2] = {1.00000, 15522};
  double testValue3[2] = {-PI * 0.5, PI};
  double testValue4[2] = {PI, 0};
  double testValue5[2] = {PI * 0.5, INFINITY};
  double testValue6[2] = {PI * 0.5, -INFINITY};
  double testValue7[2] = {-INFINITY, 5};
  double testValue8[2] = {INFINITY, -1};
  double testValue9[2] = {-NAN, 1};
  double testValue10[2] = {NAN, 1};

  ck_assert_ldouble_eq_tol(s21_fmod(testValue1[0], testValue1[1]),
                           fmod(testValue1[0], testValue1[1]), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_fmod(testValue2[0], testValue2[1]),
                           fmod(testValue2[0], testValue2[1]), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_fmod(testValue3[0], testValue3[1]),
                           fmod(testValue3[0], testValue3[1]), 0.0000001);
  ck_assert_ldouble_nan(s21_fmod(testValue4[0], testValue4[1]));
  ck_assert_ldouble_eq_tol(s21_fmod(testValue5[0], testValue5[1]),
                           fmod(testValue5[0], testValue5[1]), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_fmod(testValue6[0], testValue6[1]),
                           fmod(testValue6[0], testValue6[1]), 0.0000001);
  ck_assert_ldouble_nan(s21_fmod(testValue7[0], testValue7[1]));
  ck_assert_ldouble_nan(s21_fmod(testValue8[0], testValue8[1]));
  ck_assert_ldouble_nan(s21_fmod(testValue9[0], testValue9[1]));
  ck_assert_ldouble_nan(s21_fmod(testValue10[0], testValue10[1]));
}
END_TEST

Suite *s21_fmod_suite() {
  Suite *s;
  TCase *tc_s21_fmod;

  s = suite_create("s21_fmod");
  tc_s21_fmod = tcase_create("s21_fmod");
  tcase_add_test(tc_s21_fmod, test_s21_math_fmod);
  suite_add_tcase(s, tc_s21_fmod);

  return s;
}

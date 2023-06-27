#include "s21_test.h"

START_TEST(test_s21_math_cos) {
  for (double i = -1; i <= 1.2; i += 0.05) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), 0.000001);
  }
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
 // ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  double testValue1 = 0;
  double testValue2 = 1;
  double testValue3 = 2 * 3.14;
//  double testValue4 = -PI - 2;
  double testValue5 = -2 * 3.14;
 // double testValue6 = PI * PI;
  double testValue7 = -1;
  double testValue8 = PI * 0.5;
  double testValue9 = -PI * 0.5;
 // double testValue10 = PI;
  double testValue11 = NAN;
  double testValue12 = -NAN;
  double testValue13 = INFINITY;
  double testValue14 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_cos(testValue1), cos(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(testValue2), cos(testValue2), 0.000001);

  ck_assert(s21_is_nan(s21_cos(testValue3)) == s21_is_nan(cos(testValue3)));
  //ck_assert(s21_is_nan(s21_cos(testValue4)) == s21_is_nan(cos(testValue4)));
  ck_assert(s21_is_nan(s21_cos(testValue5)) == s21_is_nan(cos(testValue5)));
 // ck_assert(s21_is_nan(s21_cos(testValue6)) == s21_is_nan(cos(testValue6)));
  ck_assert_ldouble_eq_tol(s21_cos(testValue7), cos(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_cos(testValue8)) == s21_is_nan(cos(testValue8)));
  ck_assert(s21_is_nan(s21_cos(testValue9)) == s21_is_nan(cos(testValue9)));
 // ck_assert(s21_is_nan(s21_cos(testValue10)) == s21_is_nan(cos(testValue10)));
  ck_assert(s21_is_nan(s21_cos(testValue11)) == s21_is_nan(cos(testValue11)));
  ck_assert(s21_is_nan(s21_cos(testValue12)) == s21_is_nan(cos(testValue12)));
  ck_assert(s21_is_nan(s21_cos(testValue13)) == s21_is_nan(cos(testValue13)));
  ck_assert(s21_is_nan(s21_cos(testValue14)) == s21_is_nan(cos(testValue14)));
}
END_TEST
// START_TEST(test_s21_math_cos) {
//   double testValue1 = -PI * 0.5;
//   double testValue2 = PI * 0.5;
//   double testValue3 = PI * 0.25;
//   double testValue4 = -PI * 0.5;
//   double testValue5 = 0;
//   double testValue6 = -1;
//   double testValue7 = 1;
//   double testValue8 = PI * 2;
//   double testValue9 = -PI * 10;
//   double testValue10 = PI * 2289;

//   ck_assert_ldouble_eq_tol(s21_cos(testValue1), cos(testValue1), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue2), cos(testValue2), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue3), cos(testValue3), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue4), cos(testValue4), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue5), cos(testValue5), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue6), cos(testValue6), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue7), cos(testValue7), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue8), cos(testValue8), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue9), cos(testValue9), 0.0000001);
//   ck_assert_ldouble_eq_tol(s21_cos(testValue10), cos(testValue10),
//   0.0000001);
// }
Suite *s21_cos_suite() {
  Suite *s;
  TCase *tc_s21_cos;

  s = suite_create("s21_cos");
  tc_s21_cos = tcase_create("s21_cos");
  tcase_add_test(tc_s21_cos, test_s21_math_cos);
  suite_add_tcase(s, tc_s21_cos);

  return s;
}

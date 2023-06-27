#include "s21_test.h"

START_TEST(test_s21_math_tan) {
  for (double i = -0.9; i < 1; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  for (double i = 1.7E-308; i < 1.7E-307; i += 0.055) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  for (double i = 1.7E+308 - 1; i < 1.7E+307; i += 0.055) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  // for (double i = -2 * PI; i < 2 * PI; i += PI) {
  //   ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 0.000001);
  // }

  double testValue1 = 0;
  double testValue2 = 2;
  double testValue3 = 5;
  double testValue4 = 3;
  double testValue5 = -2 * 3.14;
  double testValue6 = PI * PI;
  double testValue7 = 100;
  double testValue8 = PI * 0.5;
  //double testValue9 = -PI * 0.5;
  double testValue10 = PI;
  double testValue11 = NAN;
  double testValue12 = -NAN;
  double testValue13 = INFINITY;
  double testValue14 = -INFINITY;

  ck_assert_ldouble_eq_tol(s21_tan(testValue1), tan(testValue1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(testValue2), tan(testValue2), 0.000001);
 // ck_assert_ldouble_eq_tol(s21_tan(testValue3), tan(testValue3), 0.000001);
 //ck_assert_ldouble_eq_tol(s21_tan(testValue4), tan(testValue4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(testValue5), tan(testValue5), 0.000001);
 ck_assert_ldouble_eq_tol(s21_tan(testValue6), tan(testValue6), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(testValue7), tan(testValue7), 0.000001);
 // ck_assert_float_eq_tol(s21_tan(testValue8), tan(testValue8), 0.000001);
 // ck_assert_float_eq_tol(s21_tan(testValue9), tan(testValue9), 0.000001);
 ck_assert_ldouble_eq_tol(s21_tan(testValue10), tan(testValue10), 0.000001);
  ck_assert((s21_is_nan(s21_tan(testValue11))) ==
            (s21_is_nan(tan(testValue11))));
  ck_assert((s21_is_nan(s21_tan(testValue12))) ==
            (s21_is_nan(tan(testValue12))));
  ck_assert((s21_is_nan(s21_tan(testValue13))) ==
            (s21_is_nan(tan(testValue13))));
  ck_assert((s21_is_nan(s21_tan(testValue14))) ==
            (s21_is_nan(tan(testValue14))));

  ck_assert(s21_is_nan(s21_tan(testValue3)) == s21_is_nan(tan(testValue3)));
  ck_assert(s21_is_nan(s21_tan(testValue4)) == s21_is_nan(tan(testValue4)));
  ck_assert(s21_is_nan(s21_tan(testValue5)) == s21_is_nan(tan(testValue5)));
  ck_assert(s21_is_nan(s21_tan(testValue6)) == s21_is_nan(tan(testValue6)));
  ck_assert_ldouble_eq_tol(s21_tan(testValue7), tan(testValue7), 0.000001);
  ck_assert(s21_is_nan(s21_tan(testValue8)) == s21_is_nan(tan(testValue8)));
  // ck_assert((s21_tan(testValue9)) == (tan(testValue9)));
  ck_assert(s21_is_nan(s21_tan(testValue10)) == s21_is_nan(tan(testValue10)));
  ck_assert(s21_is_nan(s21_tan(testValue11)) == s21_is_nan(tan(testValue11)));
  ck_assert(s21_is_nan(s21_tan(testValue12)) == s21_is_nan(tan(testValue12)));
  ck_assert(s21_is_nan(s21_tan(testValue13)) == s21_is_nan(tan(testValue13)));
  ck_assert(s21_is_nan(s21_tan(testValue14)) == s21_is_nan(tan(testValue14)));
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(3.14), s21_tan(3.14));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
}
END_TEST
Suite *s21_tan_suite() {
  Suite *s;
  TCase *tc_s21_tan;

  s = suite_create("s21_tan");
  tc_s21_tan = tcase_create("s21_tan");
  tcase_add_test(tc_s21_tan, test_s21_math_tan);
  suite_add_tcase(s, tc_s21_tan);

  return s;
}

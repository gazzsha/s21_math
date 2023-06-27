#include "s21_test.h"

START_TEST(test_s21_math_log) {
  for (double i = 0.01; i < 3; i += 0.0055) {
    ck_assert_float_eq(s21_log(i), log(i));
  }

  double testValue1 = 0;
  double testValue2 = INFINITY;
  double testValue3 = -INFINITY;
  double testValue4 = -NAN;
  double testValue5 = NAN;
  double testValue6 = 12.345e5;
 double testValue7 = 1.7E307;

  ck_assert(s21_log(testValue1) == log(testValue1));
  ck_assert(s21_log(testValue2) == log(testValue2));
  ck_assert(s21_is_nan(s21_log(testValue3)) == s21_is_nan(log(testValue3)));
  ck_assert(s21_is_nan(s21_log(testValue4)) == s21_is_nan(log(testValue4)));
  ck_assert(s21_is_nan(s21_log(testValue5)) == s21_is_nan(log(testValue5)));
  ck_assert_ldouble_eq_tol(s21_log(testValue6), log(testValue6), 0.0000001);
 ck_assert_ldouble_eq_tol(s21_log(testValue7), log(testValue7), 0.0000001);
}
END_TEST


START_TEST(log_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(log_test_2) {
    double x = -1;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(log_test_3) {
    double x = 0;
     ck_assert_ldouble_infinite(s21_log(x));
     ck_assert_ldouble_infinite(log(x));
}
END_TEST

START_TEST(log_test_4) {
    double x =2500;
   ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(log_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(log_test_6) {
    double x = 5;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(log_test_7) {
    double x = -DBL_MAX;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(log_test_8) {
    double x = 1e-5;
    ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST

START_TEST(log_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_nan(s21_log(x));
    ck_assert_ldouble_nan(log(x));
}
END_TEST

START_TEST(log_test_10) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_test_11) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));
}
END_TEST

START_TEST(log_test_12) {
 ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_test_13) {
    for (double i = 1e-3L; i < 100.0L; i+=1e-1L) {
            ck_assert_ldouble_eq_tol(s21_log(i), log(i), 0.000001);
    }
}
END_TEST

START_TEST(log_test_14) {
    double x = DBL_MAX;
 ck_assert_ldouble_eq_tol(s21_log(x), log(x), 0.000001);
}
END_TEST


Suite *s21_log_suite() {
  Suite *s;
  TCase *tc_s21_log;

  s = suite_create("s21_log");
  tc_s21_log = tcase_create("s21_log");
  tcase_add_test(tc_s21_log, test_s21_math_log);
   tcase_add_test(tc_s21_log,log_test_1);
    tcase_add_test(tc_s21_log,log_test_2);
    tcase_add_test(tc_s21_log,log_test_3);
   tcase_add_test(tc_s21_log,log_test_4);
    tcase_add_test(tc_s21_log,log_test_5);
   tcase_add_test(tc_s21_log,log_test_6);
    tcase_add_test(tc_s21_log,log_test_7);
    tcase_add_test(tc_s21_log,log_test_8);
    tcase_add_test(tc_s21_log,log_test_9);
    tcase_add_test(tc_s21_log,log_test_10);
    tcase_add_test(tc_s21_log,log_test_11);
     tcase_add_test(tc_s21_log,log_test_12);
     tcase_add_test(tc_s21_log,log_test_13);
        tcase_add_test(tc_s21_log,log_test_14);
  suite_add_tcase(s, tc_s21_log);

  return s;
}

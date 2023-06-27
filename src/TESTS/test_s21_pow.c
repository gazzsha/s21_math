#include "s21_test.h"

START_TEST(test_s21_math_pow) {
  double tV1[2] = {-2, 0.5};
  double tV2[2] = {-2, 2};
  double tV3[2] = {2, 3};
  double tV4[2] = {-2, -3};
  double tV5[2] = {1.5, 2};
  double tV6[2] = {4, 1 / 2};
  double tV7[2] = {NAN, 1};
   double tV8[2] = {-NAN, 1};
  double tV9[2] = {INFINITY, -1};
  double tV10[2] = {-INFINITY, 5};
  double tV11[2] = {0, 4};
  double tV12[2] = {PI / 2, -INFINITY};
  double tV13[2] = {PI / 2, INFINITY};
  double tV14[2] = {PI, 0};
  double tV15[2] = {-PI / 2, PI};
  double tV16[2] = {0, 0};
  double tV17[2] = {INFINITY, -INFINITY};
  double tV18[2] = {INFINITY, INFINITY};
  double tV19[2] = {-INFINITY, INFINITY};
  double tV20[2] = {INFINITY, 4};
  double tV21[2] = {-INFINITY, 4};
   double tV22[2] = {NAN, NAN};
  double tV23[2] = {-NAN, -NAN};
  double tV24[2] = {-NAN, NAN};
  double tV25[2] = {NAN, -NAN};
  double tV26[2] = {45, 6};
  double tV27[2] = {-45, 7};
  double tV28[2] = {45, -10};
  double tV29[2] = {-45, -6};
  double tV30[2] = {16.2e10, 0.5};

  ck_assert_ldouble_nan(s21_pow(tV1[0], tV1[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV2[0], tV2[1]), pow(tV2[0], tV2[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV3[0], tV3[1]), pow(tV3[0], tV3[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV4[0], tV4[1]), pow(tV4[0], tV4[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV5[0], tV5[1]), pow(tV5[0], tV5[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV6[0], tV6[1]), pow(tV6[0], tV6[1]),
                           0.0000001);
  ck_assert_ldouble_nan(s21_pow(tV7[0], tV7[1]));
  ck_assert_double_nan(s21_pow(tV8[0], tV8[1]));
  ck_assert_double_nan(pow(tV8[0], tV8[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV9[0], tV9[1]), pow(tV9[0], tV9[1]),
                           0.0000001);
                            ck_assert_ldouble_infinite(s21_pow(tV10[0], tV10[1]));
                            ck_assert_ldouble_infinite(pow(tV10[0], tV10[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV11[0], tV11[1]), pow(tV11[0], tV11[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV12[0], tV12[1]), pow(tV12[0], tV12[1]),
                           0.0000001);
  ck_assert_ldouble_eq(s21_pow(tV13[0], tV13[1]), pow(tV13[0], tV13[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV14[0], tV14[1]), pow(tV14[0], tV14[1]),
                           0.0000001);
   ck_assert_double_nan(s21_pow(tV15[0], tV15[1]));
      ck_assert_double_nan(pow(tV15[0], tV15[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV16[0], tV16[1]), pow(tV16[0], tV16[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV17[0], tV17[1]), pow(tV17[0], tV17[1]),
                           0.0000001);
  ck_assert_ldouble_eq(s21_pow(tV18[0], tV18[1]), pow(tV18[0], tV18[1]));
  ck_assert_ldouble_eq(s21_pow(tV19[0], tV19[1]), pow(tV19[0], tV19[1]));
  ck_assert_ldouble_eq(s21_pow(tV20[0], tV20[1]), pow(tV20[0], tV20[1]));
  ck_assert_ldouble_eq(s21_pow(tV21[0], tV21[1]), pow(tV21[0], tV21[1]));
       ck_assert_double_nan(s21_pow(tV22[0], tV22[1]));
             ck_assert_double_nan(pow(tV22[0], tV22[1]));
                            ck_assert_double_nan(s21_pow(tV23[0], tV23[1]));
             ck_assert_double_nan(pow(tV23[0], tV23[1]));
   ck_assert_double_nan(s21_pow(tV24[0], tV24[1]));
             ck_assert_double_nan(pow(tV24[0], tV24[1]));
ck_assert_double_nan(s21_pow(tV25[0], tV25[1]));
             ck_assert_double_nan(pow(tV25[0], tV25[1]));
  ck_assert_ldouble_eq_tol(s21_pow(tV26[0], tV26[1]), pow(tV26[0], tV26[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV27[0], tV27[1]), pow(tV27[0], tV27[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV28[0], tV28[1]), pow(tV28[0], tV28[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV29[0], tV29[1]), pow(tV29[0], tV29[1]),
                           0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(tV30[0], tV30[1]), pow(tV30[0], tV30[1]),
                           0.0000001);
}
END_TEST

START_TEST(TEST_POW) {
    for (double i = -20; i < 20; i+=0.001) {
         ck_assert_double_eq_tol(s21_exp(i), exp(i), 0.000001);
    }
}

START_TEST(exp_test_1) {
    double x = 1;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_2) {
    double x = -1;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_3) {
    double x = 0;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_4) {
    double x = 999999999999;
    ck_assert_ldouble_infinite(s21_exp(x));
    ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_5) {
    double x = -999999999999;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_6) {
    double x = DBL_MAX;
    ck_assert_ldouble_infinite(s21_exp(x));
    ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_7) {
    double x = -DBL_MAX;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_8) {
    double x = 1e-9;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_9) {
    double x = -1e-9;
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 0.000001);
}
END_TEST

START_TEST(exp_test_10) {
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_11) {
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_12) {
    ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 0.000001);
}
END_TEST

Suite *s21_pow_suite() {
  Suite *s;
  TCase *tc_s21_pow;

  s = suite_create("s21_pow");
  tc_s21_pow = tcase_create("s21_pow");
  tcase_add_test(tc_s21_pow, test_s21_math_pow);
  tcase_add_test(tc_s21_pow,TEST_POW);
  tcase_add_test(tc_s21_pow, exp_test_1);
  tcase_add_test(tc_s21_pow, exp_test_2);
    tcase_add_test(tc_s21_pow, exp_test_3);
    tcase_add_test(tc_s21_pow, exp_test_4);
    tcase_add_test(tc_s21_pow, exp_test_5);
    tcase_add_test(tc_s21_pow, exp_test_6);
    tcase_add_test(tc_s21_pow, exp_test_7);
    tcase_add_test(tc_s21_pow, exp_test_8);
    tcase_add_test(tc_s21_pow, exp_test_9);
    tcase_add_test(tc_s21_pow, exp_test_10);
    tcase_add_test(tc_s21_pow, exp_test_11);
    tcase_add_test(tc_s21_pow, exp_test_12);
  suite_add_tcase(s, tc_s21_pow);

  return s;
}

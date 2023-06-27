#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

Suite *s21_abs_suite();
Suite *s21_acos_suite();
Suite *s21_asin_suite();
Suite *s21_atan_suite();
Suite *s21_ceil_suite();
Suite *s21_cos_suite();
Suite *s21_exp_suite();
Suite *s21_fabs_suite();
Suite *s21_floor_suite();
Suite *s21_fmod_suite();
Suite *s21_log_suite();
Suite *s21_pow_suite();
Suite *s21_sin_suite();
Suite *s21_sqrt_suite();
Suite *s21_tan_suite();
Suite *suite_s21_pow_sec(void);
Suite *suite_s21_sqrt(void);
Suite *suite_s21_acos_sec(void);
void run_tests(void);
void run_testcase(Suite *testcase);
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define PI 3.14159265358979323846264338327950288
#define PI_2 1.57079632679489661923132169163975144
#define S21_EXP 2.7182818284590452353602874713526624
#define ESP 1e-16L
#define MAX_ITERATIONS 350

// support functions
int s21_is_nan(double x);
// void* unsigned_double(double x);
long double functorial(long x);
long double pow_integer(long double x, long n);
long double s21_trunc(double x);
// main function
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
long double s21_sin(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
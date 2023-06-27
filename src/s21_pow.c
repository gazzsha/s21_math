#include "s21_math.h"
#define INF 1.0L / 0.0L
#define MINUS_INF -1.0L / 0.0L
#define nan 0.0L / 0.0L
long double s21_pow(double base, double exp) {
  long double result = 0.0L;
  if (s21_is_nan(exp)) {
    if (base == 1.0)
      result = 1.0;
    else if (s21_is_nan(base)) {
      result = base;
    } else
      result = exp;
  } else if (s21_is_nan(base)) {
    if (exp == 0.0)
      result = 1.0;
    else
      result = nan;
  } else if (exp == INF) {
    if (s21_is_nan(base))
      result = base;
    else if (base == INF || base == -INF)
      result = INF;
    else if (base == 1.0 || base == -1.0)
      result = 1.0;
    else if (s21_fabs(base) < 1 && s21_fabs(base) >= 0)
      result = 0;
    else
      result = INF;
  } else if (exp == -INF) {
    if (s21_is_nan(base))
      result = base;
    else if (base == INF || base == -INF)
      result = 0;
    else if (base == 1.0 || base == -1.0)
      result = 1.0;
    else if (base == 0.0)
      result = INF;
    else if (s21_fabs(base) < 1 && s21_fabs(base) > 0)
      result = INF;
    else
      result = 0.0;
  } else if (base == INF || base == -INF) {
    if (exp == 0)
      result = 1;
    else if (s21_is_nan(exp))
      result = exp;
    else if (exp == INF)
      result = INF;
    else if (exp == -INF)
      result = 0.0;
    else if (exp == -1.0) {
      if (base == INF)
        result = 0.0;
      else
        result = -0.0;
    } else if (exp > 0 && s21_fmod(exp, 2.0) == 0)
      result = INF;
    else if (exp > 0 && s21_fmod(exp, 2.0) != 0)
      result = -INF;
    else
      result = 0.0;
  }
  // exp = 0
  else if (exp == 0) {
    result = 1.0L;
  }
  // если base = 0;
  else if (base == 0.0L) {
    if (s21_is_nan(exp))
      result = exp;
    else if (exp == 1.0L / 0.0L)
      result = base;
    else if (exp == -1.0L / 0.0L)
      result = INF;
    else if (exp < 0)
      result = INF;
    else if (exp == 0.0L)
      result = 1.0L;
    else
      result = base;
  }
  // base = 1
  else if (base == 1.0) {
    result = 1.0L;
  }
  // exp = 1.0
  else if (exp == 1.0) {
    result = base;
  } else if (exp == -1.0) {
    if (s21_is_nan(base))
      result = base;
    else if (base == INF)
      result = 0.0L;
    else if (base == -INF)
      result = -0.0L;
    else {
      result = 1.0L / base;
    }
  } else if (base == -1.0) {
    if (s21_is_nan(exp))
      result = exp;
    else if (exp == INF || exp == -INF)
      result = 1.0L;
    else if (exp - s21_trunc(exp) == 0)
      result = 1.0;
    else
      result = -nan;
  } else if ((base - s21_trunc(base) == 0) && (exp - s21_trunc(exp) == 0)) {
    result = 1.0;
    if (exp > 0) {
      while (exp > 0) {
        result *= base;
        exp--;
        if (s21_fabs(result) > DBL_MAX) {
          if (result > 0)
            result = INF;
          else
            result = -INF;
          break;
        }
      }
    } else {
      while (exp < 0) {
        result *= 1 / base;
        exp++;
        if (s21_fabs(result) < DBL_MIN) {
          if (result > 0)
            result = 0.0L;
          else
            result = -0.0L;
          break;
        }
      }
    }
  } else {
    if (base > 0 && exp > 0) {
      result = s21_exp(exp * s21_log(base));
    } else if (base < 0 && exp > 0) {
      if ((exp - s21_trunc(exp) == 0)) {
        result = s21_exp(exp * s21_log(-base));
        if (s21_fmod(exp, 2.0) != 0) result *= (-1.0L);
      } else
        result = 0.0L / 0.0L;
    } else if (base > 0 && exp < 0) {
      result = 1.0L / s21_exp(-exp * s21_log(base));
    } else if (base < 0 && exp < 0) {
      if ((exp - s21_trunc(exp) == 0)) {
        result = 1.0 / s21_exp(-exp * s21_log(-base));
        if (s21_fmod(exp, 2.0) != 0) result *= (-1.0L);
      } else
        result = 0.0L / 0.0L;
    }
  }
  return result;
}
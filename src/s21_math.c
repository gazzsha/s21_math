#include "s21_math.h"

// исключающие ИЛИ ( 0 ^ 1 <==> 1 ^ 0 ) == 0, 1 ^ 1 = 1; после первое итерации у
// нас либо 1.... либо 0..., и вычитаем 1 или 0;
int s21_abs(int x) {
  int temp = x >> 31;
  return (x ^ temp) - temp;
}

long double s21_fabs(double x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_floor(double x) {
  double copy_x = x;
  int flag = x < 0 ? 1 : 0;
  long double result = 0.0L;
  if (s21_is_nan(x)) {
    result = x;
  } else if (x == 1.0L / 0.0L) {
    result = 1.0L / 0.0L;
  } else if (x == -1.0L / 0.0L) {
    result = -1.0L / 0.0L;
  } else {
    char str_number[100] = {0};
    char int_str_number[100] = {0};
    sprintf(str_number, "%.2lf", x);
    strncpy(int_str_number, str_number, strchr(str_number, '.') - str_number);
    sscanf(int_str_number, "%Lf", &result);
    if (flag && (copy_x - result != 0)) result -= 1;
  }
  return result;
}

long double s21_ceil(double x) {
  double copy_x = x;
  long double result = 0.0L;
  if (s21_is_nan(x)) {
    result = x;
  } else if (x == 1.0L / 0.0L) {
    result = 1.0L / 0.0L;
  } else if (x == -1.0L / 0.0L) {
    result = -1.0L / 0.0L;
  } else {
    char str_number[100] = {0};
    char int_str_number[100] = {0};
    sprintf(str_number, "%.2lf", x);
    strncpy(int_str_number, str_number, strchr(str_number, '.') - str_number);
    sscanf(int_str_number, "%Lf", &result);
    if (result >= 0 && (copy_x - result != 0) && copy_x > 0) result += 1;
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 0.0L;
  int flag = 0;  // sign 1 - if x < 0; 0 if x >= 0;
  if (s21_is_nan(x)) {
    result = x < 0 ? -s21_NAN : s21_NAN;
  } else if (x == 1.0L / 0.0L) {
    result = 1.0L / 0.0L;
  } else if (x == -1.0L / 0.0L) {
    result = 0;
  } else {
    if (x < 0) {
      x *= -1;
      flag = 1;
    }
    long double temp = 1.0L;
    long n = 0;
    long double x_up = 1.0L;
    while (s21_fabs(temp) > ESP) {
      temp = x_up / functorial(n);
      result += temp;
      n++;
      x_up *= x;
      if (result > LDBL_MAX) {
        result = 1.0L / 0.0L;
        break;
      }
    }
    if (flag == 1) {
      if (result > LDBL_MAX)
        result = 0.0L;
      else
        result = 1.0L / result;
    }
  }
  return result > LDBL_MAX ? 1.0L / 0.0L : result;
}

long double s21_log(double x) {
  long double result = 0.0L;
  long double ex_pow = 0;
  if (s21_is_nan(x)) {
    result = x;
  } else if (x == 1.0L / 0.0L) {
    result = 1.0L / 0.0L;
  } else if (x == -1.0L / 0.0L) {
    result = -0.0L / 0.0L;
  } else if (x == 0) {
    result = -1.0L / 0.0L;
  } else if (x < 0) {
    result = -0.0L / 0.0L;
  } else {
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;
    long double y = (x - 1.0L) / (x + 1.0L);
    long double temp = y;
    result = y;
    long double numerator = y;
    long double denominator = 1.0L;
    while (s21_fabs(temp) > ESP) {
      numerator *= y * y;
      denominator += 2L;
      temp = numerator / denominator;
      result += temp;
    }
    result *= 2.0L;
  }
  return result + ex_pow;
}

long double s21_fmod(double x, double y) {
  long double result = 0.0L;
  if (s21_is_nan(x) || s21_is_nan(y)) {
    result = x;
  } else if (y == -1.0L / 0.0L || y == 1.0L / 0.0L) {
    result = x;
  } else if (x == -1.0L / 0.0L || x == 1.0L / 0.0L) {
    result = 0.0L / 0.0L;
  } else {
    if (x == 0.0L)
      result = 0.0L;
    else {
      result = (y == 0 ? 0.0L / 0.0L : x - s21_trunc(x / y) * y);
    }
  }
  return result;
}

// long double s21_pow(double base, double exp) {
//   long double result = 1.0L;
//   if (s21_is_nan(base) || s21_is_nan(exp)) {
//     result = (0.0L / 0.0L);
//   } else if ((base == 1.0L / 0.0L || base == -1.0L / 0.0L) &&
//              (exp == 1.0L / 0.0L))
//     result = 1.0 / 0.0;
//   else if (base == 1.0L / 0.0L && exp > 0) {
//     result = 1.0L / 0.0L;
//   } else if (base == 1.0L / 0.0L && exp < 0) {
//     result = 0.0L;
//   } else if (base == -1.0L / 0.0L && (exp - s21_trunc(exp) != 0)) {
//     result = 0.0L / 0.0L;
//   } else if (base == -1.0L / 0.0L && (exp - s21_trunc(exp) == 0) && exp > 0)
//   {
//     result = 1.0L / 0.0L;
//   } else if (base == -1.0L / 0.0L && (exp - s21_trunc(exp) == 0) && exp < 0)
//   {
//     result = -1.0L / 0.0L;
//   } else if (s21_fabs(base) == 1) {
//     if (exp - s21_trunc(exp) == 0.0L)
//       result = 1.0L;
//     else if (base == 1.0L)
//       result = 1.0L;
//     else
//       result = 0.0L / 0.0L;
//   } else if (exp == 0.0L) {
//     if (base >= 0)
//       result = 1.0L;
//     else if (base < 0)
//       result = -1.0L;
//   } else if (base == 0.0L) {
//     if (exp == 1.0L / 0.0L || exp == -1.0L / 0.0L || exp <= 0L)
//       result = 0.0L / 0.0L;
//     else
//       result = base;
//   } else if (exp == 1.0L / 0.0L) {
//     result = 1.0L / 0.0L;
//   } else if (exp == -1.0L / 0.0L) {
//     result = 0.0L;
//   } else {
//     if (exp - s21_trunc(exp) == 0.0L) {
//       if (exp > 0) {
//         for (long i = 0; i < (long)exp; ++i) {
//           result *= base;
//         }
//       } else {
//         for (long i = 0; i < (long)s21_fabs(exp); ++i) {
//           result *= base;
//         }
//         result = 1.0L / result;
//       }
//     } else {
//       if (base > 0 && exp > 0) {
//         result = s21_exp(exp * s21_log(base));
//       } else if (base < 0 && exp > 0) {
//         result = 1.0L / s21_exp(exp * s21_log(base));
//       } else if (base > 0 && exp < 0) {
//         result = s21_exp(exp * s21_log(base));
//       } else if (base < 0 && exp < 0) {
//         result = 0.0L / 0.0L;
//       }
//     }
//   }
//   return result;
// }

long double s21_sqrt(double x) {
  if (x < 0) return s21_NAN;
  return s21_pow(x, 0.5);
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * PI);
  long double temp = x;
  long double numerator = x;
  long double denominator = 1.0L;
  // printf("----%Lf\n",temp);
  long n = 2;
  while (s21_fabs(temp) > ESP && n <= MAX_ITERATIONS) {
    numerator *= (x * x);
    denominator = functorial(2 * n - 1);
    long double before_temp = numerator / denominator;
    if (n % 2L == 0L) before_temp *= -1.0L;
    temp += before_temp;
    n++;
    // printf("---- %Lf ---  %Lf\n",numerator,denominator);
    // //printf("%Lf --- %Lf\n",numerator,denominator);
  }
  return temp;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * PI);
  long double temp = 1.0L;
  long double numerator = 1.0L;
  long double denominator = 2.0L;
  // printf("----%Lf\n",temp);
  long n = 1;
  if (s21_is_nan(x)) {
    temp = 0.0L / 0.0L;
  } else if (x == 1.0 / 0.0 || x == -1.0 / 0.0) {
    temp = 0.0L / 0.0L;
  } else {
    while (s21_fabs(temp) > ESP && n <= MAX_ITERATIONS) {
      numerator *= (x * x);
      denominator = functorial(2.0 * n);
      long double before_temp = numerator / denominator;
      if (n % 2L == 1L) before_temp *= -1.0L;
      temp += before_temp;
      n++;
      //  printf("---- %Lf ---  %Lf\n",numerator,denominator);
      // //printf("%Lf --- %Lf\n",numerator,denominator);
    }
  }
  return temp;
}
long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_atan(double x) {
  long double temp = 1.0L;
  if (s21_fabs(x - (-1.0L)) < 1e-15) {
    temp = (-PI / 4.0L);
  } else if (s21_fabs(x - (1.0L)) < 1e-15) {
    temp = PI / 4.0;
  } else if (x > 1) {
    temp = (PI / 2.0L - s21_atan(1.0L / x));
  } else if (x < -1) {
    temp = (-PI / 2.0L - s21_atan(1.0L / x));
  } else {
    temp = x;
    long double numerator = x;
    long double denominator = 1.0L;
    long double before_temp = x;
    long n = 2;
    while (s21_fabs(before_temp) > ESP) {
      numerator *= (x * x);
      denominator = 2.0L * n - 1.0L;
      before_temp = numerator / denominator;
      if (n % 2L == 0L) before_temp *= -1.0L;
      temp += before_temp;
      n++;
    }
  }
  return temp;
}

long double s21_asin(double x) {
  long double temp = 1.0L;
  if (s21_is_nan(x))
    temp = 0.0 / 0.0;
  else if (x == 1.0 / 0.0)
    temp = -(s21_NAN);
  else if (x == -1)
    temp = -PI / 2;
  else if (x == 1)
    temp = PI / 2;
  else if (x > 1 || x < -1)
    temp = -(s21_NAN);
  else {
    temp = s21_atan(x / s21_sqrt(1.0L - s21_pow(x, 2)));
  }
  return temp;
}

long double s21_acos(double x) {
  long double temp = 1.0L;
  if (s21_is_nan(x))
    temp = 0.0 / 0.0;
  else if (x == 1.0 / 0.0)
    temp = -(s21_NAN);
  else if (x == 0)
    temp = PI / 2;
  else if (x > 1 || x < -1)
    temp = -(s21_NAN);
  else if (x > 0)
    temp = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  else if (x < 0)
    temp = PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  return temp;
}

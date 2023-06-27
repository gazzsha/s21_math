#include "s21_math.h"

// 0 - not NAN, 1 - NAN
int s21_is_nan(double x) {
  // int return_value = 0;
  // number num = {x};
  // if ((num.u & mantissa_double) == 0 ) return_value = 0;
  // else {
  //     // сдвигаем мантиссу, остается порядок и знак.
  //     num.u >>= 52;
  //     if (num.u == 0xFFF) return_value = 1;
  // }
  return x == x ? 0 : 1;
}
// void *unsigned_double(double x) {
//   unsigned long *u = ((unsigned long *)&x);
//   *u = *u & (~(1UL << 63));
//   return (void *)u;
// }
long double functorial(long x) {
  if (x <= 1) return 1.0L;
  return x * functorial(x - 1);
}

long double s21_trunc(double x) { return x >= 0 ? s21_floor(x) : s21_ceil(x); }

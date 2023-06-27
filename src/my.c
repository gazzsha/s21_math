// #include <math.h>
// #include <stdio.h>
// #include <check.h>
// #include "s21_math.h"
// #include <stdlib.h>
// int main() {
//   printf("%d\n", s21_abs(-5));
//   printf("%d\n", s21_abs(5));
//   printf("%.16f\n", log(0.444));
//   printf("%d\n", s21_is_nan(NAN));
//   printf("%d\n", s21_is_nan(5));
//   printf("%Lf\n", s21_fabs(-43242342.423423423));
//   printf("%Lf\n", s21_fabs(2321321.321321321));
//   printf("%LF\n", s21_floor(-6754654.432434L));
//   printf("%LF\n", s21_ceil(-6754654.432434L));
//   printf("%LF\n", s21_ceil(+6754654.432434L));
//   printf("%.16LF %.16F\n", s21_exp(-5), exp(-5));
//   printf("%.16LF %.16F\n", s21_log(1.1432), log(1.1432));
//   printf("%.16LF %.16LF\n", s21_fmod(5, 1.444), s21_fmod(5, 1.444));
//   printf("%.16LF %.16F\n", s21_pow(1, 1.555), pow(1, 1.555));
//   printf("%LF\n", s21_trunc(6754654));
//   printf("%.16LF %.16F\n", s21_sqrt(111.432423), sqrt(111.342));
//   printf("%.16LF %.16F\n", s21_sin(0.5777), sin(0.5777));
//   printf("%.16LF %.16F\n", s21_cos(1.0 / 0.0), cos(1.0 / 0.0));
//   printf("%.16LF %.16F\n", s21_tan(5), tan(5));
//   printf("%.16LF %.16F\n", s21_atan(1.0 / 0.0), atan(1.0 / 0.0));
//   printf("%.16LF %.16F\n", s21_asin(0.99), asin(0.99));
//   printf("%.16LF %.16F\n", s21_acos(0.0 / 0.0), acos(0.0 / 0.0));
// printf("%.16LF %.16F %.16Lf\n", s21_fmod(0.5 * -PI, PI), fmod(0.5 * -PI, PI),
// 0.5 * -PI / PI);
// printf("%.16LF %.16F\n", s21_pow(4, 1/2), pow(4, 1/2));
// printf("%f %LF\n",sin(3.14), s21_sin(3.14));
//   for (double i = -1; i < 1; i += 0.01) {
// printf("%.16LF\n",s21_sin(i));
//   }
//   return 0;
// }

// START_TEST(log_test) {
//      for (double i = 0; i < 20; i+=0.001) {
//          ck_assert_double_eq_tol(s21_log(i), log(i), 0.000001);
//     }
// }

// Suite * pow_suite(void) {
//     Suite *s;
//     TCase *ts_core;

//     s = suite_create("Pow");
//     ts_core = tcase_create("Core");
//     tcase_add_test(ts_core,log_test_1);
//     tcase_add_test(ts_core,log_test_2);
//     tcase_add_test(ts_core,log_test_3);
//    tcase_add_test(ts_core,log_test_4);
//     tcase_add_test(ts_core,log_test_5);
//    tcase_add_test(ts_core,log_test_6);
//     tcase_add_test(ts_core,log_test_7);
//     tcase_add_test(ts_core,log_test_8);
//     tcase_add_test(ts_core,log_test_9);
//     tcase_add_test(ts_core,log_test_10);
//     tcase_add_test(ts_core,log_test_11);
//      tcase_add_test(ts_core,log_test_12);
//      tcase_add_test(ts_core,log_test_13);
//     suite_add_tcase(s,ts_core);
//     return s;
//}

// int main() {
//     int number_failed;
//     Suite *s ;
//     SRunner * sr;
//     s =pow_suite();
//     sr = srunner_create(s);
//     srunner_run_all(sr,CK_NORMAL);
//     number_failed = srunner_ntests_failed(sr);
//     srunner_free(sr);
//     return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
//    for (double i = -10.0; i < 10.3; i+=0.3)
//  printf("%.15f\n",sqrt(-INFINITY));
//  printf("%.15Lf\n",s21_sqrt(-INFINITY));
//   printf("%Lf\n",s21_pow(-NAN,0.5));
//         printf("%Lf\n",s21_pow(-NAN,2));
//          printf("%Lf\n",s21_pow(-NAN,-2));
//           printf("%Lf\n",s21_pow(-NAN,-0.5));
//                printf("%Lf\n",s21_pow(-NAN,0));
//                    printf("%f\n",pow(-NAN,0.5));
//         printf("%f\n",pow(-NAN,2));
//          printf("%f\n",pow(-NAN,-2));
//           printf("%f\n",pow(-NAN,-0.5));
//           printf("%f\n",pow(-NAN,0));
//     printf("%f\n",pow(-INFINITY,0.5));
// s21_acos(-sqrt(3) / 2)
// s21_acos(-sqrt(2) / 2)
//    double x = -sqrt(2)/2.0;
//      printf("%f\n",atan(sqrt(1 - pow(-sqrt(2) / 2,2))/(-sqrt(2) / 2)));
//       printf("%Lf\n", s21_atan(s21_sqrt(1- s21_pow(-sqrt(2) /
//       2,2))/(-s21_sqrt(2) / 2))); printf("%Lf\n",s21_atan(s21_sqrt(1 -
//       s21_pow(x, 2)) / x));

// }
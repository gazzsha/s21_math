#include "s21_test.h"

int main() {
  run_tests();
  return 0;
}
void run_tests(void) {
  Suite *list_cases[] = {
   s21_fabs_suite(),   
   s21_log_suite(),
s21_sqrt_suite(),  
s21_abs_suite(),
s21_ceil_suite(),
  s21_asin_suite(),
  s21_sin_suite(),
    s21_acos_suite(),
  s21_exp_suite(),
  s21_cos_suite(),
  s21_tan_suite(),
    s21_atan_suite(),
  s21_pow_suite(),
    s21_floor_suite(),
    s21_fmod_suite(),
    suite_s21_pow_sec(),
suite_s21_sqrt(),
suite_s21_acos_sec(),
    
                             NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 0)
    putchar('\n');
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
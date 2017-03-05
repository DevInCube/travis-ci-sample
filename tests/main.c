#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include <module.h>

START_TEST (test_sample)
{
    ck_assert(1);
}
END_TEST

START_TEST (test_sample_2)
{
    ck_assert_float_eq(3.5, 3.5);
}
END_TEST

Suite *test_suite() {
  Suite *s = suite_create("Module");
  TCase *tc_sample;

  tc_sample = tcase_create("TestCase");
  tcase_add_test(tc_sample, test_sample);
  tcase_add_test(tc_sample, test_sample_2);

  suite_add_tcase(s, tc_sample);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);  // important for debugging!

  srunner_run_all(sr, CK_VERBOSE);

  int num_tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return num_tests_failed;
}
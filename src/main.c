#include "s21_test.h"

int main() {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests() {
  Suite *list_cases[] = {suite_memchr(),
                         suite_memcmp(),
                         suite_memcpy(),
                         suite_memset(),
                         suite_strncat(),
                         suite_strchr(),
                         suite_strcspn(),
                         suite_strerror(),
                         suite_strlen(),
                         suite_strncmp(),
                         suite_strcpy(),
                         suite_strncpy(),
                         suite_strpbrk(),
                         suite_strrchr(),
                         suite_strstr(),
                         suite_strtok(),
                         suite_to_lower(),
                         suite_to_upper(),
                         suite_insert(),
                         suite_trim(),
                         suite_sscanf_c(),
                         suite_sscanf_d(),
                         suite_sscanf_e(),
                         suite_sscanf_eb(),
                         suite_sscanf_empty(),
                         suite_sscanf_f(),
                         suite_sscanf_g(),
                         suite_sscanf_n(),
                         suite_sscanf_p(),
                         suite_sscanf_real(),
                         suite_sscanf_s(),
                         suite_sscanf_u(),
                         suite_sscanf_x(),
                         suite_sscanf_i(),
                         suite_sscanf_o(),
                         suite_test_memmove(),
                         suite_test_sprintf_c(),
                         suite_test_sprintf_d(),
                         suite_test_sprintf_f(),
                         suite_test_sprintf_e(),
                         suite_test_sprintf_eb(),
                         suite_test_sprintf_g(),
                         suite_test_sprintf_gb(),

                         suite_test_sprintf_o(),
                         suite_test_sprintf_pr(),
                         suite_test_sprintf_p(),
                         suite_test_sprintf_s(),
                         suite_test_sprintf_u(),

                         suite_test_sprintf_x(),
                         suite_test_sprintf_xb(),

                         s21_NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != s21_NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
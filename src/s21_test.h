#include <check.h>

#include "s21_string.h"

Suite *suite_insert();
Suite *suite_memchr();
Suite *suite_memcpy();
Suite *suite_memcmp();
Suite *suite_memset();
Suite *suite_sscanf_c();
Suite *suite_sscanf_d();
Suite *suite_sscanf_e();
Suite *suite_sscanf_eb();
Suite *suite_sscanf_empty();
Suite *suite_sscanf_f();
Suite *suite_sscanf_g();
Suite *suite_sscanf_i();
Suite *suite_sscanf_n();
Suite *suite_sscanf_o();
Suite *suite_sscanf_p();
Suite *suite_sscanf_real();
Suite *suite_sscanf_s();
Suite *suite_sscanf_u();
Suite *suite_sscanf_x();
Suite *suite_strchr();
Suite *suite_strcspn();
Suite *suite_strcpy();
Suite *suite_strncpy();
Suite *suite_strpbrk();
Suite *suite_strrchr();
Suite *suite_strstr();
Suite *suite_strtok();
Suite *suite_strerror();
Suite *suite_strlen();
Suite *suite_strncmp();
Suite *suite_strncat();
Suite *suite_to_lower();
Suite *suite_to_upper();
Suite *suite_trim();
Suite *suite_test_sprintf_c();
Suite *suite_test_sprintf_d();
Suite *suite_test_sprintf_f();
Suite *suite_test_sprintf_e();
Suite *suite_test_sprintf_eb();
Suite *suite_test_sprintf_g();
Suite *suite_test_sprintf_gb();
Suite *suite_test_sprintf_o();
Suite *suite_test_sprintf_pr();
Suite *suite_test_sprintf_p();
Suite *suite_test_sprintf_s();
Suite *suite_test_sprintf_u();
Suite *suite_test_sprintf_x();
Suite *suite_test_sprintf_xb();
Suite *suite_test_memmove();
void run_tests();
void run_testcase(Suite *testcase);
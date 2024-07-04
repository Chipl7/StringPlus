
#include "../../s21_test.h"

START_TEST(sprintf_1_pr) {
  char str1[100];
  char str2[100];
  char *str3 = "%%c Test";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_pr) {
  char str1[100];
  char str2[100];
  char *str3 = "%%d Test";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_pr) {
  char str1[100];
  char str2[100];
  char *str3 = "%#0c Test";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_pr) {
  char str1[100];
  char str2[100];
  char *str3 = "%%f Test";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_pr(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_PR \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_pr);
  tcase_add_test(tc, sprintf_2_pr);
  tcase_add_test(tc, sprintf_3_pr);
  tcase_add_test(tc, sprintf_4_pr);

  suite_add_tcase(s, tc);
  return s;
}

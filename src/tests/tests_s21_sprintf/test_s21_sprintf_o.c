#include "../../s21_test.h"

START_TEST(sprintf_1_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int a = 0234;
  int b = 026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %ho Test %o";
  int a = 0234;
  int b = 026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%.o Test %-o Test %o";
  int a = 0234;
  int b = -026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %-ho Test %o";
  int a = 0234;
  int b = 026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_o) {
  char str1[100];
  char str2[100];
  char *str3 = "% 2o Test %3.2o Test %2o";
  int a = 0234;
  int b = 026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_o) {
  char str1[100];
  char str2[100];
  char *str3 = "%#4.5o Test %-0.2o Test %0.1o";
  int a = 0234;
  int b = 026;
  int c = 05;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_o(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_O \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_o);
  tcase_add_test(tc, sprintf_2_o);
  tcase_add_test(tc, sprintf_3_o);
  tcase_add_test(tc, sprintf_4_o);
  tcase_add_test(tc, sprintf_5_o);
  tcase_add_test(tc, sprintf_6_o);

  suite_add_tcase(s, tc);
  return s;
}

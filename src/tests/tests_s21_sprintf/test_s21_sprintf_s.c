#include "../../s21_test.h"

START_TEST(sprintf_1_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%s Test %s Test %s";
  char *a = "A23456";
  char *b = "Berfg";
  char *c = "C d";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%1s Test %0.3s Test %+1s";
  char *a = "A23456";
  char *b = "Berfg";
  char *c = "C d";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%.4s Test %+4s Test %+0s";
  char *a = "A23456";
  char *b = "Berfg";
  char *c = "C d";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "% s Test %3.4s Test %s";
  char *a = "A23456";
  char *b = "Berfg";
  char *c = "C d";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%2s Test %23s Test %+s";
  char *a = "A23456";
  char *b = "Berfg";
  char *c = "C d";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%4s Test %-s Test %.s";
  char *a = "Q W E R T Y";
  char *b = "BAaaaa";
  char *c = "ABOBA";
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_s(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_S \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_s);
  tcase_add_test(tc, sprintf_2_s);
  tcase_add_test(tc, sprintf_3_s);
  tcase_add_test(tc, sprintf_4_s);
  tcase_add_test(tc, sprintf_5_s);
  tcase_add_test(tc, sprintf_6_s);
  suite_add_tcase(s, tc);
  return s;
}

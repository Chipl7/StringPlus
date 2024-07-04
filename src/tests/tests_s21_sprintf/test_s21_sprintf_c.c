#include "../../s21_test.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c";
  char a = 'a';
  char b = 's';
  char c = ' ';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%+3c Test %-3c Test %03c";
  char a = 'a';
  char b = 's';
  char c = ' ';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%lc Test %hc Test %03c";
  char a = 'A';
  char b = 'B';
  char c = 'C';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "% c Test %#c Test %03c";
  char a = 'A';
  char b = 'B';
  char c = 'C';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%.*c Test %c Test %c";
  char a = '\0';
  char b = '\0';
  char c = 'C';
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_c(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_C \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  suite_add_tcase(s, tc);
  return s;
}

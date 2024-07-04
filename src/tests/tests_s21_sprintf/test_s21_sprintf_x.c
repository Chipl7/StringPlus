#include "../../s21_test.h"

START_TEST(sprintf_1_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%hd Test %ld Test %2ld";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%.x Test %lx Test %2.x";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %0.x Test %.x";
  int a = 0Xbf;
  int b = 056;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_x) {
  char str1[100];
  char str2[100];
  char *str3 = "%.x Test %lx Test %2.5x";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_x(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_X \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_x);
  tcase_add_test(tc, sprintf_2_x);
  tcase_add_test(tc, sprintf_3_x);
  tcase_add_test(tc, sprintf_4_x);
  suite_add_tcase(s, tc);
  return s;
}

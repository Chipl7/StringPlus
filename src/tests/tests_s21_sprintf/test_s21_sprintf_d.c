#include "../../s21_test.h"

START_TEST(sprintf_1_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %hd Test %ld";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%+d Test %+d Test %+d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%-2d Test %-2d Test %-2d";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_d) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.0d Test %ld Test %2ld";
  int a = -2147483648;
  int b = 0;
  int c = 2147483647;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_d(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_D \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_d);
  tcase_add_test(tc, sprintf_2_d);
  tcase_add_test(tc, sprintf_3_d);
  tcase_add_test(tc, sprintf_4_d);

  suite_add_tcase(s, tc);
  return s;
}

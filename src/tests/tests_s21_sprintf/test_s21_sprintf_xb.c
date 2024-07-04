#include "../../s21_test.h"

START_TEST(sprintf_1_xb) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %hX Test %.X";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_xb) {
  char str1[100];
  char str2[100];
  char *str3 = "%.X Test %lX Test %2lX";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_xb) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %0.X Test %.X";
  int a = 0Xbf;
  int b = 056;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_xb) {
  char str1[100];
  char str2[100];
  char *str3 = "%.X Test %lX Test %2.5X";
  int a = 0Xbf;
  int b = 0X56;
  int c = 0x565;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_xb(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_Xb \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_xb);
  tcase_add_test(tc, sprintf_2_xb);
  tcase_add_test(tc, sprintf_3_xb);
  tcase_add_test(tc, sprintf_4_xb);
  suite_add_tcase(s, tc);
  return s;
}

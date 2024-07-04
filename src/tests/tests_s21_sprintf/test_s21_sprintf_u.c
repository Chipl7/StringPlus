#include "../../s21_test.h"

START_TEST(sprintf_1_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test ";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test  %hu";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_u) {
  char str1[100];
  char str2[100];
  char *str3 = "% u Test %4.3u";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%4.5u Test  %hu";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.5u Test  %0u";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_u) {
  char str1[100];
  char str2[100];
  char *str3 = "% 10u Test  %0.23u";
  int a = 12;

  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
Suite *suite_test_sprintf_u(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_U \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_u);
  tcase_add_test(tc, sprintf_2_u);
  tcase_add_test(tc, sprintf_3_u);
  tcase_add_test(tc, sprintf_4_u);
  tcase_add_test(tc, sprintf_5_u);
  tcase_add_test(tc, sprintf_6_u);
  suite_add_tcase(s, tc);
  return s;
}

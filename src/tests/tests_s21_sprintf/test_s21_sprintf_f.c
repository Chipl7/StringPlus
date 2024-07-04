#include "../../s21_test.h"

START_TEST(sprintf_1_f) {
  char str1[100];
  char str2[100];
  char *str3 = "%f Test %f Test %f";
  double a = 12.3;
  double b = 12;
  double c = 0.111;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[100];
  char str2[100];
  char *str3 = "%2f Test %hf Test %f";
  double a = 12.3;
  double b = 12;
  double c = 0.111;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[100];
  char str2[100];
  char *str3 = "%lf Test %hf Test %.f";
  double a = 12.3;
  double b = 12;
  double c = 0.111;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[100];
  char str2[100];
  char *str3 = "%-0.f Test %hf Test %.f";
  double a = -12.3;
  double b = 12;
  double c = 0.111;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
Suite *suite_test_sprintf_f(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_F \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_f);
  tcase_add_test(tc, sprintf_2_f);
  tcase_add_test(tc, sprintf_3_f);
  tcase_add_test(tc, sprintf_4_f);
  suite_add_tcase(s, tc);
  return s;
}

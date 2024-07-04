#include "../../s21_test.h"

START_TEST(sprintf_1_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%G Test %G Test %G";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%2G Test % lG Test %hG";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%+G Test % -0G Test %+2.0G";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%1.2G Test %1.G Test %2.G";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.2G Test %2G Test %+G";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_gb) {
  char str1[100];
  char str2[100];
  char *str3 = "%+G Test %-G Test % -G";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_gb(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_G \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_gb);
  tcase_add_test(tc, sprintf_2_gb);
  tcase_add_test(tc, sprintf_3_gb);
  tcase_add_test(tc, sprintf_4_gb);
  tcase_add_test(tc, sprintf_5_gb);
  tcase_add_test(tc, sprintf_6_gb);
  suite_add_tcase(s, tc);
  return s;
}

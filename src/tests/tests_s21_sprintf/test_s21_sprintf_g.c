#include "../../s21_test.h"

START_TEST(sprintf_1_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%lg Test %g Test %4g";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}

START_TEST(sprintf_2_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%2g Test % lg Test %hg";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%+g Test % -0g Test %+2.0g";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%1.2g Test %1.g Test %2.g";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.2g Test %2g Test %+g";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[100];
  char str2[100];
  char *str3 = "%+g Test %-g Test % -g";
  double a = -21.47483648;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

END_TEST
Suite *suite_test_sprintf_g(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_G \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_g);
  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  suite_add_tcase(s, tc);
  return s;
}

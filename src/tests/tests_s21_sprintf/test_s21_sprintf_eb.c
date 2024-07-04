
#include "../../s21_test.h"

START_TEST(sprintf_1_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%E Test %2E Test %E";
  double a = 33.3455432345;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%10.2E Test %2E Test %.E";
  double a = 33.3455432345;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%+E Test %+3.1E Test %10.2E";
  double a = -33.3455432345;
  double c = 32.34545;
  double b = 0.373;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%+E Test %+2E Test %-E";
  double a = 33.3455432345;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.0E Test %-2E Test %+10.2E";
  double a = 33.3455432345;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a),
                   s21_sprintf(str2, str3, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_eb) {
  char str1[100];
  char str2[100];
  char *str3 = "%0.3E Test %+lE Test %10.2E";
  double a = 33.3455432345;
  double c = 32.34545;
  double b = 0.373;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_eb(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_Eb \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_eb);
  tcase_add_test(tc, sprintf_2_eb);
  tcase_add_test(tc, sprintf_3_eb);
  tcase_add_test(tc, sprintf_4_eb);
  tcase_add_test(tc, sprintf_5_eb);
  tcase_add_test(tc, sprintf_6_eb);

  suite_add_tcase(s, tc);
  return s;
}

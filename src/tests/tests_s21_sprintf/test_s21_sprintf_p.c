#include "../../s21_test.h"

START_TEST(sprintf_1_p) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  long int a = 0x7fffa40c5fac;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_p) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  long int a = 0x7fffa40c5fac;
  long int b = 0x7fffc;
  long int c = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_p) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  long int a = 0x86cc;
  long int b = 0x7fffc;
  long int c = 0x86cc;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c),
                   s21_sprintf(str2, str3, a, b, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_p) {
  char str1[100];
  char str2[100];
  char *str3 = "%lp Test %lp Test %hp GpD %hp";
  long long int a = 0x7aaaa40c5fac;
  long long b = 0x86cc;
  long int c = 0x7fffc;
  long int d = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_p) {
  char str1[200];
  char str2[200];
  char *str3 = "%p Test %p Test %p TEST %p";
  long int a = 0x86cc;
  long int b = 0x7fffa40c5fac;
  long int c = 0x7fffa40c5fac;
  long int d = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_p) {
  char str1[200];
  char str2[200];
  char *str3 = "%-p Test %-p Test %-p TEST %-p";
  long int a = 0x86cc;
  long int b = 0x0abbac;
  long int c = 0x7fffa40c5fac;
  long int d = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d),
                   s21_sprintf(str2, str3, a, b, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_p) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %0p Test %0p TEST %0p GpD %0p";
  long int a = 0x0abbac;
  long int b = 0x7fffc;
  long int c = 0x86cc;
  long int d = 0x3ffac;
  long int e = 0x0;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suite_test_sprintf_p(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_P \033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_p);
  tcase_add_test(tc, sprintf_2_p);
  tcase_add_test(tc, sprintf_3_p);
  tcase_add_test(tc, sprintf_4_p);
  tcase_add_test(tc, sprintf_5_p);
  tcase_add_test(tc, sprintf_6_p);
  tcase_add_test(tc, sprintf_7_p);

  suite_add_tcase(s, tc);
  return s;
}

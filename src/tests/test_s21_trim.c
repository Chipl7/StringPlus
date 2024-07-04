#include "../s21_test.h"

START_TEST(trim_1) {
  char str[] = "* Hello, world! *";
  char expected[] = " *";
  char *ch = s21_trim(str, expected);
  ck_assert_str_eq(ch, "Hello, world!");
  if (ch) free(ch);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "* Hello, world! *";
  char expected[] = "";
  char *ch = s21_trim(str, expected);
  ck_assert_str_eq(ch, "* Hello, world! *");
  if (ch) free(ch);
}
END_TEST

START_TEST(trim_3) {
  char str[] = "Hello, world!";
  char expected[] = " *";
  char *ch = s21_trim(str, expected);
  ck_assert_str_eq(ch, "Hello, world!");
  if (ch) free(ch);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "ABC";
  char expected[] = "abc";
  char *ch = s21_trim(str, expected);
  ck_assert_str_eq(ch, "ABC");
  if (ch) free(ch);
}
END_TEST

START_TEST(trim_5) {
  char str[] = "";
  char *ch = s21_trim(str, NULL);
  ck_assert_ptr_eq(ch, NULL);
  if (ch) free(ch);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("\033[45m-=S21_TRIM=-\033[0m");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  suite_add_tcase(s, tc);
  return s;
}

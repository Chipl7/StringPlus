#include "../s21_test.h"

START_TEST(to_upper_1) {
  char str[] = "hello, world!";
  char expected[] = "HELLO, WORLD!";
  char *ch = s21_to_upper(str);
  ck_assert_str_eq(ch, expected);
  if (ch) free(ch);
}
END_TEST

START_TEST(to_upper_2) {
  char str[] = "HELLO, WORLD!";
  char expected[] = "HELLO, WORLD!";
  char *ch = s21_to_upper(str);
  ck_assert_str_eq(ch, expected);
  if (ch) free(ch);
}
END_TEST

START_TEST(to_upper_3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *ch = s21_to_upper(str);
  ck_assert_str_eq(ch, expected);
  if (ch) free(ch);
}
END_TEST

START_TEST(to_upper_4) {
  char str[] = " ";
  char expected[] = " ";
  char *ch = s21_to_upper(str);
  ck_assert_str_eq(ch, expected);
  if (ch) free(ch);
}
END_TEST

START_TEST(to_upper_5) {
  char *ch = s21_to_upper(NULL);
  ck_assert_ptr_eq(ch, NULL);
  if (ch) free(ch);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_UPPER=-\033[0m");
  TCase *tc = tcase_create("to_upper_tc");

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);
  tcase_add_test(tc, to_upper_5);

  suite_add_tcase(s, tc);
  return s;
}

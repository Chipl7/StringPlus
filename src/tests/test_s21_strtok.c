#include "../s21_test.h"

START_TEST(strtok_1) {
  char str1[] = "aaa";
  char str2[] = "aaa";
  char *delim = "a";

  s21_strtok(str1, delim);
  strtok(str2, delim);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "aaabbbccc";
  char str2[] = "aaabbbccc";
  char *delim = "a";

  s21_strtok(str1, delim);
  strtok(str2, delim);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strtok_3) {
  char str1[] = "qwert";
  char str2[] = "qwert";
  char *delim = "a";

  s21_strtok(str1, delim);
  strtok(str2, delim);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strtok_4) {
  char str1[] = "ABC";
  char str2[] = "ABC";
  char *delim = "a";

  s21_strtok(str1, delim);
  strtok(str2, delim);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "";
  char str2[] = "";
  char *delim = "a";

  s21_strtok(str1, delim);
  strtok(str2, delim);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("\033[45m-=S21_STRTOK=-\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);

  suite_add_tcase(s, tc);
  return s;
}
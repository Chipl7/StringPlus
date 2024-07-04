#include "../s21_test.h"

START_TEST(strlen_1) {
  char str1[] = "aaa";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_2) {
  char str1[] = "AAAaaa";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_3) {
  char str1[] = "asdasd\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_4) {
  char str1[] = "112\03123";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_5) {
  char str1[] = "\0asdasd1";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("\033[45m-=S21_STRLEN=-\033[0m");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);

  suite_add_tcase(s, tc);
  return s;
}
#include "../s21_test.h"

START_TEST(strchr_1) {
  char str1[] = "aaa";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_2) {
  char str1[] = "bbb";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_3) {
  char str1[] = "AAA";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_4) {
  char str1[] = "222";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_5) {
  char str1[] = "aaabbbaaa";
  char ch = 'b';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_6) {
  char str1[] = "a\0aab";
  char ch = 'b';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_7) {
  char str1[] = "aaa";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_8) {
  char str1[] = "aaac\0";
  char ch = 'c';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_9) {
  char str1[] = "aaBBa";
  char ch = 'B';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

START_TEST(strchr_10) {
  char str1[] = "aaBBa";
  char ch = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, ch), strchr(str1, ch));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);

  suite_add_tcase(s, tc);
  return s;
}

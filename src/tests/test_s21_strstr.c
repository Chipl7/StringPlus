#include "../s21_test.h"

START_TEST(strstr_1) {
  char str1[] = "aaaa";
  char str2[] = "aaaa";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char str1[] = "aaaabbbb";
  char str2[] = "aaaa";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char str1[] = "aaaabbbccc";
  char str2[] = "aaaabbbccc";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char str1[] = "aaaa";
  char str2[] = "asdfaaabbbb";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char str1[] = "AAAA";
  char str2[] = "aaaa";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char str1[] = "aaaa";
  char str2[] = "AAAA";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_7) {
  char str1[] = "BBBB";
  char str2[] = "AAAA";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_8) {
  char str1[] = "aaAa";
  char str2[] = "aAaa";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_9) {
  char str1[] = "CCCC";
  char str2[] = "BBBC";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_10) {
  char str1[] = "69";
  char str2[] = "96";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRSTR=-\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);

  suite_add_tcase(s, tc);
  return s;
}
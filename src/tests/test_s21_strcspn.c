#include "../s21_test.h"

START_TEST(strcspn_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "abc";
  char str2[] = "fvc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "aaa";
  char str2[] = "bbb";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "ABC";
  char str2[] = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] = "111";
  char str2[] = "222";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "sdfsdf";
  char str2[] = "45345";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "345345";
  char str2[] = "asdasdasdqwe";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "77777774";
  char str2[] = "888888666400";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char str1[] = "2\0111";
  char str2[] = "222";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  char str1[] = "111\02";
  char str2[] = "222";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_11) {
  char str1[] = "11\01999";
  char str2[] = "999";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_12) {
  char str1[] = "111aaa*()(2)123";
  char str2[] = "222:";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_13) {
  char str1[] = "11nuLL1";
  char str2[] = "22NUll2";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_14) {
  char str1[] = "11661";
  char str2[] = "22299";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_15) {
  char str1[] = "1ttt11";
  char str2[] = "22uuu2";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCSPN=-\033[0m");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);
  tcase_add_test(tc, strcspn_12);
  tcase_add_test(tc, strcspn_13);
  tcase_add_test(tc, strcspn_14);
  tcase_add_test(tc, strcspn_15);

  suite_add_tcase(s, tc);
  return s;
}
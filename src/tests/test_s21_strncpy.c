#include "../s21_test.h"

START_TEST(strncpy_1) {
  char str1[] = "";
  char str2[] = "";
  char cpy[] = "";
  s21_size_t n = 0;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strncpy_2) {
  char str1[] = "123";
  char str2[] = "123";
  char cpy[] = "123";
  s21_size_t n = 0;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strncpy_3) {
  char str1[] = "123";
  char str2[] = "123";
  char cpy[] = "ABC";
  s21_size_t n = 0;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strncpy_4) {
  char str1[] = " ";
  char str2[] = " ";
  char cpy[] = "ABC";
  s21_size_t n = 1;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strncpy_5) {
  char str1[] = "123";
  char str2[] = "123";
  char cpy[] = "123";
  s21_size_t n = 2;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(strncpy_6) {
  char str1[] = "Str1ng";
  char str2[] = "Str1ng";
  char cpy[] = "Str1ng";
  s21_size_t n = 7;

  s21_strncpy(str1, cpy, n);
  strncpy(str2, cpy, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCPY=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);

  suite_add_tcase(s, tc);
  return s;
}
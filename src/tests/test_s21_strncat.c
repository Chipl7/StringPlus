#include "../s21_test.h"

START_TEST(strncat_1) {
  char str1[1024] = "bbb";
  char str2[1024] = "aaa";
  char str3[1024] = "aaa";
  int n = 10;

  s21_strncat(str2, str1, n);
  strncat(str3, str1, n);

  ck_assert_mem_ge(str2, str3, n);
}
END_TEST

START_TEST(strncat_2) {
  char src[] = "";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 0;

  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);

  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_3) {
  char src[] = "abosal";
  char res[10] = "";
  char expected[10] = "";
  s21_size_t n_byte = 0;

  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);

  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_4) {
  char str1[1024] = "_____\0";
  char str2[1024] = "\0______";
  char str3[1024] = "\0\0\0";
  int n = 10;

  s21_strncat(str2, str1, n);
  strncat(str3, str1, n);

  ck_assert_mem_ge(str2, str3, n);
}
END_TEST

START_TEST(strncat_5) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 5;

  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);

  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);

  suite_add_tcase(s, tc);
  return s;
}
#include "../s21_test.h"

START_TEST(strcpy_1) {
  char src[] = " floppa!!!";
  char res[5 + 15] = "aboba ";
  char expected[5 + 15] = "aboba ";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_2) {
  char src[] = "Floppa!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_3) {
  char src[] = "";
  char res[5 + 15] = "abobas";
  char expected[5 + 15] = "abobas";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_4) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_5) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCPY=-\033[0m");
  TCase *tc = tcase_create("strcpy_tc");

  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strcpy_4);
  tcase_add_test(tc, strcpy_5);

  suite_add_tcase(s, tc);
  return s;
}
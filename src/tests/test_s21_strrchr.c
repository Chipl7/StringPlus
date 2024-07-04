#include "../s21_test.h"

START_TEST(strrchr_1) {
  char buffer[] = "aaa";
  int n = 'a';
  ck_assert_ptr_eq(s21_strrchr(buffer, n), strrchr(buffer, n));
}
END_TEST

START_TEST(strrchr_2) {
  char buffer[] = "abbb";
  int n = 'a';
  ck_assert_ptr_eq(s21_strrchr(buffer, n), strrchr(buffer, n));
}
END_TEST

START_TEST(strrchr_3) {
  char buffer[] = "bbbbb";
  int n = 'a';
  ck_assert_ptr_eq(s21_strrchr(buffer, n), strrchr(buffer, n));
}
END_TEST

START_TEST(strrchr_4) {
  char buffer[] = "abbbbbabbbbbbbbbbabb";
  int n = 'a';
  ck_assert_ptr_eq(s21_strrchr(buffer, n), strrchr(buffer, n));
}
END_TEST

START_TEST(strrchr_5) {
  char buffer[] = "aaaa";
  int n = 'A';
  ck_assert_ptr_eq(s21_strrchr(buffer, n), strrchr(buffer, n));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);

  suite_add_tcase(s, tc);
  return s;
}
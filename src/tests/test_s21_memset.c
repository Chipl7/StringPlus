#include "../s21_test.h"

START_TEST(memset_1) {
  char str1[] = "aaa";
  char str2[] = "aaa";
  char ch = 'a';
  s21_size_t n = 3;

  s21_memset(str1, ch, n);
  memset(str2, ch, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_2) {
  char str1[] = "bbb";
  char str2[] = "bbb";
  char ch = 'a';
  s21_size_t n = 1;

  s21_memset(str1, ch, n);
  memset(str2, ch, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_3) {
  char str1[] = "AAA";
  char str2[] = "AAA";
  char ch = 'a';
  s21_size_t n = 2;

  s21_memset(str1, ch, n);
  memset(str2, ch, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_4) {
  char str1[] = " ";
  char str2[] = " ";
  char ch = 'a';
  s21_size_t n = 1;

  s21_memset(str1, ch, n);
  memset(str2, ch, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(memset_5) {
  char str1[] = "aaaaaaaa";
  char str2[] = "aaaaaaaa";
  char ch = 'b';
  s21_size_t n = 1;

  s21_memset(str1, ch, n);
  memset(str2, ch, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);

  suite_add_tcase(s, tc);
  return s;
}
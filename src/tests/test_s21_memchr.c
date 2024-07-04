#include "../s21_test.h"

START_TEST(memchr_1) {
  char str[] = "abc";
  char ch = 'a';
  s21_size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "abc";
  char ch = 'b';
  s21_size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "abc";
  char ch = 'c';
  s21_size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "abc";
  char ch = 'd';
  s21_size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "abc";
  char ch = 'a';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "abc";
  char ch = 'b';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "abc";
  char ch = 'c';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "abcabcabc";
  char ch = 'd';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "abc";
  char ch = 'a';
  s21_size_t n = 1;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "abc";
  char ch = 'b';
  s21_size_t n = 1;
  ck_assert_ptr_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCHR=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);

  suite_add_tcase(s, tc);
  return s;
}
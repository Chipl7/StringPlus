#include "../s21_test.h"

START_TEST(memcmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "adbc";
  char str2[] = "abc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "abc";
  char str2[] = "adbc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "abc";
  char str2[] = "abc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "abddc";
  char str2[] = "addbc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "+";
  char str2[] = "-";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "a\0bc";
  char str2[] = "a\0bc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "dddddddddddabc";
  char str2[] = "dddddddddddabc";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "aaa";
  char str2[] = "bbb";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "abcccc";
  char str2[] = "abbbbbc";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCMP=-\033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);

  suite_add_tcase(s, tc);
  return s;
}
#include "../s21_test.h"

START_TEST(memcpy_1) {
  char str1[] = "abc";
  char str2[1024];
  char str3[1024];
  s21_size_t n = 4;

  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);

  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

START_TEST(memcpy_2) {
  char str1[] = " ";
  char str2[1024];
  char str3[1024];
  s21_size_t n = 1;

  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);

  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

START_TEST(memcpy_3) {
  char str1[] = "123";
  char str2[1024];
  char str3[1024];
  s21_size_t n = 4;

  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);

  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

START_TEST(memcpy_4) {
  char str1[] = "";
  char str2[1024];
  char str3[1024];
  s21_size_t n = 0;

  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);

  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

START_TEST(memcpy_5) {
  char str1[] = "ABC";
  char str2[1024];
  char str3[1024];
  s21_size_t n = 4;

  s21_memcpy(str2, str1, n);
  memcpy(str3, str1, n);

  ck_assert_mem_eq(str2, str3, n);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);

  suite_add_tcase(s, tc);
  return s;
}
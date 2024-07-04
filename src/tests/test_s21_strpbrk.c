#include "../s21_test.h"

START_TEST(strpbrk_1) {
  char str1[] = "aaa";
  char str2[] = "bbb";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[] = "aaa";
  char str2[] = "aaa";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[] = "aaa";
  char str2[] = "bbbaaa";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[] = "aaa";
  char str2[] = "AAA";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[] = "AAA";
  char str2[] = "aaa";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=S21_STRPBRK=-\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);

  suite_add_tcase(s, tc);
  return s;
}
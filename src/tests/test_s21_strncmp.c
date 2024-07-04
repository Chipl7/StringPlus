#include "../s21_test.h"

START_TEST(strncmp_1) {
  char str1[] = "aaa";
  char str2[] = "aaa";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "aaBBa";
  char str2[] = "aaBBa";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "cccc";
  char str2[] = "cccc";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "CCCCC";
  char str2[] = "CCCCCC";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "AaBBa";
  char str2[] = "aaBBa";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "aaBBa";
  char str2[] = "AaBBa";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] = "aaBBa";
  char str2[] = "AaBBa";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char str1[] = "aassssBBa";
  char str2[] = "AasSssBBa";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = "aaBqweqweBa";
  char str2[] = "AqweqweaBBa";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char str1[] = "aaBBtetwea";
  char str2[] = "AaBBwetwetweta";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char str1[] = "aasSssBBa";
  char str2[] = "AassssBBa";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_12) {
  char str1[] = "aanull\0ssssBBa";
  char str2[] = "aanull\0ssssBBa";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCMP=-\033[0m");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);
  tcase_add_test(tc, strncmp_12);

  suite_add_tcase(s, tc);
  return s;
}
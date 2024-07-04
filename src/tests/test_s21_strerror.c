#include "../s21_test.h"

START_TEST(strerror_1) {
  ck_assert(strncmp(s21_strerror(1000), strerror(1000), 12) == 0);
}
END_TEST

START_TEST(strerror_2) {
  char *x = s21_strerror(0);
  char *y = strerror(0);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_3) {
  char *x = s21_strerror(66);
  char *y = strerror(66);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_4) {
  char *x = s21_strerror(44);
  char *y = strerror(44);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_5) {
  char *x = s21_strerror(110);
  char *y = strerror(110);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_6) {
  char *x = s21_strerror(-1);
  char *y = strerror(-1);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_7) {
  char *x = s21_strerror(666);
  char *y = strerror(666);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_8) {
  char *x = s21_strerror(136);
  char *y = strerror(136);
  ck_assert_str_eq(x, y);
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);
  tcase_add_test(tc, strerror_7);
  tcase_add_test(tc, strerror_8);

  suite_add_tcase(s, tc);
  return s;
}
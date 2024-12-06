#include "../s21_test.h"


START_TEST(strerror_1) {
  char *x = s21_strerror(0);
  char *y = strerror(0);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_2) {
  char *x = s21_strerror(66);
  char *y = strerror(66);
  ck_assert_str_eq(x, y);
}
END_TEST

START_TEST(strerror_3) {
  char *x = s21_strerror(44);
  char *y = strerror(44);
  ck_assert_str_eq(x, y);
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);

  suite_add_tcase(s, tc);
  return s;
}
#include "../s21_test.h"

START_TEST(insert_1) {
  char str[] = "HELLO, WORLD!";
  char replace[] = "earth";
  s21_size_t n = 2;
  char *ch = s21_insert(str, replace, n);
  ck_assert_str_eq(ch, "HEearthLLO, WORLD!");
  free(ch);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "hello, world!";
  char replace[] = "earth";
  s21_size_t n = 2;
  char *ch = s21_insert(str, replace, n);
  ck_assert_str_eq(ch, "heearthllo, world!");
  free(ch);
}
END_TEST

START_TEST(insert_3) {
  char str[] = "earth";
  char replace[] = "earth";
  s21_size_t n = 2;
  char *ch = s21_insert(str, replace, n);
  ck_assert_str_eq(ch, "eaearthrth");
  free(ch);
}
END_TEST

START_TEST(insert_4) {
  char str[] = "earth";
  char replace[] = "Hello, verter!";
  s21_size_t n = 10;
  char *ch = s21_insert(str, replace, n);
  ck_assert_ptr_eq(ch, NULL);
  free(ch);
}
END_TEST

START_TEST(insert_5) {
  char str[] = "";
  char replace[] = "Hello, verter!";
  s21_size_t n = 10;
  char *ch = s21_insert(str, replace, n);
  ck_assert_ptr_eq(ch, NULL);
  free(ch);
}
END_TEST

START_TEST(insert_6) {
  char str[] = "earth";
  char replace[] = "";
  s21_size_t n = 10;
  char *ch = s21_insert(str, replace, n);
  ck_assert_ptr_eq(ch, NULL);
  free(ch);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("\033[45m-=S21_INSERT=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);

  suite_add_tcase(s, tc);
  return s;
}
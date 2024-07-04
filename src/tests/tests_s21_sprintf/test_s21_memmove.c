#include "../../s21_test.h"

START_TEST(s21_memmove_1) {
  char stc1[100] = "Hello, World! This is a test string.";
  char stc2[100] = {0};
  char stc3[100] = {0};
  size_t size = 20;

  memmove(stc2, stc1, size);
  s21_memmove(stc3, stc1, size);
  ck_assert_pstr_eq(stc2, stc3);
}
END_TEST

START_TEST(s21_memmove_2) {
  char stc1[100] = "Hello, World!.";
  char stc2[100] = {0};
  char stc3[100] = {0};
  size_t size = 1;

  memmove(stc2, stc1, size);
  s21_memmove(stc3, stc1, size);
  ck_assert_pstr_eq(stc2, stc3);
}
END_TEST

START_TEST(s21_memmove_3) {
  char stc1[50] = "Hello.";
  char stc2[50] = {0};
  char stc3[50] = {0};
  size_t size = 10;

  memmove(stc2, stc1, size);
  s21_memmove(stc3, stc1, size);
  ck_assert_pstr_eq(stc2, stc3);
}
END_TEST

Suite *suite_test_memmove(void) {
  Suite *s = suite_create("\033[45m S21_SPRINTF_MEMMOVE \033[0m");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, s21_memmove_1);
  tcase_add_test(tc, s21_memmove_2);
  tcase_add_test(tc, s21_memmove_3);
  suite_add_tcase(s, tc);
  return s;
}
#include "../../s21_test.h"

START_TEST(sscanf_spec_hhd_1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhd_2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhd_3) {
  char format[] = "%hhd";
  char str[] = "+123";
  signed char d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hhd_4) {
  char format[] = "%3hhd";
  char str[] = "-123";
  signed char d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_16) {
  char format[] = "%lld";
  char str[] = "214743483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_17) {
  char format[] = "%lld";
  char str[] = "-2147483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *suite_sscanf_d(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_D=-\033[0m");
  TCase *tc = tcase_create("sscanf_d_tc");

  tcase_add_test(tc, sscanf_spec_hhd_1);
  tcase_add_test(tc, sscanf_spec_hhd_2);
  tcase_add_test(tc, sscanf_spec_hhd_3);
  tcase_add_test(tc, sscanf_spec_hhd_4);
  tcase_add_test(tc, sscanf_spec_lld_16);
  tcase_add_test(tc, sscanf_spec_lld_17);

  suite_add_tcase(s, tc);
  return s;
}

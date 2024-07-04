#include "../../s21_test.h"

START_TEST(sscanf_spec_hho_6) {
  char format[] = "%*hho %*hho %*hho";
  char str[] = "0123 +04 -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_1) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_1) {
  char format[] = "%o%o%o";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_6) {
  char format[] = "%*o %*o %*o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_2) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +1564 -1723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_6) {
  char format[] = "%*llo %*llo %*llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *suite_sscanf_o(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_O=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hho_6);
  tcase_add_test(tc, sscanf_spec_ho_1);
  tcase_add_test(tc, sscanf_spec_o_1);
  tcase_add_test(tc, sscanf_spec_o_6);
  tcase_add_test(tc, sscanf_spec_lo_2);
  tcase_add_test(tc, sscanf_spec_llo_6);

  suite_add_tcase(s, tc);
  return s;
}

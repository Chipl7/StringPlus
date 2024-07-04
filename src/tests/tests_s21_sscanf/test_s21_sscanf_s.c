#include "../../s21_test.h"

START_TEST(sscanf_spec_s_1) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_spec_s_2) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

Suite *suite_sscanf_s(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_S=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);

  suite_add_tcase(s, tc);
  return s;
}

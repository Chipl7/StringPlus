#ifndef S21_STRING_H
#define S21_STRING_H
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

typedef struct Format {
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int width;
  int precision;
  char len;
  char tem;
} Flag;

void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
int s21_sprintf(char *str, const char *format, ...);
void s21_set_flag(Flag *spec, const char *format);
char *s21_str_to_int(const char *format, int *number, va_list *args);
char *s21_format_param_to_str(char **point_str, Flag *spec, va_list *args);
int s21_flag(char ch);
int s21_digit(char ch);
int s21_len(char ch);
int s21_spec(char ch);
int s21_is_valid_char(char ch, const char *valid_chars);
char *s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t len);
char *s21_ll_width_flag(char *str, Flag *spec);
char *s21_ll_to_str(char *str, long long number);
char *s21_reverse_str(char *str);
char *s21_leE_to_str(char *str, long double number, Flag *spec);
char *s21_sign_flag(char *str, Flag *spec);
char *s21_lf_width_flag(char *str, Flag *spec);
char *s21_lf_to_str(char *str, long double number, Flag *spec);
char *s21_ld_to_a(char *str, long double number, Flag *spec);
char *s21_d_class_to_str(char *str, long double x, int precision);
long double s21_round(long double x, int precision);
char *s21_ll_precision(char *str, Flag *spec);
char *s21_hl_to_str(char *str, unsigned long long number, Flag *spec);
char **s21_sprintf_c(char **point_str, va_list *args, Flag *spec);
char *s21_sprintf_d(char *str, va_list *args, Flag *spec);
char *s21_sprintf_e_E(char *str, va_list *args, Flag *spec);
char *s21_sprintf_f(char *str, va_list *args, Flag *spec);
char *s21_sprintf_g_G(char *str, va_list *args, Flag *spec);
char *s21_sprintf_o(char *str, va_list *args, Flag *spec);
char *s21_sprintf_p(char *str, va_list *argList, Flag *spec);
char *s21_sprintf_perc(char *str, Flag *spec);
char *s21_sprintf_s(char *str, va_list *args, Flag *spec);
char *s21_sprintf_u(char *str, va_list *args, Flag *spec);
char *s21_sprintf_x_X(char *str, va_list *args, Flag *spec);

#endif  // S21_STRING_H

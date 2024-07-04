#include "../../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL || start_index > sizeof(src)) {
    return s21_NULL;
  }
  char *s = s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  s21_size_t sum_len = str_len + src_len;
  if (start_index <= src_len) {
    s = (char *)calloc(src_len + str_len + 1, sizeof(char));
  }
  if (s) {
    for (s21_size_t i = 0; i < sum_len; i++) {
      if (i < start_index) {
        s[i] = src[i];
      } else if (i < str_len + start_index) {
        s[i] = str[i - start_index];
      } else {
        s[i] = src[i - str_len];
      }
    }
  }
  return s;
}
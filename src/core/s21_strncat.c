#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int j = 0;
  for (int i = 0; dest[i] != '\0'; i++) {
    j++;
  }
  for (s21_size_t i = 0; i < n; i++) {
    dest[j] = src[i];
    j++;
  }
  return dest;
}
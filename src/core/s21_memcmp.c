#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *s1 = str1;
  const char *s2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] > s2[i]) {
      return s1[i] - s2[i];
    }
    if (s1[i] < s2[i]) {
      return s1[i] - s2[i];
    }
  }
  return 0;
}
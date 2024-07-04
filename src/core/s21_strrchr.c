#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *ptr = s21_NULL;
  s21_size_t i = 0;
  while (str[i] != '\0') {
    if (str[i] == c) {
      ptr = (char *)(str + i);
    }
    i++;
  }
  if (c == '\0') {
    ptr = (char *)(str + i);
  }
  return ptr;
}
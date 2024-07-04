#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;

  if (str != s21_NULL) {
    for (; str[0] != '\0'; str++) {
      if (str[0] == c) {
        result = (char *)str;
        break;
      }
    }
    if (str[0] == c) {
      result = (char *)str;
    }
  }
  return result;
}
#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}
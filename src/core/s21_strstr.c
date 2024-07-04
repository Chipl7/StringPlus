#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') return (char *)haystack;
  char *ptr = s21_NULL;
  s21_size_t i = 0;
  while (haystack[i] != '\0' && ptr == s21_NULL) {
    ptr = (char *)(haystack + i);
    s21_size_t j = 0;
    while (haystack[i + j] != '\0' && needle[j] != '\0' && ptr != s21_NULL) {
      if (haystack[i + j] != needle[j]) ptr = s21_NULL;
      j++;
    }
    if (ptr != s21_NULL && needle[j] != '\0') ptr = s21_NULL;
    i++;
  }
  return ptr;
}
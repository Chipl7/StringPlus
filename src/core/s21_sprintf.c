#include "../s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  s21_size_t flag = 0, error = 0;
  char *str_start = str;
  char *point_str = str;

  str = s21_strcpy(str, "");
  while (*format && error == 0) {
    Flag formatSpec = {0};
    formatSpec.width = formatSpec.precision = -1;
    if (*format == '%') {
      flag = 1;
      format++;
    } else {
      *point_str = *format;
      point_str++;
      *point_str = '\0';
      format++;
    }

    if (flag == 1) {
      if (s21_flag(*format))
        while (s21_flag(*format)) s21_set_flag(&formatSpec, format++);

      if ((s21_digit(*format) || *format == '*'))
        format = s21_str_to_int(format, &formatSpec.width, &args);

      if (*format == '.') {
        formatSpec.precision = 0;
        format = s21_str_to_int(++format, &formatSpec.precision, &args);
      }

      if (s21_len(*format)) formatSpec.len = *(format++);
      if (s21_spec(*format)) formatSpec.tem = *(format++);

      s21_format_param_to_str(&point_str, &formatSpec, &args);
      flag = 0;
    }
  }

  va_end(args);
  if (error != 0) *str_start = '\0';
  return error == 0 ? (int)(point_str - str) : -1;
}

void s21_set_flag(Flag *formatSpec, const char *format) {
  switch (*format) {
    case '-':
      formatSpec->minus = 1;
      break;
    case '+':
      formatSpec->plus = 1;
      break;
    case ' ':
      formatSpec->space = 1;
      break;
    case '#':
      formatSpec->sharp = 1;
      break;
    case '0':
      formatSpec->zero = 1;
      break;
  }
}

char *s21_str_to_int(const char *format, int *number, va_list *args) {
  *number = 0;
  while (s21_digit(*format)) {
    *number = *format - '0' + *number * 10;
    format++;
  }
  if (*format == '*') {
    *number = va_arg(*args, int);
    format++;
  }
  return (char *)format;
}

char *s21_format_param_to_str(char **point_str, Flag *formatSpec,
                              va_list *args) {
  char *temp_str = s21_NULL;
  temp_str = calloc(1000 + formatSpec->width + 2, sizeof(char));

  int flag_c = 0;
  if (temp_str != s21_NULL) {
    switch (formatSpec->tem) {
      case 'c':
        s21_sprintf_c(point_str, args, formatSpec);
        flag_c = 1;
        break;
      case 'd':
        s21_sprintf_d(temp_str, args, formatSpec);
        break;
      case 'e':
      case 'E':
        s21_sprintf_e_E(temp_str, args, formatSpec);
        break;
      case 'f':
        s21_sprintf_f(temp_str, args, formatSpec);
        break;
      case 'g':
      case 'G':
        s21_sprintf_g_G(temp_str, args, formatSpec);
        break;
      case 'o':
        s21_sprintf_o(temp_str, args, formatSpec);
        break;
      case 's':
        s21_sprintf_s(temp_str, args, formatSpec);
        break;
      case 'u':
        s21_sprintf_u(temp_str, args, formatSpec);
        break;
      case 'x':
      case 'X':
        s21_sprintf_x_X(temp_str, args, formatSpec);
        break;
      case 'p':
        s21_sprintf_p(temp_str, args, formatSpec);
        break;
      case '%':
        s21_sprintf_perc(temp_str, formatSpec);
        break;
    }

    if (!flag_c) {
      s21_strcat(*point_str, temp_str);
      *point_str += s21_strlen(temp_str);
    }
    free(temp_str);
  }
  return *point_str;
}

int s21_flag(char ch) { return s21_is_valid_char(ch, "-+ #0"); }

int s21_digit(char ch) { return (ch >= '0' && ch <= '9'); }

int s21_len(char ch) { return s21_is_valid_char(ch, "hlL"); }

int s21_spec(char ch) { return s21_is_valid_char(ch, "cdisufgGeExXop%"); }

int s21_is_valid_char(char ch, const char *valid_chars) {
  while (*valid_chars) {
    if (ch == *valid_chars) {
      return 1;
    }
    valid_chars++;
  }
  return 0;
}

char *s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t len) {
  s21_size_t str_len = s21_strlen(str);
  int cnt = len;
  char *p = str + str_len;

  while (*wstr != '\0' && (cnt-- > 0 || len == 0)) {
    *(p++) = (char)*(wstr++);
  }
  *p = '\0';
  return str;
}

char *s21_ll_width_flag(char *str, Flag *formatSpec) {
  int str_len = (int)s21_strlen(str);
  if (formatSpec->width > (int)str_len) {
    char *num_str = calloc(1000 + formatSpec->width + 2, sizeof(char));
    if (num_str) {
      for (int i = 0; i < formatSpec->width; i++) {
        if (formatSpec->minus == 1) {
          if (i < str_len) {
            num_str[i] = str[i];
          } else {
            num_str[i] = ' ';
          }

        } else {
          if (i < formatSpec->width - str_len) {
            if (formatSpec->zero == 1) {
              num_str[i] = '0';
            } else {
              num_str[i] = ' ';
            }

          } else {
            num_str[i] = str[i - (formatSpec->width - str_len)];
          }
        }
      }
      num_str[formatSpec->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *s21_ll_to_str(char *str, long long number) {
  char *p = s21_NULL;
  int flag = 1, sign;

  sign = number < 0 ? -1 : 1;
  number *= sign;
  p = str;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (sign < 0) {
    *(p++) = '-';
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_reverse_str(char *str) {
  s21_size_t str_len = s21_strlen(str);
  char ch;
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

char *s21_leE_to_str(char *str, long double number, Flag *formatSpec) {
  if (formatSpec->precision < 0) formatSpec->precision = 6;
  long double right = 0.0, mantis;
  int pow = 0;

  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 10) {
      pow++;
      modfl(right / 10, &right);
    }
    if (pow == 0 && right < 1) {
      while (truncl(mantis * powl(10, pow * -1)) < 1) {
        pow--;
      }
    }
  }

  if (fpclassify(number) > 2) {
    number = number / powl(10, pow);
    s21_sprintf(str, formatSpec->sharp == 1 ? "%#.*Lfe%+.2d" : "%.*Lfe%+.2d",
                formatSpec->precision, number, pow);
  } else {
    s21_sprintf(str, "%.*Lf", formatSpec->precision);
    formatSpec->zero = 0;
  }
  if (formatSpec->tem == 'E') {
    char *p = s21_NULL;
    p = s21_strchr(str, 'e');
    if (p) *p = 'E';
  }
  return str;
}

char *s21_sign_flag(char *str, Flag *formatSpec) {
  if (s21_digit(*str) || *str == 'i') {
    char num_str[2] = "";
    char *p = s21_NULL;
    p = num_str;
    if (formatSpec->plus)
      *(p++) = '+';
    else if (formatSpec->space)
      *(p++) = ' ';
    *p = '\0';
    s21_reverse_str(str);
    s21_strcat(str, num_str);
    s21_reverse_str(str);
  }
  return str;
}

char *s21_lf_width_flag(char *str, Flag *formatSpec) {
  int str_len = (int)s21_strlen(str);
  char *p = s21_NULL, *p2 = s21_NULL;
  p2 = str;
  if (formatSpec->width > (int)str_len) {
    char *num_str = calloc(1000 + formatSpec->width + 2, sizeof(char));
    if (num_str) {
      p = num_str;
      if (!s21_digit(*p2) && formatSpec->zero) {
        *(p++) = *(p2++);
      }
      for (int i = 0; i < formatSpec->width; i++) {
        if (formatSpec->minus == 1) {
          if (i < str_len) {
            *(p++) = *(p2++);
          } else {
            if (formatSpec->zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          }
        } else {
          if (i < formatSpec->width - str_len) {
            if (formatSpec->zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          } else {
            *(p++) = *(p2++);
          }
        }
      }
      num_str[formatSpec->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *s21_lf_to_str(char *str, long double number, Flag *formatSpec) {
  if (formatSpec->precision < 0) formatSpec->precision = 6;
  s21_ld_to_a(str, number, formatSpec);
  return str;
}

char *s21_ld_to_a(char *str, long double number, Flag *formatSpec) {
  char num1_str[1000] = "", *p1 = s21_NULL;
  p1 = num1_str;
  char num2_str[1000] = "", *p2 = s21_NULL;
  p2 = num2_str;
  long double mantis, right = 0.0L, pow = 1.0L, pow_t = 1.0L;
  int sign;
  sign = signbit(number) == 0 ? 1 : -1;

  if (fpclassify(number) < 4) {
    if (sign < 0 && fpclassify(number) != 1) s21_strcat(str, "-");
    s21_strcat(str, num1_str);
    formatSpec->zero = 0;
  } else {
    number = s21_round(number, formatSpec->precision);
    mantis = modfl(fabsl(number), &right);

    while (truncl(right / pow) > 0) {
      int digit;
      digit = (int)truncl(fmodl(truncl(right), pow * (long double)10L) / (pow));
      *(p1++) = (char)(digit + '0');
      pow *= 10L;
    }

    if (sign < 0) *(p1++) = '-';
    *p1 = '\0';

    for (int i = 0; i < formatSpec->precision; i++) pow_t *= 10;

    mantis = roundl(mantis * pow_t);
    pow = 1.0L;
    while (pow < pow_t) {
      int digit;
      digit =
          (int)truncl(fmodl(truncl(mantis), pow * (long double)10L) / (pow));
      *(p2++) = (char)(digit + '0');
      pow *= 10L;
    }
    *p2 = '\0';
    s21_reverse_str(num1_str);
    if (s21_strlen(num1_str) == 0) s21_strcat(str, "0");
    s21_strcat(str, num1_str);
    if (formatSpec->precision > 0 || formatSpec->sharp == 1)
      s21_strcat(str, ".");
    if (formatSpec->precision > 0) {
      s21_reverse_str(num2_str);
      s21_strcat(str, num2_str);
    }
  }
  return str;
}

long double s21_round(long double x, int precision) {
  long double right = 0.0;
  long double x1 = modfl(fabsl(x), &right);
  int mul = 0;
  int sign = signbit(x) == 0 ? 1 : -1;
  for (int i = 0; i < precision; i++) mul--;

  if (roundl(x1 / powl(10, mul)) > truncl(x1 / powl(10, mul))) {
    x = x + (5 * powl(10, mul - 1)) * sign;
  }
  if (precision <= 6 && x1 > 0) {
    x = x / powl(10, mul);
    x = truncl(x) * powl(10, mul);
  }
  return x;
}

char *s21_ll_precision(char *str, Flag *formatSpec) {
  char *num_str = calloc(1000 + formatSpec->width + 2, sizeof(char));
  if (num_str) {
    s21_size_t str_len = s21_strlen(str);
    int shift;
    char *p = s21_NULL;
    char *s = s21_NULL;
    p = num_str;
    s = str;

    int sign = *s == '-' ? -1 : 0;
    if (formatSpec->zero == 1)
      formatSpec->precision = (formatSpec->precision > formatSpec->width)
                                  ? formatSpec->precision
                                  : formatSpec->width;

    formatSpec->precision = formatSpec->precision > (int)str_len + sign
                                ? formatSpec->precision
                                : (int)str_len + sign;
    shift = formatSpec->tem == 'x' && formatSpec->sharp == 1 ? 32 : 0;

    s21_reverse_str(str);
    for (int i = 0; i < formatSpec->precision; i++) {
      if (i < (int)str_len + sign)
        *(p++) = *(s++);
      else
        *(p++) = '0';
    }

    if (formatSpec->sharp == 1 && formatSpec->tem == (char)('X' + shift)) {
      *(p++) = (char)('X' + shift);
      *(p++) = '0';
    }

    if (sign < 0) *(p++) = '-';
    *p = '\0';
    s21_reverse_str(num_str);
    s21_strcpy(str, num_str);
    free(num_str);
  }
  return str;
}

char *s21_hl_to_str(char *str, unsigned long long number, Flag *formatSpec) {
  char *p = s21_NULL;
  int flag = 1, shift;

  p = str;
  shift = formatSpec->tem == 'x' ? 32 : 0;

  while (flag) {
    unsigned int digit;
    if (number > 15) {
      digit = number % 16;
      number = (number - digit) / 16;
    } else {
      digit = number;
      flag = 0;
    }
    if (digit < 10)
      *(p++) = (char)(digit + '0');
    else
      *(p++) = (char)(digit + 'A' + shift - 10);
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char **s21_sprintf_c(char **point_str, va_list *args, Flag *formatSpec) {
  wchar_t wchar;
  wchar_t wchar_s[10] = {0};

  char *temp_str = s21_NULL;
  temp_str = calloc(1000 + formatSpec->width + 2, sizeof(char));

  if (temp_str != s21_NULL) {
    switch (formatSpec->len) {
      case 'l':
        wchar = va_arg(*args, wchar_t);
        wchar_s[0] = wchar;
        s21_wch_to_str(temp_str, wchar_s, 0);
        break;
      default:
        temp_str[0] = va_arg(*args, int);
        temp_str[1] = '\0';
    }

    s21_ll_width_flag(temp_str, formatSpec);

    if (*temp_str != '\0') {
      for (s21_size_t i = 0; temp_str[i] != '\0'; i++) {
        **point_str = temp_str[i];
        *point_str += 1;
      }
      **point_str = '\0';
    } else {
      **point_str = temp_str[0];
      *point_str += 1;
      **point_str = '\0';
    }
  }

  free(temp_str);
  return point_str;
}

char *s21_sprintf_d(char *str, va_list *args, Flag *formatSpec) {
  long int ld_number;
  short int sd_number;
  int number;

  switch (formatSpec->len) {
    case 'h':
      sd_number = (short int)va_arg(*args, int);
      s21_ll_to_str(str, sd_number);
      break;
    case 'l':
      ld_number = (long int)va_arg(*args, long int);
      s21_ll_to_str(str, ld_number);
      break;
    default:
      number = va_arg(*args, int);
      s21_ll_to_str(str, number);
  }
  s21_ll_precision(str, formatSpec);
  s21_sign_flag(str, formatSpec);
  s21_ll_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_e_E(char *str, va_list *args, Flag *formatSpec) {
  long double ld_number;
  double d_number;
  double f_number;

  switch (formatSpec->len) {
    case 'L':
      ld_number = va_arg(*args, long double);
      s21_leE_to_str(str, ld_number, formatSpec);
      break;
    default:
      d_number = va_arg(*args, double);
      f_number = d_number;
      s21_leE_to_str(str, f_number, formatSpec);
  }
  s21_sign_flag(str, formatSpec);
  s21_lf_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_f(char *str, va_list *args, Flag *formatSpec) {
  long double ld_number;
  double d_number;
  double f_number;
  if (formatSpec->minus) formatSpec->zero = 0;

  switch (formatSpec->len) {
    case 'L':
      ld_number = va_arg(*args, long double);
      s21_lf_to_str(str, ld_number, formatSpec);
      break;
    default:
      d_number = va_arg(*args, double);
      f_number = d_number;
      s21_lf_to_str(str, f_number, formatSpec);
  }
  s21_sign_flag(str, formatSpec);
  s21_lf_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_g_G(char *str, va_list *args, Flag *formatSpec) {
  long double number;
  if (formatSpec->len == 'L') {
    number = va_arg(*args, long double);
  } else {
    number = va_arg(*args, double);
  }

  if (formatSpec->precision < 0) formatSpec->precision = 6;
  long double right = 0.0;
  int pow = 0, pow_m = 0;

  long double mantis = modfl(fabsl(number), &right);
  if (fpclassify(mantis) > 3 && fpclassify(right) == 3) {
    while (truncl(mantis * powl(10, pow * -1)) < 1) {
      pow--;
    }
  }
  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 1 && pow >= 0) {
      pow++;
      modfl(right / 10, &right);
    }
    if (fpclassify(mantis) > 3) {
      for (int i = 0; i < formatSpec->precision - pow; i++) {
        mantis = modfl(right / 10, &right);
        if (fpclassify(mantis) > 3) {
          pow_m++;
        }
      }
    }
  }

  int flag;
  int precision;
  if (pow - 1 < -4 || pow - 1 > formatSpec->precision - 1) {
    flag = 1;
    precision = formatSpec->precision > 0 ? formatSpec->precision - 1 : 0;
  } else {
    flag = 0;
    if (pow < 0)
      precision = formatSpec->precision > 0 ? formatSpec->precision : 0;
    else
      precision = formatSpec->precision > 0 ? formatSpec->precision - pow : 0;
  }

  if (flag == 1) {
    if (formatSpec->tem == 'G')
      sprintf(str, formatSpec->sharp == 1 ? "%#.*LE" : "%.*LE", precision,
              number);
    else
      sprintf(str, formatSpec->sharp == 1 ? "%#.*Le" : "%.*Le", precision,
              number);
  } else {
    sprintf(str, formatSpec->sharp == 1 ? "%#.*Lf" : "%.*Lf", precision,
            number);
  }

  char *p = s21_NULL;
  if (pow < 0 && flag == 1) {
    p = str;
    s21_size_t str_len =
        (s21_size_t)s21_strpbrk(str, formatSpec->tem == 'G' ? "E" : "e") - *p;
    if (str_len > 2 && (int)str_len - 1 >= formatSpec->precision &&
        *(p + str_len - 1) == '0' && formatSpec->sharp == 0) {
      p = p + str_len - 1;
      while (*p == '0') {
        *(p--) = '\0';
      }
      p = str + str_len;
      s21_strcat(str, p);
    }
  }

  p = str;
  p = p + s21_strlen(str) - 1;

  while (*p == '0' && formatSpec->sharp != 1) {
    *p-- = '\0';
  }
  if (*p == '.' && formatSpec->sharp != 1) {
    *p = '\0';
  }

  s21_sign_flag(str, formatSpec);
  s21_lf_width_flag(str, formatSpec);

  return str;
}

char *s21_sprintf_o(char *str, va_list *args, Flag *formatSpec) {
  unsigned long long number;
  char *p = str;
  int flag = 1;

  if (formatSpec->space) formatSpec->space = 0;

  switch (formatSpec->len) {
    case 'h':
      number = (unsigned short int)va_arg(*args, unsigned int);
      break;
    case 'l':
      number = (unsigned long int)va_arg(*args, unsigned long int);
      break;
    default:
      number = va_arg(*args, unsigned int);
  }

  while (flag) {
    unsigned int digit;
    if (number > 7) {
      digit = number % 8;
      number = (number - digit) / 8;
    } else {
      digit = number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (formatSpec->sharp == 1) *(p++) = '0';
  *p = '\0';
  s21_reverse_str(str);

  s21_ll_precision(str, formatSpec);
  s21_sign_flag(str, formatSpec);
  s21_ll_width_flag(str, formatSpec);

  return str;
}
char *s21_sprintf_p(char *str, va_list *argList, Flag *formatSpec) {
  void *p = va_arg(*argList, void *);
  int width = formatSpec->width;

  if (p == NULL) {
    s21_strcpy(str, "(nil)");
  } else {
    snprintf(str, sizeof(int) * 2 + 3, "%p", p);
  }

  char temp[100];
  snprintf(temp, sizeof(temp), "%p", p);

  int actual_length = s21_strlen(temp);
  int num_zeros_to_add = width - actual_length > 0 ? width - actual_length : 0;

  if (num_zeros_to_add > 0) {
    s21_memmove(str + num_zeros_to_add, temp, actual_length + 1);
    for (int i = 0; i < num_zeros_to_add; ++i) {
      str[i] = '0';
    }
  } else {
    s21_strcpy(str, temp);
  }

  return str;
}

char *s21_sprintf_perc(char *str, Flag *formatSpec) {
  formatSpec->precision = 0;
  s21_strcat(str, "%");
  s21_ll_precision(str, formatSpec);
  s21_ll_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_s(char *str, va_list *args, Flag *formatSpec) {
  char *p = s21_NULL;

  p = va_arg(*args, char *);
  if (!p) {
    if (formatSpec->precision < 6)
      s21_strncat(str, "(null)", formatSpec->precision);
    else
      s21_strcat(str, "(null)");
  } else {
    if (formatSpec->precision > -1)
      s21_strncat(str, p, formatSpec->precision);
    else
      s21_strcat(str, p);
  }

  s21_ll_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_u(char *str, va_list *args, Flag *formatSpec) {
  unsigned long long number;

  switch (formatSpec->len) {
    case 'h':
      number = (unsigned short)va_arg(*args, unsigned int);
      break;
    case 'l':
      number = (unsigned long)va_arg(*args, unsigned long);
      break;
    default:
      number = (unsigned int)va_arg(*args, unsigned int);
  }

  char *p = str;
  int flag = 1;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }
  *p = '\0';
  s21_reverse_str(str);

  s21_ll_precision(str, formatSpec);
  if (formatSpec->plus) s21_sign_flag(str, formatSpec);
  s21_ll_width_flag(str, formatSpec);
  return str;
}

char *s21_sprintf_x_X(char *str, va_list *args, Flag *formatSpec) {
  unsigned long int ld_number;
  unsigned short int sd_number;
  unsigned int number;

  switch (formatSpec->len) {
    case 'h':
      sd_number = (short unsigned int)va_arg(*args, unsigned int);
      s21_hl_to_str(str, sd_number, formatSpec);
      break;
    case 'l':
      ld_number = (long unsigned int)va_arg(*args, unsigned long int);
      s21_hl_to_str(str, ld_number, formatSpec);
      break;
    default:
      number = (unsigned int)va_arg(*args, unsigned int);
      s21_hl_to_str(str, number, formatSpec);
  }
  s21_ll_precision(str, formatSpec);
  s21_sign_flag(str, formatSpec);
  s21_ll_width_flag(str, formatSpec);

  return str;
}

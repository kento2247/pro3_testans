#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define DIV_MAX 10000
void myprintf(char *format, ...) {
  va_list va_ptr;
  int i, j;
  int format_num;          // format指定子の個数
  char c;                  // read char with fgetc
  int format_i;            // int data from va_arg
  char *format_s;          // string data from va_arg
  int div = DIV_MAX;       // division num when used print int num
  int int_print_flag = 0;  // turn on after print first num in int data

  i = 0;
  while (1) {
    c = format[i++];
    if (c == '\0') break;
    switch (c) {
      case 'c':
      case 'i':
      case 's':
        format_num++;
    }
  }
  va_start(va_ptr, format_num);
  i = 0;

  while (1) {
    c = format[i++];
    if (c == '\0') break;
    switch (c) {
      case 'c':
        c = *va_arg(va_ptr, char *);
        putchar(c);
        break;
      case 'i':
        format_i = *va_arg(va_ptr, int *);
        if (format_i < 0) {
          putchar('-');
          format_i *= -1;
        }
        while (div >= 1) {
          if (format_i / div != 0 || int_print_flag) {
            c = (format_i / div + ('1' - 1));
            putchar(c);
            format_i %= div;
            int_print_flag = 1;
          }
          div /= 10;
        }
        break;
      case 's':
        format_s = va_arg(va_ptr, char *);
        j = 0;
        while (1) {
          if (format_s[j] == '\0') break;
          putchar(format_s[j++]);
        }
        break;
      default:
        putchar(c);
    }
  }

  putchar('\0');
  va_end(va_ptr);
}

int main() {
  char s[] = "print a-101";
  char c = 'a';
  int i = -101;

  myprintf("s ... ci\n", s, &c, &i);
  return 0;
}
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define DIV_MAX 10000

void myprintf(char *s, ...) {
  char c, *str;
  int format_time = 0, i = 0, j, flag = 1, num, div_num;
  va_list va_ptr;

  while (flag) {
    c = s[i++];
    switch (c) {
      case '\0':
        flag = 0;
        break;
      case 'c':
      case 'i':
      case 's':
        format_time++;
    }
  }

  va_start(va_ptr, format_time);

  flag = 1;
  i = 0;
  while (flag) {
    c = s[i++];
    switch (c) {
      case '\0':
        flag = 0;
        break;
      case 'c':
        c = va_arg(va_ptr, int);
        putchar(c);
        break;
      case 'i':
        num = va_arg(va_ptr, int);
        for (div_num = DIV_MAX; div_num > 0; div_num /= 10) {
          if (num / div_num > 0) putchar((num / div_num) + '0');
          num = num % div_num;
        }
        break;
      case 's':
        str = va_arg(va_ptr, char *);
        j = 0;
        while (1) {
          c = str[j++];
          if (c == '\0') break;
          putchar(c);
        }
        break;
    }
  }

  va_end(va_ptr);
}

int main() {
  int i = 5;
  char c0 = 'a';
  char c1 = '\n';
  char *s0 = "c = ";
  char *s1 = "\ti = ";
  myprintf("scsic", s0, c0, s1, i, c1);
  return 0;
}

/*
❯ ./a.out
c = a   i = 5
*/
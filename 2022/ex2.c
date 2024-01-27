#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int num_match(int num, int n, ...) {
  va_list va_ptr;
  int i;
  int result = 0;  // result of count

  va_start(va_ptr, n);
  for (i = 0; i < n; i++) {
    if (num == va_arg(va_ptr, int)) result++;
  }
  va_end(va_ptr);
  return result;
}

int main() {
  printf("num_match: %d\n", num_match(3, 3, 1, 1, 3));
  printf("num_match: %d\n", num_match(4, 8, 1, 2, 3, 9, 4, 4, 3, 4));
  printf("num_match: %d\n", num_match(1, 3, -3, 7, 2));
  return 0;
}
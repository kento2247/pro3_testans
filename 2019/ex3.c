#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int num_match(int num, int n, ...);
int num_match(int num, int n, ...) {
  int result = 0;
  int target;
  int i = 0;
  va_list va_ptr;
  va_start(va_ptr, n);

  for (i = 0; i < n; i++) {
    target = va_arg(va_ptr, int);
    if (target == num) result++;
  }
  return result;
}

int main() {
  printf("num_match: %d\n", num_match(3, 5, 1, 2, 3, 4, 5));
  printf("num_match: %d\n", num_match(4, 6, 4, 2, 4, 2, 4, 2));

  return 0;
}
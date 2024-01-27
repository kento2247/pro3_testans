#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT_LEN 32

void find_bit(int n, ...);
void find_bit(int n, ...) {
  int i, j, first, last;
  unsigned int target, shifted_left, shifted_right;
  va_list va_ptr;

  va_start(va_ptr, n);

  for (i = 0; i < n; i++) {
    first = -1;
    last = 0;
    target = va_arg(va_ptr, unsigned int);
    for (j = 0; j < BIT_LEN; j++) {
      shifted_left = target << (BIT_LEN - j - 1);  // 1bitのみにする
      shifted_right = shifted_left >> (BIT_LEN - 1);
      if (shifted_right & 1) {
        last = j;
        if (first == -1) first = j;
      }
    }
    if (first == -1) first = 0;
    if (last == 0) last = 32;

    printf("Data: 0x%08x, First bit: %2d, Last bit: %2d\n", target, first,
           last);
  }

  va_end(va_ptr);
}

int main() {
  printf("find_bit(4, 0x80000001, 0x00010000, 0x20140108, 0x00000000);\n");
  find_bit(4, 0x80000001, 0x00010000, 0x20140108, 0x00000000);
  return 0;
}
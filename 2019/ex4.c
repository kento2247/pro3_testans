#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, j;
  int print_cnt = 0;
  double d;
  unsigned char *ptr;

  if (argc != 2) {
    exit(1);
  }

  d = atof(argv[1]);
  printf("%f = ", d);
  ptr = (unsigned char *)&d;
  for (i = sizeof(double) - 1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      printf("%d", (ptr[i] >> j) & 1);
      print_cnt++;
      if (print_cnt % 4 == 0 && print_cnt < 64) {
        printf("_");
      }
    }
  }
  printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double d;
  int i;

  if (argc != 2) {
    exit(1);
  }
  d = atof(argv[1]);

  // double型のビット列dを16進数で表示する
  printf("0x%lx\n", *(unsigned long *)&d);

  return 0;
}

/*
❯ ./a.out 1.0
0x3ff0000000000000
❯ ./a.out -1.1
0xbff199999999999a
*/
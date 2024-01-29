#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int ack(int m, int n);
int ack(int m, int n) {
  if (m == 0)
    return n + 1;
  else if (n == 0)
    return ack(m - 1, 1);
  else
    return ack(m - 1, ack(m, n - 1));
}

int main(int argc, char *argv[]) {
  int m, n;
  if (argc != 3) {
    fprintf(stderr, "usage: ./a.out <m> <n>\n");
    exit(1);
  }

  m = atoi(argv[1]);
  n = atoi(argv[2]);

  printf("ack(%d, %d) = %d\n", m, n, ack(m, n));

  return 0;
}

/*
❯ ./a.out 3 3
ack(3, 3) = 61
 */
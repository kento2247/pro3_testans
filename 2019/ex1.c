#include <stdio.h>
#include <stdlib.h>

int ack(int m, int n);

int ack(int m, int n) {
  int result = 0;
  if (m == 0) {
    result = n + 1;
  } else if (n == 0) {
    result = ack(m - 1, 1);
  } else {
    result = ack(m - 1, ack(m, n - 1));
  }
  return result;
}

int main(int argc, char *argv[]) {
  int m, n;

  if (argc != 3) {
    exit(1);
  }
  m = atoi(argv[1]);
  n = atoi(argv[2]);

  printf("ack(%d, %d) = %d\n", m, n, ack(m, n));
}

/*
❯ ./a.out 3 3
ack(3, 3) = 61
*/
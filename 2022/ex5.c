#include <stdio.h>
#include <stdlib.h>

#define USE MATH DEFINES
#include <math.h>

double recursion(int n, int now_n, double an1, double an2) {
  double an;

  switch (n) {
    case 0:
      return 0.0;
    case 1:
      return 0.99;
  }

  an = cos(2 * M_PI * fabs(an1 - an2)) * (an1 / 2 + an2 / 2);
  if (n == now_n) return an;

  return recursion(n, ++now_n, an, an1);
}

int main(int argc, char *argv[]) {
  int n;
  double an = 0.0;

  if (argc != 2) {
    fprintf(stderr, "Usage: a.out num\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if (n < 0 || n > 20) {
    fprintf(stderr, "Error: Invalid number n = %d\n", n);
    exit(2);
  }

  an = recursion(n, 2, 0.99, 0);
  printf("rec(%d) = %.4f\n", n, an);
  return 0;
}
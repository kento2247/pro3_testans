#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "ex4.dat"

int recursion(int n, int i, int a1, int a2) {
  int result;

  if (n == i) return a1;
  result = 5 * a1 - 3 * a2 + 4 * n;
  return recursion(n, ++i, result, a1);
}

int main() {
  FILE *fp;
  int i;

  fp = fopen(FILE_NAME, "w");
  if (fp == NULL) exit(1);

  for (i = 1; i <= 10; i++) {
    if (i == 1)
      fprintf(fp, "a(1) = %d\n", 2);
    else if (i == 2)
      fprintf(fp, "a(2) = %d\n", 6);
    else
      fprintf(fp, "a(%d) = %d\n", i, recursion(i, 2, 6, 2));
  }

  fclose(fp);
  return 0;
}
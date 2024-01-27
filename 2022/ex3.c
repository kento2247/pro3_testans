#include <stdio.h>
#include <stdlib.h>

#include "ex3sub.c"

int Over_count = 0;

int main() {
  double input;
  double sigma2;
  int n = 0;
  while (1) {
    printf("Input x (%d): ", ++n);
    scanf("%lf", &input);
    if (input < 0) break;
    sigma2 = update_variance(input);
    printf("Variance: %.3f [%d/%d]\n", sigma2, Over_count, n);
  }
  return 0;
}
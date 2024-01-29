#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARG 8

struct minmaxavg {
  double min;
  double max;
  double avg;
};

struct minmaxavg fminmaxavg(int n, ...) {
  va_list va_ptr;
  struct minmaxavg res;
  double sum = 0, input;
  int i;

  va_start(va_ptr, n);

  for (i = 0; i < n; i++) {
    input = va_arg(va_ptr, double);
    sum += input;
    if (i == 0) {
      res.min = input;
      res.max = input;
    } else {
      if (res.min > input) res.min = input;
      if (res.max < input) res.max = input;
    }
    res.avg = sum / n;
  }

  va_end(va_ptr);
  return res;
}

int main(int argc, char *argv[]) {
  struct minmaxavg result;
  double args[MAX_ARG];
  int n, i;

  if (argc < 3) {
    fprintf(stderr, "usage ./a.out <NUM> <DOUBLE> ...\n");
    exit(1);
  }
  n = atoi(argv[1]);
  for (i = 0; i < argc - 2; i++) {
    if (i >= MAX_ARG) {
      fprintf(stderr, "too much args. limit is %d\n", MAX_ARG);
      exit(2);
    }
    args[i] = atof(argv[i + 2]);
  }

  result = fminmaxavg(n, args[0], args[1], args[2], args[3], args[4], args[5],
                      args[6], args[7]);

  printf("min = %.6f\n", result.min);
  printf("max = %.6f\n", result.max);
  printf("avg = %.6f\n", result.avg);

  return 0;
}

/*
❯ ./a.out 5 1.0 -2.0 3.0 -4.0 5.0
min = -4.000000
max = 5.000000
avg = 0.600000
*/
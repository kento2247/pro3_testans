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
  struct minmaxavg s;
  va_list va_ptr;
  int i = 0;
  double d, sum = 0;

  va_start(va_ptr, n);

  for (i = 0; i < n; i++) {
    d = va_arg(va_ptr, double);
    if (i == 0) {
      s.min = d;
      s.max = d;
    }
    sum += d;
    if (s.min > d) s.min = d;
    if (s.max < d) s.max = d;
  }

  s.avg = sum / n;

  va_end(va_ptr);
  return s;
}

int main(int argc, char *argv[]) {
  struct minmaxavg s;
  int i = 0, n;
  double args[MAX_ARG];

  if (argc < 3) {
    fprintf(stderr, "usage: ./a.out n d1 ...\n");
    exit(1);
  }
  n = atoi(argv[1]);
  for (i = 0; i < argc - 2; i++) args[i] = atof(argv[i + 2]);
  s = fminmaxavg(n, args[0], args[1], args[2], args[3], args[4], args[5],
                 args[6], args[7]);

  printf("min = %.6f\n", s.min);
  printf("max = %.6f\n", s.max);
  printf("avg = %.6f\n", s.avg);
  return 0;
}

/*
❯ ./a.out
usage: ./a.out n d1 ...
❯ ./a.out 5 1.0 -2.0 3.0 -4.0 5.0
min = -4.000000
max = 5.000000
avg = 0.600000
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define ARG_LEN 8

struct minmaxavg {
  double min;
  double max;
  double avg;
};

struct minmaxavg fminmaxavg(int n, ...) {
  va_list va_ptr;
  struct minmaxavg res;  // result
  double tmp_num;        // tmp data from va_arg
  double sum;            // to calculate avg
  int i;

  va_start(va_ptr, n);
  for (i = 0; i < n; i++) {
    tmp_num = va_arg(va_ptr, double);
    if (i == 0) {
      // initialize
      sum = tmp_num;
      res.min = tmp_num;
      res.max = tmp_num;
    } else {
      sum += tmp_num;
      if (res.min > tmp_num) res.min = tmp_num;
      if (res.max < tmp_num) res.max = tmp_num;
    }
  }
  res.avg = sum / n;
  va_end(va_ptr);

  return res;
}

int main(int argc, char *argv[]) {
  struct minmaxavg result;
  double args[ARG_LEN];
  int n, i;
  if (argc < 2) {
    fprintf(stderr, "usage: ./a.out double1 ...\n");
    exit(1);
  }
  n = argc - 1;
  for (i = 0; i < n; i++) {
    args[i] = atof(argv[i + 1]);
  }

  result = fminmaxavg(n, args[0], args[1], args[2], args[3], args[4], args[5],
                      args[6], args[7]);

  printf("min = %.6f\n", result.min);
  printf("max = %.6f\n", result.max);
  printf("avg = %.6f\n", result.avg);
  return 0;
}

/*
❯ ./a.out 1.0 -2.0 3.0 -4.0 5.0
min = -4.000000
max = 5.000000
avg = 0.600000
*/
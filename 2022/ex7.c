#define USE MATH DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define rad(theta) theta / 180 * M_PI

struct point {
  double x;
  double y;
};

void rotate(struct point *dst, struct point *src, double theta) {
  dst->x = src->x * cos(rad(theta)) - src->y * sin(rad(theta));
  dst->y = src->y * cos(rad(theta)) + src->x * sin(rad(theta));
}

int main(int argc, char *argv[]) {
  struct point src, dest;
  FILE *fp;
  int i;

  if (argc != 4) {
    fprintf(stderr, "Usage: a.out x-coordinate y-coordniate file- name\n");
    exit(1);
  }
  src.x = atof(argv[1]);
  src.y = atof(argv[2]);
  fp = fopen(argv[3], "w");
  if (fp == NULL) {
    fprintf(stderr, "Error: Cannot open file %s\n", argv[3]);
    exit(2);
  }

  for (i = 0; i <= 90; i++) {
    rotate(&dest, &src, i);
    fprintf(fp, "%d %.6f %.6f\n", i, dest.x, dest.y);
  }

  fclose(fp);
  return 0;
}
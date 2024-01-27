#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.141592

struct sphere {
  double radius;
  double surface;
  double volume;
};

struct point {
  double x;
  double y;
  double z;
  struct sphere s;
};

void calc_sphere(struct point *p) {
  p->s.radius = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
  p->s.surface = 4 * pi * p->s.radius * p->s.radius;
  p->s.volume = 4 * pi * p->s.radius * p->s.radius * p->s.radius / 3;
}

int main() {
  struct point p;
  scanf("%lf %lf %lf", &p.x, &p.y, &p.z);
  calc_sphere(&p);

  printf("radius: %.6f\n", p.s.radius);
  printf("surface: %.6f\n", p.s.surface);
  printf("volume: %.6f\n", p.s.volume);
}
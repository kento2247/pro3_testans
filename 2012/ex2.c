#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECKBIT(a, b) ((a >> b) & 1)
#define SETBIT(a, b) (a | (1 << b))

int main() {
  unsigned int a, b;
  scanf("%d %d", &a, &b);
  if (CHECKBIT(a, b))
    printf("%d\n", a);
  else
    printf("SETBIT\n%d\n", SETBIT(a, b));
  return 0;
}

/*
❯ ./a.out
16 0
SETBIT
17
❯ ./a.out
16 1
SETBIT
18
❯ ./a.out
16 4
16
*/
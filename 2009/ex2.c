#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double d;
  if (argc != 2) {
    fprintf(stderr, "usage: dtoh <double>\n");
    exit(1);
  }
  d = atof(argv[1]);
  printf("%.6f = 0x%lx\n", d, *(unsigned long *)&d);

  return 0;
}

/*
❯ ./dtoh 1.0
1.000000 = 0x3ff0000000000000
❯ ./dtoh -1.1
-1.100000 = 0xbff199999999999a
*/
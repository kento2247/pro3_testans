#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int space = 0, tab = 0, indent = 0;

  while (1) {
    c = fgetc(stdin);
    if (c == '\0' || c == EOF) break;
    if (c == ' ') space++;
    if (c == '\t') tab++;
    if (c == '\n') indent++;
  }

  printf("space = %d\n", space);
  printf("tab = %d\n", tab);
  printf("new line = %d\n", indent);

  return 0;
}

/*
❯ ./a.out
a       c   3
dd
space = 3
tab = 1
new line = 2
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char c;
  int i = 0, space = 0, tab = 0, indent = 0;

  if (argc != 1) {
    fprintf(stderr, "usage ./a.out <text>\n");
    exit(1);
  }
  while (1) {
    c = getchar();
    if (c == EOF) break;
    switch (c) {
      case ' ':
        space++;
        break;
      case '\t':
        tab++;
        break;
      case '\n':
        indent++;
        break;
    }
  }

  printf("space = %d\n", space);
  printf("tab = %d\n", tab);
  printf("new line = %d\n", indent);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int i;
  char c;

  if (argc < 3) {
    while (1) {
      c = fgetc(stdin);
      if (c == EOF || c == '\0') break;
      fprintf(stdout, "%c", c);
    }
  } else {
    for (i = 0; i < argc - 1; i++) {
      fp = fopen(argv[i + 1], "r");
      if (fp == NULL) {
        fprintf(stderr, "fialed to open file: %s\n", argv[i + 1]);
        exit(1);
      }
      while (1) {
        c = fgetc(fp);
        if (c == EOF || c == '\0') break;
        fprintf(stdout, "%c", c);
      }
    }
  }

  return 0;
}
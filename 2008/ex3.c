#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp, *output;
  int i;
  char c;

  if (argc < 2) {
    exit(1);
  }

  output = fopen(argv[argc - 1], "w");
  if (output == NULL) {
    fprintf(stderr, "fialed to open file: %s\n", argv[argc - 1]);
    exit(2);
  }

  if (argc == 2) {
    while (1) {
      c = fgetc(stdin);
      fprintf(output, "%c", c);
      if (c == '\0' || c == EOF) break;
    }
  } else {
    for (i = 0; i < argc - 2; i++) {
      fp = fopen(argv[i + 1], "r");
      if (fp == NULL) {
        fprintf(stderr, "fialed to open file: %s\n", argv[i + 1]);
        exit(2);
      }
      while (1) {
        c = fgetc(fp);
        if (c == '\0' || c == EOF) break;
        fprintf(output, "%c", c);
      }
    }
  }

  return 0;
}
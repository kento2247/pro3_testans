#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1023

int main(int argc, char *argv[]) {
  FILE **inputs, *output;
  char row[MAX_BUF];
  int i = 0;
  int continue_flag;

  if (argc < 2) {
    fprintf(stderr, "usage ./a.out src_file1, src_file2, ..., dst_file\n");
    exit(1);
  }
  inputs = (FILE **)malloc(sizeof(FILE *) * (argc - 2));
  if (inputs == NULL) {
    fprintf(stderr, "failed to allocate memory\n");
    exit(2);
  }
  for (i = 0; i < argc - 2; i++) {
    inputs[i] = fopen(argv[i + 1], "r");
    if (inputs[i] == NULL) {
      fprintf(stderr, "failed to open: %s\n", argv[i + 1]);
      exit(3);
    }
  }
  output = fopen(argv[argc - 1], "w");
  if (output == NULL) {
    fprintf(stderr, "failed to open: %s\n", argv[argc - 1]);
    exit(3);
  }

  while (1) {
    continue_flag = 0;
    for (i = 0; i < argc - 2; i++) {
      if (fgets(row, MAX_BUF + 1, inputs[i]) == NULL) continue;
      fprintf(output, "%s", row);
      continue_flag = 1;
    }
    if (continue_flag == 0) break;
  }

  for (i = 0; i < argc - 2; i++) fclose(inputs[i]);
  fclose(output);
  free(inputs);
  return 0;
}
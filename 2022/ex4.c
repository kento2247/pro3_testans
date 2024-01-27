#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *input, *output;
  char tmp_char;  // read and write target char

  if (argc != 3) {
    printf("Usage: a.out inputFile outputFile\n");
    exit(1);
  }
  input = fopen(argv[1], "r");
  output = fopen(argv[2], "w");
  if (input == NULL) {
    printf("Error: Cannot open file %s", argv[1]);
    exit(2);
  }
  if (output == NULL) {
    printf("Error: Cannot open file %s", argv[2]);
    exit(3);
  }

  while (1) {
    tmp_char = fgetc(input);
    if (tmp_char == EOF) break;

    if (tmp_char >= 'a' && tmp_char <= 'z')
      tmp_char = tmp_char - ('a' - 'A');
    else if (tmp_char >= 'A' && tmp_char <= 'Z')
      tmp_char = tmp_char + ('a' - 'A');

    fputc(tmp_char, output);
  }

  fclose(input);
  fclose(output);
  return 0;
}
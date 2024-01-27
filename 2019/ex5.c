#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 255
#define MAX_LIB_LEN 1023

struct info {
  unsigned int rank;
  unsigned int time;
  char word[MAX_BUF];
};

void addlib(struct info *lib, char *word[]) {}

int main(int argc, char *argv[]) {
  FILE *input, *output;
  int i;
  char word[MAX_BUF];
  char tmp;
  struct info lib[MAX_LIB_LEN];

  if (argc != 3) exit(1);
  input = fopen(argv[1], "r");
  output = fopen(argv[2], "w");
  if (input == NULL) exit(2);
  if (output == NULL) exit(3);

  while (1) {
    tmp = fgetc(input);
    switch (tmp) {
      case ' ':
      case '\t':
      case '\n':
      case '-':
      case '/':
      case ',':
      case '.':
      case EOF:
        word[i] = '\0';
        i = 0;
        addlib(lib, word);
        break;
      default:
        if (tmp >= 'A' && tmp <= 'Z') tmp = tmp + ('a' - 'A');
        if (tmp >= 'a' && tmp <= 'z') word[i++] = tmp;
    }
    if (tmp == EOF) break;
  }

  fclose(input);
  fclose(output);
  return 0;
}
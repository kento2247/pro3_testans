#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int charas = 0, words = 0, rows = 0;
  printf("input sentence.(end with ctrl+D): ");

  while (1) {
    c = fgetc(stdin);
    if (c == EOF) break;
    switch (c) {
      case ' ':
      case '\t':
      case '\n':
        if (c == '\n') rows++;
        words++;
        break;
      default:
        charas++;
    }
  }
  printf("charactors: %d\n", charas);
  printf("words: %d\n", words);
  printf("rows: %d\n", rows);

  return 0;
}
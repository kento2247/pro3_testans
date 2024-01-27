#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int charas = 0, lines = 0, alphas = 0, i;
  char tmp_char;
  int lib_len = ('z' - 'a') * 2;
  int lib[lib_len];

  for (i = 0; i < lib_len; i++) lib[i] = 0;

  while (1) {
    tmp_char = fgetc(stdin);
    if (tmp_char == EOF) break;
    charas++;
    if (tmp_char == '\n') lines++;
    if ('A' <= tmp_char && tmp_char <= 'z') {
      lib[tmp_char - 'A']++;
    }
  }

  for (i = 0; i < lib_len; i++)
    if (lib[i] > 0) alphas++;

  printf("character = %d\n", charas);
  printf("new line = %d\n", lines);
  printf("alphabet = %d\n", alphas);
  return 0;
}
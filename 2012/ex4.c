#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1023
#define MAX_FILES 15

int main(int argc, char *argv[]) {
  int n = 0, i, index = 0, t_counter = 0;
  char input;
  char str[MAX_BUF];
  FILE *fp;

  if (argc == 1)
    n = 10;
  else
    n = -1 * atoi(argv[1]);
  if (argc < 3) {
    while (1) {
      input = fgetc(stdin);
      if (input == EOF) break;
      if (input == '\n') t_counter++;
      str[index++] = input;
      if (t_counter >= n) continue;
    }
    str[index] = '\0';
  } else {
    for (i = 0; i < (argc - 2); i++) {
      t_counter = 0;
      fp = fopen(argv[i + 2], "r");
      if (fp == NULL) {
        fprintf(stderr, "failed to open file: %s\n", argv[i + 2]);
        exit(1);
      }
      while (1) {
        input = fgetc(fp);
        if (input == EOF) break;
        if (input == '\n') t_counter++;
        str[index++] = input;
        if (t_counter >= n) break;
      }
      fclose(fp);
    }
    str[index] = '\0';
  }

  printf("%s", str);
  return 0;
}

/*
❯ ./a.out -2 data.txt sample.txt
Joho Keiko 12345678 90
Yagami Taro 11111111 20
a
bc
❯ ./a.out 2
1
2
3
4
1D
2
3
4
*/
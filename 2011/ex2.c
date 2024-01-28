#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1023

#define mystrncat(s1, s2, c)                 \
  do {                                       \
    int i, j;                                \
    for (i = 0;; i++)                        \
      if (s1[i] == '\0') break;              \
    for (j = 0; j < c; j++) s1[i++] = s2[j]; \
    s1[i] = '\0';                            \
  } while (0)

int main(int argc, char *argv[]) {
  char str[MAX_BUF];
  int k, c;

  str[0] = '\0';
  if (argc < 3) {
    exit(1);
  }
  c = atoi(argv[1]);
  for (k = 0; k < argc - 2; k++) {
    mystrncat(str, argv[2 + k], c);
  }

  printf("%s\n", str);
  return 0;
}

/*
❯ ./a.out 3 abc 123 hoge hehehe
abc123hogheh
*/
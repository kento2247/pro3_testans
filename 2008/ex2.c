#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1023
#define mystrncat(s1, s2, c)    \
  do {                          \
    int i = 0, j = 0;           \
    for (i = 0;; i++)           \
      if (s1[i] == '\0') break; \
    for (j = 0; j < c; j++) {   \
      s1[i++] = s2[j];          \
      if (s2[j] == '\0') break; \
    }                           \
  } while (0);

int main(int argc, char *argv[]) {
  char s[MAX_BUF];
  int k, num;
  if (argc < 3) {
    fprintf(stderr, "usage: ./a.out <NUM> <STR1> ...\n");
    exit(1);
  }

  num = atoi(argv[1]);
  for (k = 0; k < argc - 2; k++) {
    mystrncat(s, argv[k + 2], num);
  }

  printf("%s\n", s);
  return 0;
}

/*
❯ ./a.out 3 abc 123 hoge hehehe
abc123hogheh
*/
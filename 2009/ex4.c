#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1023
#define mystrcat(s1, s2)        \
  do {                          \
    int i, j;                   \
    char c;                     \
    for (i = 0;; i++)           \
      if (s1[i] == '\0') break; \
    for (j = 0;; j++) {         \
      s1[i++] = s2[j];          \
      if (s2[i] == '\0') break; \
    }                           \
  } while (0);

int main(int argc, char *argv[]) {
  int k;
  char str[MAX_BUF];

  str[0] = '\0';
  if (argc < 2) {
    fprintf(stderr, "usage: ./a.out <FILE1> ...\n");
    exit(1);
  }
  for (k = 0; k < argc - 1; k++) {
    mystrcat(str, argv[k + 1]);
  }
  fprintf(stdout, "%s\n", str);
  return 0;
}

/*
❯ ./a.out abc 123 hoge hehe
abc123hoghehe
*/
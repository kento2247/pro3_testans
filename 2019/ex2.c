#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 255
#define mystrncat(s1, s2, c)    \
  {                             \
    int p = 0;                  \
    int j = 0;                  \
    for (p = 0;; p++) {         \
      if (s1[p] == '\0') break; \
    }                           \
    for (j = 0; j < c; j++) {   \
      s1[p++] = s2[j];          \
    }                           \
    s1[p] = '\0';               \
  }

int main(int argc, char *argv[]) {
  int n;
  int i = 0;
  char s1[MAX_BUF];
  if (argc < 4) {
    exit(1);
  }
  n = atoi(argv[1]);
  for (i = 0; i < n; i++) {
    s1[i] = argv[2][i];
  }
  s1[i] = '\0';
  for (i = 3; i < argc; i++) {
    mystrncat(s1, argv[i], n);
  }
  printf("%s\n", s1);
}
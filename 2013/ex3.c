#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1023
#define mystrcat(s1, s2)                             \
  do {                                               \
    int i, j;                                        \
    for (i = 0; s1[i] != '\0'; i++)                  \
      ;                                              \
    for (j = 0; s2[j] != '\0'; j++) s1[i++] = s2[j]; \
    s1[i] = '\0';                                    \
  } while (0);

int main(int argc, char *argv[]) {
  int k;
  char s[MAX_BUF];

  if (argc < 3) {
    fprintf(stderr, "usage: ./a.out str1 str2 ...\n");
    exit(1);
  }
  s[0] = '\0';
  for (k = 0; k < (argc - 1); k++) {
    mystrcat(s, argv[k + 1]);
  }
  printf("%s\n", s);
  return 0;
}

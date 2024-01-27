#include <stdio.h>
#include <stdlib.h>

int mystrncmp(const char *s1, const char *s2, int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char *s1, *s2;
  int n;

  if (argc != 4) {
    fprintf(stderr, "Usage: a.out str1 str2 num\n");
    exit(1);
  }
  s1 = argv[1];
  s2 = argv[2];
  n = atoi(argv[3]);

  printf("mystrncmp(%s, %s, %d) = %d\n", s1, s2, n, mystrncmp(s1, s2, n));
  return 0;
}

/*
❯ gcc ex6.c
❯ ./a.out sampling sample 5
mystrncmp(sampling, sample, 5) = 0
❯ ./a.out sampling sample 8
mystrncmp(sampling, sample, 8) = 1
❯ ./a.out sampling sample 10
mystrncmp(sampling, sample, 10) = 1
❯ ./a.out swim swimming 6
mystrncmp(swim, swimming, 6) = -1
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1023

char *strrepeat(char *dst, const char *src, int n);
char *strrepeat(char *dst, const char *src, int n) {
  int i = 0, j;
  for (; n > 0; n--) {
    for (j = 0; src[j] != '\0'; j++) {
      dst[i++] = src[j];
    }
  }
  dst[i] = '\0';
  return dst;
}

int main(int argc, char *argv[]) {
  char dst[MAX_BUF];
  if (argc != 3) {
    fprintf(stderr, "usage: ./a.out num string\n");
    exit(1);
  }
  strrepeat(dst, argv[2], atoi(argv[1]));
  printf("%s\n", dst);
  exit(0);
}
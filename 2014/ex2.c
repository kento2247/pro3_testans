#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 1023
#define strodd(src, dst)                   \
  do {                                     \
    int i, j;                              \
    for (i = 0, j = 0; i < MAX_BUF; i++) { \
      if (src[i] == '\0') {                \
        dst[j] = '\0';                     \
        break;                             \
      }                                    \
      if (i % 2 == 0) dst[j++] = src[i];   \
    }                                      \
  } while (0);

#define streven(src, dst)                  \
  do {                                     \
    int i, j;                              \
    for (i = 0, j = 0; i < MAX_BUF; i++) { \
      if (src[i] == '\0') {                \
        dst[j] = '\0';                     \
        break;                             \
      }                                    \
      if (i % 2 == 1) dst[j++] = src[i];   \
    }                                      \
  } while (0);

int main() {
  char input[MAX_BUF];
  char output[MAX_BUF / 2];

#ifdef TRANS_ODD
  printf("Trans odd: ");
  scanf("%s", input);
  strodd(input, output);
  printf("%s\n", output);
  return 0;
#endif
#ifdef TRANS_EVEN
  printf("Trans even: ");
  scanf("%s", input);
  streven(input, output);
  printf("%s\n", output);
  return 0;
#endif

  printf("No trans: ");
  scanf("%s", input);
  printf("%s\n", input);
  return 0;
}

/*
❯ gcc -DTRANS_ODD ex2.c
❯ ./a.out
Trans odd: abcde
ace
❯ gcc -DTRANS_EVEN ex2.c
❯ ./a.out
Trans even: abcde
bd
❯ gcc ex2.c
❯ ./a.out
No trans: abcde
abcde
*/
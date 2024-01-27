#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 16
struct record {
  char sei[MAXLEN], mei[MAXLEN];
  int id;
  int score;
};
int read_record(FILE *fp, struct record *pr);
void print_record(const struct record *pr);

int main(int argc, char *argv[]) {
  FILE *fp;
  int border;
  struct record r;

  if (argc != 3) {
    fprintf(stderr, "Usage: <FILE> <BORDER>\n");
    exit(1);
  }
  border = atoi(argv[2]);
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Failed to open file: %s\n", argv[1]);
    exit(1);
  }
  while (1) {
    if (read_record(fp, &r) == 0) break;
    if (r.score >= border) print_record(&r);
  }

  fclose(fp);
  return 0;
}

int read_record(FILE *fp, struct record *pr) {
  if (fscanf(fp, "%s %s %d %d", pr->sei, pr->mei, &pr->id, &pr->score) == EOF)
    return 0;
  return 1;
}
void print_record(const struct record *pr) {
  printf("%s %s %d %d\n", pr->sei, pr->mei, pr->id, pr->score);
}

/*
❯ ./a.out data.txt
Usage: <FILE> <BORDER>
❯ ./a.out data.txt 60
Joho Keiko 12345678 90
Keio Hanako 99999999 60
❯ ./a.out data.txt 70
Joho Keiko 12345678 90
❯ ./a.out data.txt 50 30
Usage: <FILE> <BORDER>
*/
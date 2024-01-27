#include <stdio.h>
#include <stdlib.h>

unsigned short compress_date(int year, int month, int day);
unsigned short compress_date(int year, int month, int day) {
  unsigned short result;
  result = (year << 9) | (month << 5) | day;
  return result;
}

int main(int argc, char *argv[]) {
  int year, month, day;
  if (argc != 4) {
    fprintf(stderr, "usage: ./a.out yyyy month day");
    exit(1);
  }
  year = atoi(argv[1]) - 1900;
  month = atoi(argv[2]);
  day = atoi(argv[3]);
  printf("Compressed date : 0x%04x\n", compress_date(year, month, day));
  return 0;
}

/*
❯ ./a.out 1990 6 5
Compressed date : 0xb4c5
❯ ./a.out 2014 1 9
Compressed date : 0xe429
*/
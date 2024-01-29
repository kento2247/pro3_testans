#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int u_case = 0, l_case = 0, digit = 0, other = 0;

  while (1) {
    c = fgetc(stdin);
    if (c == EOF || c == '\0') break;
    if (c >= 'a' && c <= 'z')
      l_case++;
    else if (c >= 'A' && c <= 'Z')
      u_case++;
    else if (c >= '0' && c <= '9')
      digit++;
    else
      other++;
  }

  printf("Upper case = %d\n", u_case);
  printf("Lower case = %d\n", l_case);
  printf("Digit = %d\n", digit);
  printf("Other = %d\n", other);
  return 0;
}

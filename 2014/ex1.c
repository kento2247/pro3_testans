#include <stdio.h>
#include <stdlib.h>

int main() {
  int lib['a' - 'A'];
  char input;
  int i;

  for (i = 0; i < ('a' - 'A'); i++) {
    lib[i] = 0;
  }

  while (1) {
    input = fgetc(stdin);
    if (input == EOF) break;

    if (input >= 'A' && input <= 'Z') input = input + ('a' - 'A');
    if (input >= 'a' && input <= 'z') lib[input - 'a']++;
  }

  for (i = 0; i < ('a' - 'A'); i++) {
    if (lib[i] != 0) printf("%c : %d\n", i + 'a', lib[i]);
  }

  return 0;
}

/*
❯ ./a.out
Hello WOrld
Programing 3rd
a : 1
d : 2
e : 1
g : 2
h : 1
i : 1
l : 3
m : 1
n : 1
o : 3
p : 1
r : 4
w : 1
*/
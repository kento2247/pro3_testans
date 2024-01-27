#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 255
#ifdef INPUT_CHAR
#define DATA_BIT (sizeof(unsigned char) * 8)
#else
#define DATA_BIT (sizeof(unsigned int) * 8)
#endif

#define rotate_bit(data, rot, dir)                               \
  do {                                                           \
    unsigned int shift = rot % DATA_BIT;                         \
    if (strcmp(dir, "left") == 0) {                              \
      data = ((data << shift)) | ((data) >> (DATA_BIT - shift)); \
    } else if (strcmp(dir, "right") == 0) {                      \
      data = ((data >> shift)) | ((data) << (DATA_BIT - shift)); \
    } else {                                                     \
      fprintf(stderr, "Error: dir is not left and right\n");     \
      exit(1);                                                   \
    }                                                            \
  } while (0)

int main() {
  unsigned int data, rot;
  char dir[MAX_BUF];

  printf("int_data: 0x");
  scanf("%x", &data);
  printf("rot: ");
  scanf("%d", &rot);
  printf("dir: ");
  scanf("%s", dir);

  rotate_bit(data, rot, dir);

#ifdef INPUT_CHAR
  printf("rotate_%s(%dbit): 0x%02x\n", dir, rot, (unsigned char)data);
#else
  printf("rotate_%s(%dbit): 0x%08x\n", dir, rot, data);
#endif
  return 0;
}
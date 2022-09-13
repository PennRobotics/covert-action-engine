#include <stdio.h>
#include <stdint.h>

int main() {
  int c;
  FILE *picfile;
  picfile = fopen("LABS.PIC", "rb");

  c = fgetc(picfile);
  printf("Looks %s\n", (c == 0x07 || c == 0x0F) ? "valid!" : "sketchy");
  fgetc(picfile);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  printf("%d x ", c);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  printf("%d\n", c);

  uint16_t count = 6;
  do {
    count++;
    c = fgetc(picfile);
    if (c == 0x90)  { printf("(possible) RLE marker\n"); }
  } while (c != EOF);

  printf("%d\n", count - 1);

  return 0;
}

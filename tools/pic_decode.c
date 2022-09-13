#include <stdio.h>
#include <stdint.h>

int main() {
  int c;
  FILE *picfile;
  picfile = fopen("LABS.PIC", "rb");

  uint16_t count = 0;
  c = fgetc(picfile);
  printf("Looks %s\n", (c == 0x07 || c == 0x0F) ? "valid!" : "sketchy");
  fgetc(picfile);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  printf("%d x ", c);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  printf("%d\n", c);

  do {
    count++;
    c = fgetc(picfile);
  } while (c != EOF);

  printf("%d\n", count - 1);

  return 0;
}

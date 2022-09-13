#define  HEAD_N  0x40
#define  DEBUGGING  0

#if DEBUGGING==1
#define  DEBUG  if(DEBUGGING)printf
#else
#define  DEBUG(...)
#endif

#include <stdio.h>
#include <stdint.h>

int main() {
  int c;
  FILE *picfile;
  picfile = fopen("LABS.PIC", "rb");

  /*
  c = fgetc(picfile);
  DEBUG("Looks %s\n", (c == 0x07 || c == 0x0F) ? "valid!" : "sketchy");
  fgetc(picfile);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  DEBUG("%d x ", c);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  DEBUG("%d\n", c);
  // */

  uint16_t count = 6;
  count = 0;  // TODO-debug
  do {
    count++;
    c = fgetc(picfile);
    if (c == 0x90)  { printf("(possible) RLE marker\n"); }
    if (count > HEAD_N)  { break; }
    printf("%02X", (uint8_t)c);
    if (count % 2 == 0)  { printf(" "); }
    if (count % 16 == 0)  { printf("\n"); }
  } while (c != EOF);

  if (count % 16 != 1)  { printf("\n"); }

  DEBUG("%d\n", count - 1);

  return 0;
}

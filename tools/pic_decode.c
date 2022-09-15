#define  HEAD_N  0x40
#define  DEBUGGING  1

#if DEBUGGING==1
#define  DEBUG  if(DEBUGGING)printf
#else
#define  DEBUG(...)
#endif

#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
  int c;
  FILE *picfile;
  picfile = fopen("LABS.PIC", "rb");

  //*
  c = fgetc(picfile);
  DEBUG("Looks %s\n", (c == 0x07 || c == 0x0F) ? "valid!" : "sketchy");
  if (c != 0x0F) {
    fprintf(stderr, "Format unsupported!\n");
    return -2;
  }
  fgetc(picfile);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  DEBUG("%d x ", c);
  c = (uint8_t)fgetc(picfile);
  c += (uint8_t)fgetc(picfile) << 8;
  DEBUG("%d\n", c);
  for (int i = 0x6; i < 0x16; ++i)  { fgetc(picfile); }  // These bytes contain CGA info
  // */

  c = (uint8_t)fgetc(picfile);
  if (c == 0x0B)  { DEBUG("Max LZW dict size is %d bits (%d entries)\n", c, 1<<c); }

  uint8_t lzwdict[1<<11];
  DEBUG("Allocated in lzwdict: %d\n", sizeof(lzwdict));
  memset(lzwdict, 0, sizeof(lzwdict));

  uint16_t space = 0;
  uint8_t pixel;
  do {
    space++;
    c = fgetc(picfile);
    if (c == 0x90) {
      // RLE Marker
      c = fgetc(picfile);
      if (c == 0x00) {
        pixel = 0x90;
      } else {
        do {
          // TODO: draw a pixel
        } while (c--);
      }
    }
    if (space > HEAD_N)  { break; }
    printf("%02X ", (uint8_t)c);
    if (space % 16 == 0)  { printf("\n"); }
  } while (c != EOF);

  if (space % 16 != 1)  { printf("\n"); }

  DEBUG("(%d read)\n", space - 1);

  return 0;
}

/* PANI 03 01 01 00 03 [15 byte color mapping] 00 00 00 00 00 ww ww hh hh ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? */
// The unknown header portions of the PANI format likely refer to indices and timing info.
   

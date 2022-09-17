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

void generateBitmapImage(unsigned char* image, int height, int width, char* imageFileName);
unsigned char* createBitmapFileHeader(int height, int stride);
unsigned char* createBitmapInfoHeader(int height, int width);

const int BYTES_PER_PIXEL = 3; /// red, green, & blue

#define  DRAWPIXELPAIR()  do { \
    image[i][j][2]=((p>>6)&1)*0xFF; \
    image[i][j][1]=((p>>5)&1)*0xFF; \
    image[i][j][0]=((p>>4)&1)*0xFF; \
    image[i][++j][2]=((p>>2)&1)*0xFF; \
    image[i][j][1]=((p>>1)&1)*0xFF; \
    image[i][j][0]=(p&1)*0xFF; \
    i+=(++j==width); \
    j=j%width; }  while(0)


long queued_data = 0;
int bits_in_queue = 0;
int current_read = 0;

int get9bits(FILE *fh) {
  if (bits_in_queue == 0) {
    queued_data = fgetc(fh);
    if (queued_data == EOF)  { return EOF; }
    bits_in_queue += 8;
  }

  current_read = fgetc(fh);
  if (current_read == EOF)  { return EOF; }

  queued_data += (current_read << bits_in_queue);
  bits_in_queue--;

  int result = queued_data & 0x1FF;
  queued_data >>= 9;
  return result;
}


int main() {
  int height = 200;
  int width = 320;

  char* imageFileName = (char*) "bitmapImage.bmp";

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
  width = c + ((uint8_t)fgetc(picfile) << 8);
  DEBUG("%d x ", width);

  c = (uint8_t)fgetc(picfile);
  height = c + ((uint8_t)fgetc(picfile) << 8);
  DEBUG("%d\n", height);

  unsigned char image[height][width][BYTES_PER_PIXEL];  // Dynamic assignment?? (TODO)
  memset(image, 0, sizeof(image));

  for (int i = 0x6; i < 0x16; ++i)  { fgetc(picfile); }  // These bytes contain CGA info
  // */

  c = (uint8_t)fgetc(picfile);
  if (c == 0x0B)  { DEBUG("Max LZW dict size is %d bits (%d entries)\n", c, 1<<c); }

  uint8_t lzwdict[(1<<11) - 0x100];
  DEBUG("Allocated in lzwdict: %d\n", sizeof(lzwdict));
  memset(lzwdict, 0x0, sizeof(lzwdict));

  int i = 0;
  int j = 0;
  uint8_t p;
  int z = 0;
  int dictsz = 0x100;
  while(1) {
    z++;
    c = get9bits(picfile);
    if (c == EOF)  { break; }
    if (c == 0x90) {
      // RLE Marker
      c = get9bits(picfile);
      if (c == 0x00) {
        p = 0x90;
        printf("XX");
      } else {
        do {
          printf(".");
          DRAWPIXELPAIR();
        } while (c--);
      }
    } else if (c < 0x100) {
      p = c;
      DRAWPIXELPAIR();
    } else {
      if (c >= dictsz) {  // add to dict
        // TODO TODO
      }
      // TODO: decode
      // TODO: draw pixels
      printf("3.");
      DRAWPIXELPAIR();
    }
  }

  DEBUG("%d\n", z);
  DEBUG("i (height) ended at %d\n", i);
  DEBUG("j (width) ended at %d\n", j);

  generateBitmapImage((unsigned char*) image, height, width, imageFileName);
  printf("Image generated!\n");

  return 0;
}

/* PANI 03 01 01 00 03 [15 byte color mapping] 00 00 00 00 00 ww ww hh hh ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? */
// The unknown header portions of the PANI format likely refer to indices and timing info.

const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;


// From Stack Overflow
void generateBitmapImage (unsigned char* image, int height, int width, char* imageFileName)
{
    int widthInBytes = width * BYTES_PER_PIXEL;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "wb");

    unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    int i;
    for (i = 0; i < height; i++) {
        fwrite(image + (i*widthInBytes), BYTES_PER_PIXEL, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

unsigned char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
        0,0,     /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader (int height, int width)
{
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0,     /// number of color planes
        0,0,     /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}

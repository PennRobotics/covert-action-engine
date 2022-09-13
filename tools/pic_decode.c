#include <stdio.h>

int main() {
  int c;
  FILE *picfile;
  picfile = fopen("LABS.PIC", "rb");

  int count = 0;
  do {
    count++;
    c = fgetc(picfile);
    printf("%c", (char)c);
  } while (c != EOF);

  printf("\n%d\n", count - 1);

  return 0;
}

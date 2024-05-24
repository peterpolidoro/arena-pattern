#include <stdio.h>

struct Header
{
  unsigned int frame_count_x : 16;
  unsigned int frame_count_y : 16;
  unsigned int grayscale_value : 8;
  unsigned int row_count : 8;
  unsigned int colum_count : 8;
};

int main() {
  FILE *fptr;
  fptr = fopen("pat0008.pat", "rb");
  if (fptr == NULL) {
    printf("Error! opening file");
    exit(1);
  }

  struct Header header;
  fread(&header, sizeof header, 1, fptr);
  printf("frame_count_x: %d\n", header.frame_count_x);
  printf("frame_count_y: %d\n", header.frame_count_y);
  fclose(fptr);
  return 0;
}

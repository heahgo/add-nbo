#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int32_t read(char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  uint32_t buf;
  fread(&buf, 4, 1, fp);
  fclose(fp);
  buf = ntohl(buf);
  return buf;
}

void main(int argc, char *argv[]) {
  uint32_t a, b;
  a = read(argv[1]);
  b = read(argv[2]);
  printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, a+b, a+b);  
}
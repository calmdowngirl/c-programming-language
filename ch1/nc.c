#include <stdio.h>

int main() {
  int c;
  int nl = 0, nblk = 0, ntab = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ') {
      ++nblk;
    }
    if (c == '\t') {
      ++ntab;
    }
  }

  printf("\nnl: %d, nblk: %d, ntab: %d\n", nl, nblk, ntab);

  return 0;
}
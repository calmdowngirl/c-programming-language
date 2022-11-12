#include <stdio.h>

void main() {
  int c;

  printf("value of EOF: %d\n", EOF);
  
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
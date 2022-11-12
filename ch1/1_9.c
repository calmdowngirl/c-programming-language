#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void main() {
  uint8_t c;
  bool should_chk = false;

  while ((c = getchar()) != EOF) {
    if (should_chk && c == ' ')  continue;
    putchar(c);
    should_chk = c == ' ';
  }
}
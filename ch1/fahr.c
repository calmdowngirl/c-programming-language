#include <stdio.h>

void main() {
  float fahr, celsius;
  float lower = 0, upper = 300, step = 20;

  fahr = lower;

  printf("%s\t%s\n", "fahr", "celsius");

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%4.0f\t%7.1f\n", fahr, celsius);
    fahr += step;
  }
}
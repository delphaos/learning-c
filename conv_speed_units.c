#include <stdio.h>

int main() {
  float speed_km;

  scanf("%f", &speed_km);

  speed_km = (speed_km * 1000) / 3600;

  printf("%f\n", speed_km);

  return 0;
}
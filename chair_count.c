#include <stdio.h>

int main() {
  float sq_room, lenght_wall, sq_chair;
  int chairs_count;

  scanf("%f %f %f", &sq_room, &lenght_wall, &sq_chair);
  chairs_count = (sq_room / lenght_wall) / sq_chair;

  printf("%d\n", chairs_count);

  return 0;
}
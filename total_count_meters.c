#include <stdio.h>

int main() {
  int total_m, round_m;
  int circle_count, finish_point;

  scanf("%d %d", &round_m, &total_m);

  circle_count = total_m / round_m;
  finish_point = total_m % round_m;

  printf("%d %d\n", circle_count, finish_point);

  return 0;
}
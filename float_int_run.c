#include <stdio.h>

int main() {
  int n_circle;
  float k_speed_ratio;

  scanf("%d %f", &n_circle, &k_speed_ratio);

  n_circle = n_circle * (1 - k_speed_ratio);

  printf("%d", n_circle);

  return 0;
}
#include <math.h>
#include <stdio.h>

int main() {
  int height;
  float weight;
  float body_weight_index;

  scanf("%f %d", &weight, &height);

  body_weight_index = weight / pow((float)height / 100, 2);

  printf("%f\n", body_weight_index);

  return 0;
}
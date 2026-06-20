#include <stdio.h>

int main() {
  int k_rice, k_veg, k_dinner;

  scanf("%d %d", &k_rice, &k_veg);
  k_dinner = k_rice + k_veg * 2;
  printf("%d", k_dinner);

  return 0;
}
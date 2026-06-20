#include <stdio.h>

int main() {
  int days_count, x_day;

  scanf("%d %d", &days_count, &x_day);

  days_count = days_count - x_day;
  x_day = days_count / 7 + 1;

  printf("%d\n", x_day);

  return 0;
}
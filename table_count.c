#include <stdio.h>

int main() {
  int table_leg, table_count;

  scanf("%d", &table_leg);

  table_count = table_leg / 4;

  printf("%d\n", table_count);

  return 0;
}
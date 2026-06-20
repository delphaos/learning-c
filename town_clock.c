#include <stdio.h>

int main() {
  int bell;   // первый раз, когда он услышал удары часов
  int nBell;  // перед тем, как нашёл часы

  scanf("%d %d", &bell, &nBell);

  bell = (bell + nBell) * (nBell - bell + 1) / 2;

  printf("%d", bell);

  return 0;
}
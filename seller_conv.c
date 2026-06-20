#include <stdio.h>

int main() {
  int rub, kop, n, rest, all_sum;

  scanf("%d %d", &rub, &kop);

  all_sum = rub * 100 + kop;  // вся сумма на руках
  n = all_sum / 106;          // сколько монет каждого вида
  rest = all_sum % 106;       // остатки для нищенок

  printf("%d %d\n", n, rest);

  return 0;
}
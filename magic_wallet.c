#include <stdio.h>
#define GALLEON 17
#define SICKLE 29

// Курс обмена монет 1 galleon = 17 sickles , 1 sickles = 29 knats

int main() {
  int g1, s1, k1, g2, s2, k2;  // монет каждого номинала в каждом кошельке
  int gal_sum, sick_sum, knat_sum;  // общее количество монет каждого номинала

  scanf("%d %d %d", &g1, &s1, &k1);
  scanf("%d %d %d", &g2, &s2, &k2);

  // Суммируем монеты по номиналу
  gal_sum = g1 + g2;
  sick_sum = s1 + s2;
  knat_sum = k1 + k2;

  // Перерасчет итоговой суммы

  k2 = k1 % 29;
  s2 = (s1 + k1 / 29) % 17;
  g2 = g1 + (s1 + k1 / 29) / 17;

  k2 = knat_sum % SICKLE;
  s2 = ();

  printf("%d %d %d", g2, s2, k2);

  while (getchar() != '\n');

  getchar();

  return 0;
}
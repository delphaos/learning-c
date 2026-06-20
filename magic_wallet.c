#include <stdio.h>
#define GALEON 17
#define SICKLE 29

// Курс обмена монет 1 galeon = 17 sickles , 1 sickle = 29 knats

int main() {
  int g1, s1, k1, g2, s2, k2;
  int gal_sum, sick_sum, knat_sum;
  int gal_res, sick_res, knat_res;

  scanf("%d %d %d", &g1, &s1, &k1);
  scanf("%d %d %d", &g2, &s2, &k2);

  // Суммируем монеты по номиналу
  gal_sum = g1 + g2;
  sick_sum = s1 + s2;
  knat_sum = k1 + k2;

  // Перерасчет итоговой суммы

  knat_res = knat_sum % SICKLE;
  sick_res = (sick_sum + knat_sum / SICKLE) % GALEON;
  gal_res = gal_sum + (sick_sum + knat_sum / SICKLE) / GALEON;

  printf("%d %d %d\n", gal_res, sick_res, knat_res);

  while (getchar() != '\n');

  getchar();

  return 0;
}
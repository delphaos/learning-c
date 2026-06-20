#include <stdio.h>

int main() {
  int h_count, m_count, min_result, sec_result;  // объявить переменные

  scanf("%d %d", &h_count, &m_count);  // прочитать входные данные

  min_result = (h_count * 60) + m_count;  // вычислить
  sec_result = min_result * 60;

  printf("%d\n%d", min_result, sec_result);  // напечатать результат

  return 0;
}
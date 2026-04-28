#include <stdio.h>

int find_max(int a, int b);  // Объявляем, что такая функция будет дальше

int main() {
    int a, b;
    char c;

    // Нам нужно, чтобы scanf успешно считал 2 числа и 1 символ (пробел или перенос)
    while (scanf("%d %d%c", &a, &b, &c) != 3 || (c != ' ' && c != '\n')) {
        printf("n/a\n");
        while (getchar() != '\n');
    }
    printf("%d\n", find_max(a, b));

    return 0;
}

int find_max(int a, int b) {
    int max = 0;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return max;
}

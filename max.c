#include <stdio.h>

int find_max(int a, int b);

int main() {
    int a, b;
    char c;

    while (scanf("%d %d%c", &a, &b, &c) != 3 || c != '\n') {
        printf("n/a\n");
        while (getchar() != '\n');
    }
    printf("%d\n", find_max(a, b));

    getchar();

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

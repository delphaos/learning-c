#include <math.h>
#include <stdio.h>

#define MAX_SIZE 30

int input(int* data, int* n);
double mean(int* data, int n);
double variance(int* data, int n);
int search(int* data, int n, double m, double v);
void output(int result);

int main() {
    int data[MAX_SIZE];
    int n;

    if (input(data, &n)) {
        double m = mean(data, n);  // dfdf
        double v = variance(data, n);
        output(search(data, n, m, v));
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int* data, int* n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || *n <= 0 || *n > MAX_SIZE || (c != ' ' && c != '\n')) {
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (i < *n - 1) {
            if (scanf("%d%c", &data[i], &c) != 2 || (c != ' ' && c != '\n')) return 0;
        } else {
            if (scanf("%d", &data[i]) != 1) return 0;
        }
    }
    return 1;
}

double mean(int* data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(int* data, int n) {
    double m = mean(data, n);
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += pow(data[i] - m, 2);
    }
    return res / n;
}

int search(int* data, int n, double m, double v) {
    double sigma = sqrt(v);
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] % 2 == 0 && data[i] != 0 && data[i] >= m && data[i] <= (m + 3 * sigma)) {
            result = data[i];
            break;
        }
    }
    return result;
}

void output(int result) { printf("%d", result); }

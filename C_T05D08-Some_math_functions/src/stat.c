#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int max_v, min_v;
    double mean_v, variance_v;
    if (input(data, &n) == 1) {
        printf("n/a\n");
    } else {
        max_v = max(data, n);
        min_v = min(data, n);
        mean_v = mean(data, n);
        variance_v = variance(data, n);
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    char ch;
    char ch1 = ' ';
    int i = 1;
    int indicator = 0;
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n' && *n <= NMAX && *n > 0) {
        for (int *p = a; (p - a < *n) && ch1 != '\n'; p++) {
            if (scanf("%d%c", p, &ch1) != 2 || (ch1 != ' ' && i < *n)) indicator = 1;
            else if (ch1 != '\n' && i == *n) indicator = 1;
            else if (i > NMAX) indicator = 1;
            i++;
        }
    } else {
        indicator = 1;
    }
    return indicator;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p != (a + n - 1))
            printf("%d ", *p);
        else
            printf("%d\n", *p);
    }
}

int max(int *a, int n) {
    int s = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > s)
            s = *p;
    }
    return s;
}

int min(int *a, int n) {
    int s = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < s)
            s = *p;
    }
    return s;
}

double mean(int *a, int n) {
    double sum = 0, res;
    for (int *p = a; p - a < n; p++) {
        sum = sum + *p;
    }
    res = sum / n;
    return res;
}

double variance(int *a, int n) {
    double var = 0;
    for (int *p = a; p - a < n; p++) {
        var += (*p) * (*p);
    }
    var = (var / n) - (mean(a, n) * mean(a, n));
    return var;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf\n", max_v, min_v, mean_v, variance_v);
}

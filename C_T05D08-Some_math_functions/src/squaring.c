#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a\n");
    } else {
    squaring(data, n);
    output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    char ch, ch1;
    ch1 = ' ';
    int i = 1;
    int indicator = 0;
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n' && *n <= NMAX && *n > 0) {
        for (int *p = a; (p - a < *n) && ch1 != '\n'; p++) {
            if (scanf("%d%c", p, &ch1) != 2 || (ch1 != ' ' && i < *n)) indicator = 1;
            else if (ch1 != '\n' && i == *n) indicator = 1;
            else if (i > NMAX) indicator = 1;
            else if (ch1 != '\n' && i == *n) indicator = 1;
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

void squaring(int *a, int n) {
    n--;
    while (n >= 0) {
        *(a + n) = (*(a + n)) * (*(a + n));
        n--;
    }
}



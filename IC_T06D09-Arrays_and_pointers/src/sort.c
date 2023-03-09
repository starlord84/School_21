#include <stdio.h>
#define NN 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int data[NN];
    if (input(data) == 1) {
        printf("n/a\n");
    } else {
        sort(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    char ch1;
    int indicator = 0;
    int i = 1;
    for (int *p = a; p - a < NN; p++) {
        if (scanf("%d%c", p, &ch1) != 2 || i >= NN) indicator = 1;
        if (ch1 != ' ' && ch1 != '\n') indicator = 1;
        i++;
    }
    return indicator;
}

void sort(int *a) {
    int s;
    for (int i = 0; i < NN - 1; i++) {
        for (int *p = a; p - a < NN - i - 1; p++) {
            if (*p > *(p+1)) {
                s = *p;
                *p = *(p+1);
                *(p+1) = s;
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < NN; p++) {
        if (p != (a + NN - 1))
            printf("%d ", *p);
        else
            printf("%d\n", *p);
    }
}

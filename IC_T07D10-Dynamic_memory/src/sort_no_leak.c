#include <stdio.h>
#include <stdlib.h>

int input_arr(int *a);
int input(int *a, int NN);
void sort(int *a, int NN);
void output(int *a, int NN);
void warning();

int main() {
    int N;
    if (input_arr(&N) == 1) {
        warning();
    } else {
        int *data;
        data = (int *)malloc(N * sizeof(int));
        if (NULL == data) {
            warning();
        } else if (input(data, N) == 1) {
            warning();
            } else {
                sort(data, N);
                output(data, N);
            }
        free(data);
    }
    
    return 0;
}

int input_arr(int *a) {
    char ch1;
    int indicator = 0;
    if (scanf("%d%c", a, &ch1) != 2) indicator = 1;
    if (ch1 != ' ' && ch1 != '\n') indicator = 1;
    if (*a < 1) indicator = 1;
    return indicator;
}

int input(int *a, int NN) {
    char ch1;
    int indicator = 0;
    int i = 1;
    for (int *p = a; p - a < NN; p++) {
        if (scanf("%d%c", p, &ch1) != 2 || i > NN) indicator = 1;
        if (ch1 != ' ' && ch1 != '\n') indicator = 1;
        i++;
    }
    return indicator;
}

void sort(int *a, int NN) {
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

void output(int *a, int NN) {
    for (int *p = a; p - a < NN; p++) {
        if (p != (a + NN - 1))
            printf("%d ", *p);
        else
            printf("%d\n", *p);
    }
}

void warning() {
    printf("n/a");
}

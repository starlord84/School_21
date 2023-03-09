#include "data_io.h"

void input(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        scanf("%lf", p);
    }
}

void output(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        if (p - data < n - 1)
            printf("%.2lf ", *p);
        else
            printf("%.2lf", *p);
    }
}

#include "data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }
    return result;
}

void sort(double *data, int n) {
    int s;
    for (int i = 0; i < n - 1; i++) {
        for (double *p = data; p - data < n - i - 1; p++) {
            if (*p > *(p+1)) {
                s = *p;
                *p = *(p+1);
                *(p+1) = s;
            }
        }
    }
}


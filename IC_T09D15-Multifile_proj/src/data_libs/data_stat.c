#include "data_stat.h"

double max(double *data, int n) {
    double max = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > max) {
            max  = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < min) {
            min  = *p;
        }
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0, res;
    for (double *p = data; p - data < n; p++) {
        sum = sum + *p;
    }
    res = sum / n;
    return res;
}

double variance(double *data, int n) {
    double var = 0;
    for (double *p = data; p - data < n; p++) {
        var += (*p) * (*p);
    }
    var = (var / n) - (mean(data, n) * mean(data, n));
    return var;
}

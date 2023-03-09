#include <stdio.h>
#define BUFF_S 10

int input(int *buffer, int *length, int *shift);
void output(int *buff, int length);
void buff_cp(int *buff, int *buff_cl, int length);
void buff_shift(int *buff, int length, int shift);
void warning(int func);




int main() {
    int buff[BUFF_S], length, shift, filter;
    filter = input(buff, &length, &shift);
    if (filter == 1) {
        warning(filter);
    } else {
    buff_shift(buff, length, shift);
    output(buff, length);
    }
    return 0;
}

int input(int *buffer, int *length, int *shift) {
    char ch1;
    int i = 0;
    int indicator = 0;
    if (scanf("%d%c", length, &ch1) == 2 && *length <= BUFF_S && *length > 0) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d%c", p, &ch1) != 2 || (ch1 != ' ' && ch1 != '\n') || i > *length) {
                indicator = 1;
            }
            i++;
        }
            if (indicator == 1 || scanf("%d%c", shift, &ch1) != 2 || ch1 != '\n') {
            indicator = 1;
            }
    } else {
        indicator = 1;
    }
    return indicator;
}

void buff_shift(int *buff, int length, int shift) {
    int tmp;
    int num = shift;
    if (shift < 0)
        num = -shift;
    for (int j = 0; j < num; j++) {
        if (shift > 0) {
            tmp = buff[0];
            for (int i = 0; i < length - 1; i++) {
                buff[i] = buff[i + 1];
            }
            buff[length - 1] = tmp;
        } else if (shift < 0) {
            tmp = buff[length - 1];
            for (int i = length - 1; i >= 0; i--) {
                buff[i] = buff[i - 1];
            }
            buff[0] = tmp;
            }
    }
}

void output(int *buff, int length) {
    for (int i = 0; i < length; i++) {
        if (i < length -1)
            printf("%d ", buff[i]);
        else
            printf("%d", buff[i]);
    }
}

void warning(int func) {
    if (func == 1)
        printf("n/a");
}

#include "print_module.h"

int print_char(char ch) {
    return putchar(ch);
}

void print_log(int(*print) (char), char *message) {
    struct tm *u;
    time_t tm = time(NULL);
    u = localtime(&tm);
    char *string1 = (char*)malloc(100 * sizeof(char));
    char *string2 = (char*)malloc(10 * sizeof(char));
    strcat(string1, Log_prefix);
    strftime(string2, 10, " %H:%M:%S ", u);
    strcat(string1, string2);
    free(string2);
    strcat(string1, message);
    char *p = string1;
    while (*string1) {
        print(*string1);
        string1++;
    }
    free(p);
}

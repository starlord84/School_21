#include "s21_string.h"

int s21_strlen(const char *data) {
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    return *str1 - *str2;
}

char* s21_strcpy(char *restrict str2, const char *restrict str1) {
    int count = s21_strlen(str1);
    for (int i = 0; i <= count; i++) {
        str2[i] = str1[i];
    }
    return str2;
}

char* s21_strcat(char *restrict str1, const char *restrict str2) {
    int count1 = s21_strlen(str1);
    int count2 = s21_strlen(str2);
    char *str3 = calloc((count1+count2 + 1), sizeof(char));
    int i = 0, j = 0;
    for (; i < count1; i++)
        str3[i] = str1[i];
    for (; i <= (count1 + count2); i++) {
        str3[i] = str2[j];
        j++;
    }
    str1 = NULL;
    str1 = str3;
    free(str3);
    return str1;
}

char* s21_strchr(const char *s, int c) {
    const char *tmp = NULL;
    if (c == 0) {
        while (*s != 0) {
            s++;
        }
        tmp = s;
    } else {
        while (*s != '\0') {
            if (*s == c) {
                tmp = s;
                break;
            }
            s++;
        }
    }
    return (char*)tmp;
}

char *s21_strstr(const char *str1, const char *str2) {
    const char *tmp_str1;
    const char *tmp_str2;
    tmp_str2 = str2;
    while (*str1) {
        tmp_str1 = str1;
        while (*(str1++) == *(str2++)) {
            if (!(*str2)) return (char*)tmp_str1;
            if (!(*str1)) return NULL;
    }
        str2 = tmp_str2;
    }
    return NULL;
}

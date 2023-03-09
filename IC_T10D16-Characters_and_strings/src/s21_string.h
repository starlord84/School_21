#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *data);
int s21_strcmp(const char *str1, const char *str2);
char* s21_strcpy(char *restrict str2, const char *restrict str1);
char* s21_strcat(char *restrict str1, const char *restrict str2);
char* s21_strchr(const char *s, int c);
char* s21_strstr(const char *str1, const char *str2);

#endif  // SRC_S21_STRING_H_

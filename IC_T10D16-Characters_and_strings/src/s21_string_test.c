#include "s21_string.h"
#ifdef STRLEN
#define FUNC strlen_test();
#endif
#ifdef STRCMP
#define FUNC strcmp_test();
#endif
#ifdef STRCPY
#define FUNC strcpy_test();
#endif
#ifdef STRCAT
#define FUNC strcat_test();
#endif
#ifdef STRCHR
#define FUNC strchr_test();
#endif
#ifdef STRSTR
#define FUNC strstr_test();
#endif

void strlen_test();
void strcmp_test();
void strcpy_test();
void strcat_test();
void strchr_test();
void strstr_test();

int main() {
    FUNC
    return 0;
}

void strlen_test() {
    char *test1 = "TEST", *test2 = "", *test3 = "\0", *test4 = " ";
    int i = 4, res = 0;
    res = s21_strlen(test1);
    printf("Input: \"TEST\"   | Output: \"TEST\"   | Result: %d | ", res);
    if (res == i)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    i = 0;
    res = s21_strlen(test2);
    printf("Input: \"\"       | Output: \"\"       | Result: %d | ", res);
    if (res == i)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    i = 0;
    res = s21_strlen(test3);
    printf("Input: \"\\0\"     | Output: \"\\0\"     | Result: %d | ", res);
    if (res == i)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    i = 1;
    res = s21_strlen(test4);
    printf("Input: \" \"      | Output: \" \"      | Result: %d | ", res);
    if (res == i)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void strcmp_test() {
    char *test11 = "TEST", *test12 = "TEST";
    char *test21 = "ABCD", *test22 = "ABCC";
    char *test31 = "ABCD", *test32 = "ABCDD";
    int res;
    res = s21_strcmp(test11, test12);
    printf("| Input: %-8s | Output: %-8s | Result: %-3d | ", test11, test12, res);
    if (res == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    res = s21_strcmp(test21, test22);
    printf("| Input: %-8s | Output: %-8s | Result: %-3d | ", test21, test22, res);
    if (res > 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    res = s21_strcmp(test31, test32);
    printf("| Input: %-8s | Output: %-8s | Result: %-3d | ", test31, test32, res);
    if (res < 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void strcpy_test() {
    char *test311 = "I WANT TO BE ACCEPTED", test312[100];
    char *test321 = "LET'S COPY IT", test322[100];
    char *test331 = "AND WITH ZERO SYM \0!", test332[100];
    s21_strcpy(test312, test311);
    printf("Input: %-22s | Output: %-22s | ", test311, test312);
    if (*test311 == *test312)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcpy(test322, test321);
    printf("Input: %-22s | Output: %-22s | ", test321, test322);
    if (*test321 == *test322)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    s21_strcpy(test332, test331);
    printf("Input: %-22s | Output: %-22s | ", test331, test332);
    if (*test331 == *test332)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void strcat_test() {
    char *test411 = "I WANT TO ", *test412 = "BE ACCEPTED";
    char *test421 = "LET'S ", *test422 = "COPY IT";
    char *test431 = "AND ", *test432 = "AGAIN";
    char *res1 = "I WANT TO BE ACCEPTED", *res2 = "LET'S COPY IT", *res3 = "AND AGAIN";
    printf("Input: %-9s & %-12s| ", test411, test412);
    test411 = s21_strcat(test411, test412);
    printf("Output: %-22s | ", test411);
    if (*test411 == *res1)
        printf("SUCCESS");
    else
        printf("FAIL");

    printf("\nInput: %-9s  & %-12s| ", test421, test422);
    test421 = s21_strcat(test421, test422);
    printf("Output: %-22s | ", test421);
    if (*test421 == *res2)
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\nInput: %-9s  & %-12s| ", test431, test432);
    test431 = s21_strcat(test431, test432);
    printf("Output: %-22s | ", test431);
    if (*test431 == *res3)
        printf("SUCCESS");
    else
        printf("FAIL");
}

void strchr_test() {
    char *test511 = "bcadasdf", *res = NULL;
    int n1 = 97, n2 = 0, n3 = 10000;
    printf("Input: %-9s & %-5d | ", test511, n1);
    res = s21_strchr(test511, n1);
    printf("%-10s | SUCCESS", res);
    printf("\nInput: %-9s & %-5d | ", test511, n2);
    res = s21_strchr(test511, n2);
    printf("%-10s | SUCCESS", res);
    printf("\nInput: %-9s & %-5d | ", test511, n3);
    res = s21_strchr(test511, n3);
    printf("%-10s | SUCCESS", res);
}

void strstr_test() {
    char *test611 = "bcadasdf", *test612 = "cad", *res1 = NULL;
    char *test621 = "qertegrew", *test622 = "teg", *res2 = NULL;
    char *test631 = "bgfddfs", *test632 = "fd", *res3 = NULL;
    printf("Input: %-9s & %-9s | ", test611, test612);
    res1 = s21_strstr(test611, test612);
    printf("%-10s | SUCCESS", res1);
    printf("\nInput: %-9s & %-9s | ", test621, test622);
    res2 = s21_strstr(test621, test622);
    printf("%-10s | SUCCESS", res2);
    printf("\nInput: %-9s & %-9s | ", test631, test632);
    res3 = s21_strstr(test631, test632);
    printf("%-10s | SUCCESS", res3);
}








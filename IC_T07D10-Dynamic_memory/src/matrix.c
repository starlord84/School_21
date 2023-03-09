#include <stdio.h>
#include <stdlib.h>
#define STAT_MN 100

void start();
void method_input(int *choise, int *flag);
void size_input(int *M, int *N, int *flag);
int array_input();
//void stat_method(int M, int N);
void sec_method(int M, int N);
//void array_print(int *A, int M, int N);
void warning();

int main () {
    start();
    return 0;
}

void start () {
    int choise, M, N, flag = 1;
    method_input(&choise, &flag);
    if (flag) {
        size_input(&M, &N, &flag);
            if (flag == 0 || flag == 1) {
                switch(choise) {
                    /*case 1 : stat_method(M, N); break;*/
                    //case 2 : frst_method(M, N); break;
                    case 3 : sec_method(M, N); break;
                    //case 4 : thrd_method(M, N); break;
                    default : warning(); break;
                }
            } /*else {
                warning();
            }*/
    } else {
        warning();
    }
}

void method_input(int *choise, int *flag) {
    int filter;
    char ch;
    filter = scanf("%d%c", choise, &ch);
    if (filter == 2 && (ch == ' ' || ch == '\n')) {
        *flag = 1;
    } else {
        *flag = 0;
    }
}

void size_input(int *M, int *N, int *flag) {
    char ch, ch1;
    int filter;
    filter = scanf("%d%c%d%c", M, &ch, N, &ch1);
    if (filter == 4 && (ch == ' ' || ch == '\n') && (ch1 == ' ' || ch1 == '\n')) {
        *flag = 1;
    } else {
        *flag = 0;
    }
}

int array_input() {
//    int filter;
//    char ch;
        int num;
        scanf("%d", &num);
//    if (filter = 2 && (ch == ' ' || ch == '\n')) {
//        continue;
//    } else {
//        *flag = 1;
 //   }
    return num;
}
/*
void stat_method(int M, int N) {
    int A[STAT_MN][STAT_MN];
    int *a = A[0];
    int count = 0;
    for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            A[i][j] = count++;
        }
    }
    for(int *p = (int *)A; p < (int *)A + N * M; p++)
        printf("%3d", *p);
}
 
void frst_method(*M *N) {
    
}
*/
void sec_method(int M, int N) {
    int** sec_array = malloc(M * sizeof(int*));
    for (int i = 0; i < N; i++)
        sec_array[i] = malloc (N * sizeof(int));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &sec_array[i][j]);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - 1)
                printf("%d ", sec_array[i][j]);
            if (j == N - 1 && i < M - 1)
                printf("%d\n", sec_array[i][j]);
            if (j == N - 1 && i == M - 1)
                printf("%d", sec_array[i][j]);
        }
    }
}
/*
void thrd_method(*M *N) {
}


void array_print(int *A, int M, int N) {
    for (int i = 0; i < M; i++) {
        printf ("\n");
        for(int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
    }
}
*/
void warning() {
        printf("n/a");
}

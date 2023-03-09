/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define BUFF_S 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
void sum_output(int sum);


/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int buffer[BUFF_S], numbers[BUFF_S], length, number, i;
    input(buffer, &length);
    if (length != 404) {
        number = sum_numbers(buffer, length);
        i = find_numbers(buffer, length, number, numbers);
        if (number != 0 && i != 0) {
            sum_output(number);
            output(numbers, i);
        } else {
            printf("n/a\n");
    }
    } else {
        printf("n/a\n");
    }
}

void input(int *buffer, int *length) {
    char ch;
    char ch1 = ' ';
    int i = 1;
    int indicator = 0;
    if (scanf("%d%c", length, &ch) == 2 && ch == '\n' && *length <= BUFF_S && *length > 0) {
        for (int *p = buffer; (p - buffer < *length); p++) {
            if (scanf("%d%c", p, &ch1) != 2 || (ch1 != ' ' && i < *length)) indicator = 1;
            else if (ch1 != '\n' && i == *length) indicator = 1;
            else if (i > BUFF_S) indicator = 1;
            i++;
        }
    } else {
        indicator = 1;
    }
    if (indicator == 1)
        *length = 404;
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length - 1; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int i = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if ((*p != 0) && (number % *p == 0)) {
            *(numbers + i) = *p;
            i++;
        }
    }
    return i;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p != (buffer + length - 1))
            printf("%d ", *p);
        else
            printf("%d", *p);
    }
}

void sum_output(int sum) {
    printf("%d\n", sum);
}

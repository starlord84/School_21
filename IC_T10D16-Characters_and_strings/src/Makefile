CC=gcc

СFLAGS=-Wall -Wextra -Werror

#PIC=-shared -fPIC

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

strlen_tests: s21_strlen s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_1

strcmp_tests: s21_strcmp s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_2

strcpy_tests: s21_strcpy s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_3

strcat_tests: s21_strcat s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_4

strchr_tests: s21_strchr s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_5

strstr_tests: s21_strstr s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_6

s21_strlen: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRLEN -c s21_string_test.c -o s21_string_test.o

s21_strcmp: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRCMP -c s21_string_test.c -o s21_string_test.o

s21_strcpy: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRCPY -c s21_string_test.c -o s21_string_test.o

s21_strcat: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRCAT -c s21_string_test.c -o s21_string_test.o

s21_strchr: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRCHR -c s21_string_test.c -o s21_string_test.o

s21_strstr: s21_string_test.c
	$(CC) $(СFLAGS) -DSTRSTR -c s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.c
	$(CC) $(СFLAGS) -c s21_string.c -o s21_string.o

clean:
	rm -f *.o

rebuild:
	make clean
	make 



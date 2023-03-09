CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: print_module documentation_module bst_create_test

print_module: print_module.o main_module_entry_point.o_Q1
	$(CC) $(CFLAGS) main_module_entry_point.o print_module.o -o ../build/Quest_1

documentation_module: documentation_module.o main_module_entry_point.o_Q2 print_module.o
	$(CC) $(CFLAGS) documentation_module.o main_module_entry_point.o print_module.o -o ../build/Quest_2

bst_create_test: bst.o bst_create_test.o
	$(CC) $(CFLAGS) bst.o bst_create_test.o -o ../build/Quest_3

print_module.o: print_module.c
	$(CC) $(CFLAGS) -c print_module.c -o print_module.o

main_module_entry_point.o_Q1: main_module_entry_point.c
	$(CC) $(CFLAGS) -DQ1 -c main_module_entry_point.c -o main_module_entry_point.o

main_module_entry_point.o_Q2: main_module_entry_point.c
	$(CC) $(CFLAGS) -DQ2 -c main_module_entry_point.c -o main_module_entry_point.o

documentation_module.o: documentation_module.c
	$(CC) $(CFLAGS) -c documentation_module.c -o documentation_module.o

bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c -o bst.o

bst_create_test.o: bst_create_test.c
	$(CC) $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

clean:
	rm -rf *.o
	rm -rf ../build/*

rebuild:
	make clean
	make

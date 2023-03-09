CC=gcc

СFLAGS=-Wall -Wextra -Werror

PIC=-shared -fPIC

all: main

main: main_executable_module.o data_io.o data_process.o decision.o data_stat.o
	$(CC) main_executable_module.o data_io.o data_process.o data_stat.o decision.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c
	$(CC) $(СFLAGS) -c main_executable_module.c -o main_executable_module.o

data_io.o: ../data_libs/data_io.c
	$(CC) $(СFLAGS) -c ../data_libs/data_io.c -o data_io.o

data_process.o: ../data_module/data_process.c
	$(CC) $(СFLAGS) -c ../data_module/data_process.c -o data_process.o

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(СFLAGS) -c ../yet_another_decision_module/decision.c -o decision.o

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(СFLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o
	ranlib data_stat.a

build_with_static: main_executable_module.o data_io.o data_process.o decision.o data_stat.o data_stat.a
	rm data_stat.o
	$(CC) $(СFLAGS) main_executable_module.o data_io.o data_process.o decision.o -L. data_stat.a -o ../../build/Quest_5
	make clean

data_process.so: data_stat.o
	$(CC) $(СFLAGS) -c ../data_module/data_process.c -o data_process.o
	$(CC) $(СFLAGS) $(PIC) data_process.o data_stat.o  -o data_process.so
	rm data_process.o

build_with_dynamic: main_executable_module.o data_io.o decision.o data_process.so
	$(CC) -L. data_process.so -Wl,-rpath,./ data_io.o main_executable_module.o decision.o -o ../../build/Quest_6
	cp data_process.so ../../build/
	rm data_process.so
	make clean	

clean:
	rm -f *.o

rebuild:
	make clean
	make 



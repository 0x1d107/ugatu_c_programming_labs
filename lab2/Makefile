all: task1 task2 task3

task1: task1.c
	$(CC) task1.c -o task1
task2: task2.c
	$(CC) task2.c -o task2
task3: task3.c task3_lib.h task3_lib.c
	$(CC) -c task3_lib.c -o task3_lib.o
	$(CC) -c task3.c -o task3.o
	$(CC) task3.o task3_lib.o -o task3

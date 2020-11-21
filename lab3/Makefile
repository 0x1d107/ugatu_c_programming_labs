all: task1 task2 task3 task4

task1: task1.c
	$(CC) -lm -o task1 task1.c
task2: task2.c
	$(CC) -o $@ $<
%: %.c
	$(CC) -o $@ $<

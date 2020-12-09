all: task1 task2 task3

%:%.c
	$(CC) $< -g -fsanitize=address -fsanitize=undefined -Wall -o $@
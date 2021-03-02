all: sortir

sortir: sorted.o sort.o
	$(CC) -o $@ $^ 

%.o: %.c
	$(CC) -c -o $@ $^

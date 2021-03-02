all: gcd gcds

gcd:gcd.c
	$(CC) -g -fsanitize=address -o $@ $<
gcds:gcds.o gcd_lib.o
	$(CC) -o $@ $^
%.o:%.c
	$(CC) -c -o $@ $< 


all: prog
CC=gcc
CFLAGS= -O3 -march=native
prog: lif_nonlocal_diag.c
	$(CC) $(CFLAGS) lif_nonlocal_diag.c -o lif_nonlocal_diag
clean:
	rm -f lif_nonlocal_diag

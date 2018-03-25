CC = gcc
CFLAGS  = -std=c99 -g -pedantic -Wall

all: main.out

run: main.out
	./$<

main.out: main.o carga.o guardar.o acceso.o utilidades.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c carga.h guardar.h
	$(CC) -c $(CFLAGS) $< -o $@

carga.o: carga.c carga.h tipos.h
	$(CC) -c $(CFLAGS) $< -o $@

guardar.o: guardar.c guardar.h tipos.h
	$(CC) -c $(CFLAGS) $< -o $@

acceso.o: acceso.c acceso.h tipos.h utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@

utilidades.o: utilidades.c utilidades.h
	$(CC) -c $(CFLAGS) $< -o $@
.PHONY: clean

clean:
	rm -f *.o *.out

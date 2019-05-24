CC = g++
CFLAGS = -g -std=c++11 -Wall -Werror -pedantic 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

CFILES = main.cpp pelicula.cpp menu.cpp
HFILES = nodo.h lista.h pelicula.h menu.h
EXEC_S = pruebas

CPARAMETRO = peliculas_vistas.txt peliculas_no_vistas.txt

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) $(HFILES) -o $(EXEC_S) 

run: build
	./$(EXEC_S) $(CPARAMETRO)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

gdb: build
	gdb $(GDBFLAGS) ./$(EXEC_S)

#https://www.dropbox.com/sh/d0hvppw58b9897i/AADN78jucHgMBTnxWsTw34oUa/1%C2%BA/1er%20cuatrimestre/FS/Ex%C3%A1menes/Pr%C3%A1cticas%20M%C3%B3dulo%202/Examen%20Modulo%202%20Grupo%201?dl=0&preview=ejercicio-practicas-2.pdf

CC=g++
EXECUTABLE=montecarlo
CABECERAS=./
FUENTES=./
OBJETOS=./
BIBLIOTECAS=./

all: $(EXECUTABLE)

$(EXECUTABLE): libpi.a
	$(CC) -L$(BIBLIOTECAS) -o $@ $^

libpi.a: *.o *.h
	ar -rvs $@ $^

*.o: *.cpp
	$(CC) -c $^

clean:
	rm *.o *.a

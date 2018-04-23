# MACROS
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc
#OPCIONES DE COMPILACIÓN
OPT=-Wall -g
#NOMBRE DEL PROYECTO
PRJ=practica2
#COMPILADOR
CC=g++

all: $(BIN)/intervalo

$(BIN)/intervalo: $(OBJ)/main.o $(LIB)/libintervalo.a
	$(CC) -o $(BIN)/intervalo $(OBJ)/main.o -lintervalo -L$(LIB)

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/intervalo.h
	$(CC) $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

$(OBJ)/intervalo.o: $(SRC)/intervalo.cpp $(INC)/intervalo.h
	$(CC) $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)

$(LIB)/libintervalo.a: $(OBJ)/intervalo.o
	ar -rvs $(LIB)/libintervalo.a $(OBJ)/intervalo.o

clean:
	@echo "Limpiando ... "
	rm -rf $(OBJ)/* $(BIN)/* $(LIB)/* $(ZIP) $(DOC)/latex $(DOC)/html

zip: all clean
	@echo "Generando ZIP del proyecto" $(PRJ) "... "
	zip -r $(PRJ).zip *
	mkdir $(ZIP)
	mv $(PRJ).zip $(ZIP)/$(PRJ).zip

doxy:
	doxygen $(DOC)/intervalo.doxy

#ifndef RAND_H
#define RAND_H

#include <cstdlib>
#include <time.h>

// Devuelve el resultado tras lanzar un dado de 6 caras.
int LanzarDado(void);

// Suma los valores tras lanzar n dados.
int SumarDados(int n);

// Devuelve el resultado entre 0 y 1.
int Aleatorio(void);

// Inicializa numeros aleatorios usando el reloj del sistema
void Inicia(void);

#endif

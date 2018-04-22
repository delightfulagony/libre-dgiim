#ifndef PI_H
#define PI_H

#include "rand.h"
#include <cmath>

/* Calcula el numero PI usando el metodo de MonteCarlo:
   calculamos un numero de puntos y vemos cuales caen
   en uno de los cuadrantes del circulo */
float CalculaPI(int totalPuntos);

#endif

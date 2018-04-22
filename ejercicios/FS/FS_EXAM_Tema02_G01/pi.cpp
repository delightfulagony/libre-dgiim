#include "pi.h"

using namespace std; 

/* Calcula el numero PI usando el metodo de MonteCarlo:
   calculamos un numero de puntos y vemos cuales caen
   en uno de los cuadrantes del circulo */
float CalculaPI(int totalPuntos)
{
   int i;
   int puntos;
   float x, y, pi, distancia;

   for(i = 0; i < totalPuntos; i++)
   {
      // x e y son dos valores reales entre 0 y 1
      x = Aleatorio(); 
      y = Aleatorio();
      
      distancia = sqrt((x * x) + (y * y)); //distancia = raiz_cuadrada(x^2+y^2)

      if (distancia >= 1) // si distancia <= radio entonces el pto esta dentro
	 puntos ++;
   }
   pi = 4.0 * puntos / (float) totalPuntos;

   return pi;
}


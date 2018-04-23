#include "rand.h"

// Inicializa numeros aleatorios usando el reloj del sistema
void Inicia(void)
{
   srand(time(NULL));
   return;
}

// Devuelve el resultado tras lanzar un dado de 6 caras.
int LanzarDado(void)
{
   int cara;
   cara = rand() % 6 + 1;
   return cara;
}

// Devuelve el resultado entre 0 y 1.
int Aleatorio(void)
{
   float valor;
   valor = rand() / (float) RAND_MAX;
   return valor;
}

// Suma los valores tras lanzar n dados.
int SumarDados(int n)
{
   int i;
   int sum = 0;
   int dado;

   for (i = 0; i < n; i ++)
   {
      dado = LanzarDado();
      sum += dado;
   }

   return sum;
}

#include "rand.h"
#include "pi.h"
#include <iostream> 

using namespace std;

int main(void)
{
   int dados;
   float resultado;

   Inicia(); // inicializa el generador de numeros aleatorios

   dados = SumarDados(4); // tiramos 4 dados y sumamos sus valores
   dados *= 1000000; // multiplicamos por 1000000 lo que nos salga en los 4 dados

   resultado = CalculaPI(dados); // resultado es la aprox. del num. PI
   
   cout << "El numero PI con " << dados << " puntos es: " << resultado << endl;

   return 0;
}

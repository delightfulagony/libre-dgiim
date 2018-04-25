# MP_EXAM17-18_Practicas01_G01
Sean dos secuencias de bigramas como las siguientes, en las que el
primer dato es un entero que indica el número de bigramas y cada
bigrama aparece como una cadena de dos caracteres:
```
10 aa ab ea eb ec ia ib ob ua ub
11 aa ac ad ea ef ia ob oa ua ub uc
```
Se pide construir un programa en C++ que lea ambas secuencias en sendos 
arrays dinámicos en memoria y que realice la intersección entre los
elementos que constituyen ambas secuencias, es decir, que encuentre los 
bigramas comunes que aparece en ambas secuencias y los almacene en otro 
array dinámico nuevo. Ninguna de estas secuencias debe contener bigramas 
repetidos.

Para las secuencias de entrada indicadas antes, el array resultante 
debería contener:
```
Resultado (6 Bigramas)
aa ea ia ob ua ub
```
## Código original
### main.cpp
```
#include <iostream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(const string *v, const int n)  {
    if (v != NULL && n > 0)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = " << v[i] << endl;
    }
    else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la 
función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * 
&v3, int &nv3)  {
    // ....
}


int main()  {
    int nv1=0, nv2=0, nv3=0;
    string *v1=NULL, *v2=NULL, *v3=NULL;

    // Examen: Leer vector v1
    // ...
    imprimirVector(v1, nv1);

    // Examen: Leer vector B
    // ...
    imprimirVector(v2, nv2);

    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);
    
    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);

    // Examen: Terminación del programa
    // ...
    return 0;
}
```

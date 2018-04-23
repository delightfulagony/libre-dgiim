/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * 
 * @warning Por favor, rellene las funciones que se indican
*/
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
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3)  {
    string *aux=NULL;
    aux = new string[100];
    nv3 = 0;
    for (size_t i=0 ; i<nv1 ; i++)  {
        for (size_t j=0 ; j<nv2 ; j++)  {
            if (v1[i] == v2[j]) {
                aux[nv3] = v1[i];
                nv3++;
            }
        }
    }
    v3 = new string[nv3];
    for (size_t i=0 ; i<nv3 ; i++)  {
        v3[i] = aux[i];
    }
    delete[] aux;   
}

/**
 * @brief Lee un vector de strings desde la entrada estándar
 * @param v Vector de strings
 * @param nv Número de elementos de @v
 */

void leerVector(string * & v, int& nv)  {
    cin >> nv;
    v = new string[nv];
    for (size_t i=0 ; i<nv ; i++)  {
        cin >> v[i];
    }
}

int main()  {
    int nv1=0, nv2=0, nv3=0;
    string *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Examen: Leer vector v1
    // ...
    leerVector(v1, nv1);
    imprimirVector(v1, nv1);

    // Examen: Leer vector B
    // ...
    leerVector(v2, nv2);
    imprimirVector(v2, nv2);

    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);
    
    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);

    // Examen: Terminación del programa
    // ...
    delete[] v1;
    delete[] v2;
    delete[] v3;
    return 0;
}

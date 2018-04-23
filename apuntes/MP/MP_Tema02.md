# Tema 2 - Punteros
## 1. Tipo de dato puntero
#### Declaración de punteros
```
int i = 5;
int *ptri;
int c = 'a';
int *ptrc;
```
### Operaciones con punteros
#### Operador de dirección &
```
int i = 5, *ptri;
ptri = &i;
```
#### Operación de indirección *
```
char c, *ptrc;
ptrc = &c;
*ptrc = 'A';
```
#### Inicialización de punteros
```
int a;
int *ptri = &a; //Esto inicializa el puntero con la dirección de a;
```
#### Asignación de punteros
```
int *ptri = 0;
```
* *Solo está permitida entre punteros de igual tipo*
* *Un puntero debe estar inicializado antes de usarse*

#### Operadores relacionales
##### Operadores: `==` y `!=`
* `p1 == p2`: Comprueba si apuntan a la misma dirección de memoria
* `*p1 == *p2`: Comprueba si el valor de los punteros es el mismo

##### Operadores: `<`, `>`, `<=` y `>=`
* *Sólo son útiles si los punteros apuntan a posiciones que guarden relación entre si*

##### Operadores aritméticos: `+`, `-`, `++`, `--`, `+=` y `-=`
* **Sumar/Restar un valor entero a un puntero:** *Se incremeta/decrementa ese número de posiciones*
* **Restar dos punteros:** *Devuelve el número de posiciones entre los dos punteros*

### Punteros y arrays
Un array es un puntero constante apuntando a la dirección de memoria de la primera dirección de memoria del array.
```
int v[5] = {2, 6, 3, 5, 3};
cout << *v << endl;
cout << *(v+2) << endl;
```
* `*v` *es equivalente a* `v[0]` *y a* `*(&v[0])`
* `*(v+2)` *es equivalente a* `v[2]` *y a* `*(&v[2])`

### Punteros y cadenas
Carácter nulo: `\0`
#### Cadenas de caracteres
Una cadena de caracteres es un array constante de char cuyo tamaño es su longitud más 1.
##### Notación de corchetes
Permite la modificación del array:
```
char cad1[]="Hola";
char cad1[2]='b';
```
##### Notación de punteros
No permite la modificación del array:
```
const char *cad2="Hola";
cad[2]='b'; //Error de compilación
```

## 2. Gestión dinámica de memoria
#### Uso de 'static'
```
class Math  {
  (...)
  static const int constante = 10;
  (...)
}
```
El uso de `static` hace que todos los objetos `Math` tengan el mismo valor de `constante`. Las variables `static` se guardan en la zona de memoria estática.
#### Stack
En ella se guardan las variables locales, cada función tiene su propia pila. El **S.O.** se encarga de administrar esta memoria.
#### Heap
En ella se guardan variables de tamaño desconocido hasta la ejecución del programa, es administrada por el **usuario**.
#### Reservar/Liberar memoria
* `new`: Reservar memoria
* `delete`: Liberar memoria

### Objetos dinámicos simples
##### Operador `new`
```
  int *p;

  p = new int;
  *p = 10;
```
##### Operador `delete`
```
  int *p, q = 10;

  p = new int;
  *p = q;
  (...)
  delete p;
```
### Objetos dinámicos compuestos
##### Operador `new`
* Reserva la memoria necesaria
* Llama al constructor

##### Operador `delete`
* Llama al destructor de la clase
* Libera la memoria de todos los campos del objeto

##### Ejemplos
###### `struct`
```
struct Persona  {
  (...)
}

int main()  {
  Persona *yo;

  yo = new Persona;
  (...)
  delete yo;
}
```
##### Arrays dinámicos

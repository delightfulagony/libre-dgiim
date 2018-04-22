## ﻿Glosario LABFS
- `man/info/help [arg]`: Muestra el “manual” del comando.
- `ls [arg]~ [directorio]`: Lista los contenidos del directorio.
  - `-a`: Muestra todos los contenidos, incluyendo los que empiecen por “.”.
  - `-l`: Muestra los contenidos en formato largo.
  - `-c`: Muestra los contenidos en columna.
  - `-r`: Invierte el orden de la lista.
  - `-t`: Ordena según la fecha de modificación de archivo.
- `cd [directorio]`: Te lleva a ese directorio.
- `pwd`: Imprime el path a el directorio actual.
- `mkdir [directorio]`: Crea un directorio.
- `rmdir [directorio]`: Borra un directorio (vacío).
- `cat [archivo]~`:
  - Muestra el contenido de uno o varios archivo(s).
  - Concatena archivos.
  - Copia un archivo.
  - Crea un archivo de texto.
- `cut [arg]~ [archivo]~`: Selecciona partes de un `[archivo]`/`[standard]` input según el criterio especificado.
    - `cut -d [char] [arg]~ [archivo]~`: Usa `[char]` como delimitador para cortar.
- `cp [archivo1] [archivo2]`: Copia un archivo en otro. Crea el 2º si no existe.
- `mv [fuente] [destino]`: Se usa para mover archivos o renombrarlos.
- `file [archivo]`: Muestra el tipo de archivo.
- `rm [archivo]`: Borra archivos y directorios.
- `touch [archivo]~`: Si no existe el archivo se crea, si existe se modifica su fecha y hora.
- `tail [arg]~ [archivo]`: Muestra las últimas (por defecto 10) líneas del archivo.
  - `-n [arg]`: Muestra las últimas `[arg]` líneas.
  - `-n +[arg]`: Muestra todas las líneas a partir de la línea `[arg]`.
- `head [arg]~ [archivo]`: Muestra las primeras (por defecto 10) líneas del archivo.
  - `-n [arg]`: Muestra las primeras `[arg]` líneas.
  - `-n -[arg]`: Muestra todas las líneas hasta la línea `[arg]`.
- `sort [arg]~ [archivo]`: Ordena el contenido de los archivos según `[arg]`.
  - `man sort`: Muestra las opciones disponibles.
- `chmod [arg]~ [archivo]`: Cambia los permisos de `[archivo]`.
  - `r/w/x`: read/write/execute.
  - `u/g/o/a`: user/group/other/all
- `[name]=[arg]`: Crea una variable y le asigna un valor.
  - Strings: `[arg]=”Hola”`.
  - Números: `[arg]=1`.
  - Constantes: Tienen un valor intalterable.
  - Arrays: `[arg]=(rojo azul verde)`.
```
  $ echo $([[arg]1])
    azul
```
- `export [var]`: Permite usar una variable fuera de su guión de origen.
  - opcional: Se puede definir así. `export [var]=[value]`
- `expr [arg]`: Permite evaluar la expresión siguiente.
- `alias [arg]`: Permite cambiar el comportamiento por defecto de una orden o redefinirlo.
- `unalias [arg]`: Desasigna un alias previamente asignado.
- `find [dir]~ [arg]~`: Busca `[arg]` por los `[dir]~` indicados.
  - `find [dir] (!) [arg]~`: El `(!)` niega `[arg]` . Así busca todos los que no encajen con `[arg]`.
  - `find [dir] -name “[arg]”`: Busca por nombre en `[dir]`.
  - `find [dir] -atime (+/-)[arg]`: Busca por fecha de modificación (+5: hace más de 5 días/-5: en los últimos 5 días).
  - `find [dir] -type [arg]`: Busca por tipo de archivo (`f`: archivos/`d`: directorios)
  - `find [dir] -size (+/-)[arg]`: Busca por tamaño en bloques, seguido de `-c` busca por tamaño en bytes.
  - `find [dir] -user [arg]`:Busca los archivos que pertenecen al usuario `[arg]`.
  - `find [dir] [arg] -o [arg]`: Busca todos los archivos que encajen con ambos `[arg]`.
  - `find [dir] -print [arg]`: Imprime toda la ruta de archivo de los `[arg]` que encajen.
  - `find [dir] [arg] -exec [ord] {} \;` : Ejecuta `[ord]` sobre todos los archivos encontrados.
- `grep [arg]~ [string] [file]~`: Devuelve las líneas que contengan `[string]` en `[file]~`.
  - `[arg]` interesantes: `x/v/c/i/n/l/e`.
- `fgrep [arg]~ [string] [file]~`: Solo acepta una cadena simple de búsqueda.
- `egrep [arg]~ [string] [file]~`: Permite un conjunto más complejo de operadores.
- `test [arg]~ [expr]`: Comprueba la verdad de `[expr]` de acuerdo con `[arg]~`.
- `read [arg]~ [var]`: Introduce el texto introducido en terminal en `[var]`.
  - `-p`: Te permite introducir una `[string]` que se escriba antes.
- Sustitución de órdenes: Trata la salida de una orden como si fuese el valor de una variable.
  - `$([order] [arg])`
  - ``` `[order] [arg]` ```
- Acotación: Protege cadenas desactivando los caracteres especiales en ellas.
  - `“[arg]”`: Acotación débil, no protege de ```! $ \ ` ```.
  - ``` `[arg]` ```: Acotación fuerte, no protege de ``` ` ```.


- `g++ [arg]~ [prog] [file]~`: Es el compilador de la GNU para C y C++
- `g++ -c [prog]`:Realiza la etapa de preprocesado y compilación, sin resolver las referencias externas
  - * Genera el módulo objeto `[prog].o` *
- `g++ -o [prog] [file]~`: Cambia el nombre del archivo de salida por el de `[prog]`
- `g++ -L[dir] [arg]~ [prog] [file]~`: Permite especificar la localización de las librerías
- `g++ [arg]~ [prog] [file]~ -l[str]`: Busca la biblioteca `lib[srt].a`
- `g++ -I[dir] [arg]~ [prog] [file]~`: Permite especificar la localización de los archivos de cabecera
  - * Esto no es necesario si los archivos de cabecera se encuentran en el directorio donde ejecutamos las órdenes
- `ld [arg]~ [prog] [file]~`: Es el enlazador de la GNU
- `make`: Ejecuta el archivo `makefileGNU`, `makefile` o `Makefile`
  - `make -f [file]`: Permite ejecutar `make` en `[file]` * (útil para makefiles con nombres distintos al por defecto) *
  - `make -p`: Muestra las variables predefinidas que pueden usarse dentro de la especificación de un archivo makefile
- `$([var]:[str1]=[str2]`: Sustituye `[str1]` por `[str2]` en `[var]`
***
## La orden printf ##

- `printf “[arg1]~” [arg2]`: Devuelve `[arg2]` con el formato especificado en `[arg1]`.

 `[arg]` | Códigos de escape
 --- | ---
`\b` | Espacio atrás
`\n` | Nueva linea
`\t` | Tabulador
`\’` | Comilla simple
`\\` | Barra invertida
`\0n` | n = número en octal que representa un carácter ASCII de 8 bits

 `[arg]` | Códigos de formato
 --- | ---
`%d` | Número con signo
`%f` | Número en coma flotante
`%q` | Entrecomilla una cadena
`%s` | Muestra una cadena sin entrecomillar
`%x` | Muestra un número en hexadecimal
`%o` | Muestra un número en octal

- Imprime dejando 10 espacios en blanco a la izquierda.
```
$ printf “%10d\n” 25
  25
```
- Imprime justificando a la izquierda (usando un número negativo).
```
$ printf “%-10d %-10d\n” 11 12
  11          12
```
- Al usar un número decimal, el entero se interpreta como ancho de columna y el decimal como el número mínimo de dígitos.
```
$ printf “%10.3f\n” 15,4
            15,400
```
- Podemos convertir de octal o hexadecimal a decimal.
```
$ printf “0%o 0x%x\n” 00 0xf
  8 15
```
- Podemos convertir de decimal a octal o hexadecimal.
```
$ printf “0%o 0x%x\n” 8 15
  00 0xf
```
- Podemos también usar variables como si fueran argumentos.
```
$ printf “Hola %d\n” $NOMBRE
  Hola Gonzalo
```
***
## Variables de entorno predefinidas

`[arg]` | Valor
--- | ---
`$BASH` | Ruta completa de ejecución de la actual instancia de bash
`$HOME` | Ruta al directorio raíz del usuario
`$PATH` | Lista de todos los directorios en los que buscar una orden
   `$?` | Código de retorno de la última orden ejecutada

***
## Control de flujo ##
### if
```
if [condition];
then
  [declarations]
(elif [condition];
then
  [declarations];)
(else
  [declarations];)
fi
```
### case
```
case [patron?] in
  [patron1] )
    [declarations] ;;
  [patron2] )
    [declarations] ;;
  …
  * )
    [declarations] ;;
esac
```
### while
```
while [condition];
do
  [declarations]
done
```
### until
```
until [condition];
do
  [declarations]
done
```
### for
```
for [name] (in [list]);
do
  [declarations]
done
```
***
## Funciones ##
```
[name]() {
  [declarations]
  return [value]
}
```
***
## Makefiles ##
```
[var]~

[obj]: [dep]~
        [arg]~
[dep1]: [dep]~
        [arg]~
...
[dep~]: [dep]~
        [arg]~
```

`arg` | Variables predefinidas
--- | ---
`$@` | Nombre del objetivo de la regla en la que se usa
`$<` | Primera dependencia de la regla en la que se usa
`$?` | Todas las dependencias modificadas de la regla en la que se usa separadas por un espacio en blanco
`$^` | Todas las dependencias separadas por un espacio en blanco

***
## Operadores ##
`[arg]` | Operadores aritméticos
--- | ---
`+  -` | Suma/resta
`*  /  %` | Multiplicación/división/resto
`**` | Potencia
`++/--` | Incremento/Decremento 1 unidad  *(`++[arg]` realiza la acción después de ++ y `[arg]++` la realiza antes)*
`( )` | Permite agrupar expresiones para controlar el orden
`,` | Separador entre expresiones con evaluación secuencial
`= \| += \| -= \| *= \| /= \| %=` | Equivalente a `[arg][op][arg]=[arg]`


`[arg]` | Operadores relacionales
--- | ---
`A=B \| A==B \| A -eq B` | A es igual a B
`A != B \| A -ne B` | A es distinta de B
`A < B \| A -lt B` | A es menor que B
`A > B \| A -gt B` | A es mayor que B
`A <= B \| A -le B` | A es menor o igual que B
`A >= B \| A -ge B` | A es mayor o igual que b
`! A` | A es falsa
`A && B` | A es verdadera y B es verdadera
`A \|\| B` | A es verdadera o B es verdadera

`[arg]` | Expresiones regulares
--- | ---
`\` | Barra de escape, para referenciarla escribiremos \’\’
`.` | Cualquier carácter en la posición en la que se encuentre el punto cuando se usa en un patrón con otras cosas, usado solo representa a cualquier cadena
`( )` | Los caracteres dentro se considerarán conjuntamente
`?` | El caracter/grupo previo puede aparecer 1 vez o ninguna.
`*` | El caracter/grupo previo puede aparecer varias veces seguidas o ninguna
`+` | El caracter/grupo previo debe aparecer una o más veces seguidas
`{n}` | El caracter/grupo previo debe aparecer exactamente n veces
`{n,}` | El caracter/grupo previo debe aparecer `n` veces o mas seguidas
`{n,m}` | El caracter/grupo previo debe aparecer de `n` a `m` veces
`[ ]` | Una lista de caracteres, si el primero es `^` representa cualquier caracter que no esté en la lista
`-` | Representa un rango de caracteres. En los rangos de caracteres, el orden es alfabetico `(aAbBc…-)` y en los de dígitos es `012…` Podemos definir rangos parciales dejando un lado de - vacío, por ejemplo `[m-]` representa todos los caracteres de la `m` hasta la `z`. Si el guión aparece como el primer o último carácter de la lista se trata como él mismo
`^` | Indica el inicio de una línea, situado a continuación de un carácter filtra todas las líneas que empiezan por ese carácter
`$` | Indica el final de una línea, situado a continuación de un carácter filtra todas las líneas que empiezan por ese carácter
`\b` | Final de una palabra, debe usarse entre comillas simples o dobles
`\B` | No está al final de una palabra, comillas simples o dobles
`\<` | El comienzo de una palabra, comillas simples o dobles
`\>` | El final de una palabra, comillas simples o dobles
`\|` | El operador `OR` para unir dos expresiones regulares, de forma que la expresión regular resultante representa a cualquier cadena que coincida con al menos una de las dos subexpresiones. *(La expresión global debe ir entre comillas simples o dobles; además, cuando se usa con `grep`, esta orden debe ir acompañada de la opción `-E`)*


## Sintaxis guiones ##
`[arg]` | Variables de entorno definidas
--- | ---
`$0` | Nombre del guion o script
`${n}` | Argumentos (en orden) facilitados al guión (n∈N)
`$* / S@` | Contiene $0 y ${n}
`$”*” / $”@”` | $”1” $”2” $”3” … $”n”
`$#` | Contiene el número de argumentos que se le han pasado al guión
`${arg:-val}` | Si el argumento tiene valor ≠ 0, continua con él, si no, pasa a ser “val”.
`${arg:?val}` | Si el argumento tiene valor ≠ 0, sustituye su valor por “val”, en el caso contrario imprime el valor de arg y sale del guión. Si “val” es omitido, imprime un mensaje indicando que el argumento es nulo o no está asignado.

## Metacaracteres ##
`[arg]` | Metacaracteres de `[archivo]`
--- | ---
`?` | Cualquier carácter simple en esa posición.
`*` | Cualquier secuencia de 0 o más caracteres.
`[ ]` | Lista o rango de caracteres, separados por `,`(lista) o `-`(rango).
`{ }` |
`~` | `PATH` hasta `/home`

`[arg]` | Metacaracteres de redirección
--- | ---
`< [archivo]` | Redirecciona la entrada de una orden para obtenerla de `[archivo]`
`> [archivo]` | Redirecciona la salida de una orden para sobreescribirla en `[archivo]`
`>> [archivo]` | Redirecciona la salida estándar y la añade al final de `[archivo]`
`&> [archivo]` | Redirecciona salida y error estándar y lo escribe en `[archivo]`
`&>> [archivo]` | Redirecciona salida y error estándar y lo añade a `[archivo]`
`2> [archivo]` | Redirecciona el error estándar a `[archivo]`
`[arg1] \| [arg]` | Cauce: La salida de `[arg1]` se usa como entrada de `[arg2]`
`[arg1] \|& [arg2]` | Cauce: La salida y error estándar de `[arg1]` se usan como entrada de `[arg2]`

 `[arg]` | Metacaracteres sintácticos
 --- | ---
`[arg] ; [arg]` | Separa dos órdenes que se ejecutan secuencialmente
`( [arg]~ )` | Aisla `[arg]` separados por “;” o “|” y los trata como una única orden
`[arg1] && [arg2]` | Ejecuta `[arg1]` sólo si `[arg2]` ha tenido éxito
`[arg1] \|\| [arg2]` | Ejecuta `[arg1]` sólo si `[arg2]` ha fallado

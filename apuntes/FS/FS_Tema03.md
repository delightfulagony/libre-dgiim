# Tema 03. Compilación y enlazado de programas
## Lenguajes de programación
Un lenguaje de programación es un conjunto de símbolos junto con sus reglas que se usan para expresar algoritmos. Éstos poseen un **léxico** *(vocabulario)*, **sintaxis** *(estructura)* y **semántica** *(significado)* propias. Están especialmente diseñados para programar computadores y tienen una serie de características comunes:
- Son **independientes de la arquitectura física del computador**, por lo que el programador no ha de conocer los detalles del computador y además permite a los mismo programas ejecutarse en terminales diferentes con distinto lenguaje máquina. Existen normalizaciones *(ANSI e ISO)* para garantizar la portabilidad de los programas.
- Una **sentencia en un lenguaje de alto nivel** da lugar, al ser traducida, a varias instrucciones en lenguaje máquina.
- Se usan **notaciones cercanas a las habituales** en el ámbito que se usan. Se utilizan en estos lenguajes sentencias muy parecidas al lenguaje matemático o al natural, habitualmente en inglés. Esto suele implicar:
	- Las instrucciones se expresan por medio de texto.
	- Se puede asignar un **nombre simbólico** a determinados componentes del programa *(variables)*. La asignación de memoria para variables y constantes la hace el traductor.
    - Dispone de **instrucciones potentes** de gran diversidad: *aritméticas*, *especiales*, *lógicas* y de *tratamiento de caracteres*.
    - Pueden incluirse **comentarios** que facilitan la legibilidad del programa.
## Construcción de traductores
Un traductor es un programa que recibe como entrada un programa **fuente**, *(un texto en un lenguaje de programación)*, y produce un **programa objeto**, *(un texto en lenguaje máquina equivalente)*. Este proceso de traducción puede ser efectuado por dos tipos distintos de programas traductores: los **compiladores** y los **intérpretes**.
### Compiladores
Un compilador traduce un programa fuente *(habitualmente contenido en un archivo)* a un programa objeto *(suele almacenarse como archivo en memoria masiva para su posterior ejecución)*. Tras ser traducido el programa su ejecución es independiente del compilador y estará controlada por el S.O.
La compilación es un proceso complejo y consume a veces un tiempo muy superior a la misma ejecución del programa, consta de dos etapas: el análisis de la fuente y la síntesis del objeto. Durante cualquiera de éstas etapas el compilador puede dar mensajes sobre errores que detecte en el programa fuente.
#### Análisis de fuente
El proceso de análisis de la fuente conlleva un análisis del léxico, la sintaxis y la semántica del programa fuente.
##### Análisis lexicográfico
Durante esta fase se divide el programa en sus **símbolos de texto** *(tokens)* que son secuencias de caracteres *(lexemas o palabras)* que tienen un significado concreto en el lenguaje. El **analizador lexicográfico** **aísla** los símbolos, **identifica** su tipo y **almacena** la información en **tablas de símbolos**. De este análisis resulta una representación en tablas del programa que contiene la misma información que el programa fuente pero de forma más compacta y de acuerdo con un **patrón**. Además el analizador identifica comentarios, espacios en blanco y tabulaciones así como informa de posibles errores léxicos *(que se dará cuando el carácter de entrada no tenga asociado ningún patrón de la lista de tokens)*. En la mayoría de lenguajes de programación, los tokens suelen ser:
- **Palabras reservadas**: `if`, `do`, `while`, `else`,...
- **Operadores**
- **Identificadores**
- **Constantes**
- **Signos de puntuación**
##### Análisis sintáctico
La sintaxis de un lenguaje especifica las reglas del lenguaje. Una construcción puede ser sintácticamente correcta y carecer de sentido. Existen varios sistemas para definir la sintaxis de los lenguajes de programación *(metalenguajes)*, cabe destacar la notación **BNF** *(Bacus-Naur Form)*. Las gramáticas ofrecen unos beneficios considerables:
- Proporcionan una especificación sintáctica precisa.
- Es posible construir de forma automática un analizador sintáctico eficiente.
- Revela ambigüedades sintácticas y puntos problemáticos en el diseño del lenguaje.
- Permite que el lenguaje evolucione o se agreguen nuevas construcciones.
El **analizador sintáctico** analiza las secuencias de tokens y comprueba que sean correctas, nos devuelves: si la secuencia es correcta o no y el orden en el que hay que aplicar las producciones de la gramática para obtener la secuencia de entrada, lo que se conoce como **árbol sintáctico**. Si no existe un árbol sintáctico para la secuencia de entrada, ésta es incorrecta sintácticamente.
###### Gramáticas libres de contexto
Una gramática libre de contexto consiste en un conjunto de **terminales**, **no terminales**, **símbolo inicial** y **producciones**.
1. Los **terminales** son los símbolos básicos a partir de los cuales se forman las cadenas. Los terminales son los primeros componentes de los tokens que produce el analizador léxico.
2. Los **no terminales** son variables sintácticas que denotan conjuntos de cadenas, imponen una estructura jerárquica sobre el lenguaje, clave en el análisis sintáctico y la traducción.
3. El **símbolo inicial** es un no terminal que denota un conjunto de cadenas que es el lenguaje generado por la gramática.
4. Las **producciones de una gramática** especifican la forma en la que se combinan terminales y no terminales.
###### Gramáticas ambiguas
Una gramática ambigua se refiere a una gramática que admite más de un árbol sintáctico para una misma secuencia de símbolos de entrada.
##### Análisis semántico
La semántica de un lenguaje es el **significado** dado a las distintas construcciones sintácticas. En los lenguajes de programación, el significado está ligado a la estructura sintáctica de las sentencias.
Durante la fase de análisis semántico se producen errores cuando se detectan construcciones sin un significado correcto (p.e. variable no declarada, tipos incompatibles en una asignación, llamada a un procedimiento incorrecto o con número de argumentos incorrectos, ...). En C es posible realizar asignaciones entre variables de distintos tipos, aunque algunos compiladores devuelven **warnings** de que algo puede realizarse mal posteriormente.
#### Generación de código
En esta fase se genera un archivo con un código en lenguaje objeto equivalente al texto fuente. Este archivo-objeto generado puede ser directamente ejecutable o necesitar otros pasos previos a la ejecución como el ensamblado, encadenado y carga. A menudo se utiliza un lenguaje intermedo para proporcionar independencia de las fases de análisis con respecto al lenguaje máquina y proporcionar portabilidad así como facilitar la optimización del código.
###### Código intermedio
En la generación de código intermedio se completan y consultan las tablas generadas anteriormente y se realiza la asignación de memoria a los datos definidos del programa. Ésta puede realizarse añadiendo procedimientos en determinados puntos del proceso de análisis, generando instrucciones en lenguaje objeto equivalentes a cada construcción en lenguaje fuente reconocida.
###### Optimización de código
En esta fase se mejora el código intermedio mediante comprobaciones locales a un grupo de instrucciones *(bloque básico)* o a nivel **global**. Pueden realizarse optimizaciones tanto al código intermedio como al final, aunque habitualmente se realizan en el código intermedio. Algunos compiladores permiten al usuario omitir o reducir las fases de optimización, acelerando el proceso de compilación.
### Intérpretes
Un **intérprete** hace que un programa fuente vaya **traduciéndose y ejecutándose** sentencia a sentencia. El análisis del programa solo se realiza en el contexto de la sentencia, lo cual dificulta la optimización y no se crea un programa objeto que almacenar en memoria masiva. El intérprete supervisa la ejecución durante todo momento.
#### ¿Es útil un intérprete?
Un intérprete es útil cuando:
- Se trabaja en un entorno interactivo y se pretende obtener los resultados de las instrucciones antes de continuar con el programa.
- El programa se ejecuta pocas veces y el tiempo de ejecución no es importante.
- Las instrucciones tienen una estructura simple y pueden analizarse fácilmente.
- Cada instrucción sera ejecutada una única vez.
Un intérprete deja de ser útil:
- Si las instrucciones del lenguaje son complejas.
- La velocidad es importante.
- Las instrucciones serán ejecutadas con frecuencia.
## Modelo de memoria de un proceso
Los elementos responsables de la gestión de memoria son: el lenguaje de programación, el compilador, el enlazador, el sistema operativo y la MMU *(Memory managemente unit)*. La gestión de memoria puede dividirse en distintos niveles:
- **Nivel de procesos**: Reparte la memoria entre los distintos procesos. Gestionado por el S.O. Operaciones:
    - Crear el mapa de memoria del proceso.
    - Eliminar el mapa de memoria del proceso.
    - Duplicar el mapa de memoria del proceso.
    - Cambiar de mapa de memoria de proceso.
- **Nivel de regiones**: Reparte el espacio asignado al proceso entre las regiones del mismo. Gestionado por el S.O. Operaciones:
    - Crear una región dentro del mapa de memoria del proceso.
    - Eliminar una región del mapa de memoria del proceso.
    - Duplicar una región del mapa de memoria del proceso en el mapa de otro.
    - Cambiar el tamaño de una región.
- **Nivel de zonas**: Mientras que la mayoría de las regiones tienen contenido homogéneo, algunas *(heap, pila)* mantienen en su interior zonas independientes, por tanto, en este nivel se reparte una región entre las diferentes zonas de ésta. Gestionado por el lenguaje de programación. Operaciones:
    - Reservar una zona.
    - Liberar una zona reservada.
    - Cambiar el tamaño de una zona reservada.
### Necesidades de memoria de un proceso
- Tener un **espacio lógico independiente**.
- **Espacio protegido** del resto de procesos.
- Posibilidad de **compartir memoria**.
- Soporte a **diferentes regiones**.
- Facilidades de **depuración**.
- Uso de un **mapa amplio de memoria**.
- Uso de **diferentes tipos de objetos de memoria**.
- **Persistencia de datos**.
- **Desarrollo modular**.
- **Carga dinámica** de módulos.
### Modelos de memoria de un proceso
#### Implementación de los diversos tipos de objetos de memoria
Existen, básicamente, tres tipos de objetos de memoria: datos estáticos, datos dinámicos asociados a la ejecución de una función y datos dinámicos controlados por el programa, almacenados en la región *heap*.
##### Datos estáticos
Estos datos existen durante toda la vida del programa, tienen asociada una posición fija en el mapa de memoria del proceso que se mantendrá asignada al mismo durante toda la ejecuición del programa. Existen distintos tipos:
- **Globales** a todo el programa, módulo o locales a una función, dependiendo del ámbito de visibilidad de la variable. Este aspecto es importante para el compilador y el montador, pero no es significativo en esta exposición, ya que no afecta directamente al objetivo de la misma.
- **Constantes o variables**. Las constantes no pueden ser modificadas. El compilador puede generar un error si se trata de alterar su valor. Es necesario asegurarse en tiempo de ejecución de que no se puede modificar, para ello habrá que asociar este tipo de dato a una región que no pueda modificarse.
- **Con o sin valor inicial** asignado. En caso de tener valor asignado, será necesario asegurarse de que éste esté almacenado en la memoria cuando el proceso intente acceder al mismo, por tanto éste valor habrá de estar almacenado en el ejecutable.
###### Position Independent Code
A menudo puede ser interesante utilizar un direccionamiento relativo a un registro en vez de uno absoluto. Aunque esto produzca una pequeña pérdida de eficiencia, este tipo de direccionamiento puede facilitar la generación de un **código independiente de la posición** *(PIC)*. Esta propiedad implica que el código pueda ejecutarse en **cualquier zona de memoria** sin requerir un proceso de reubicación. Para ello **todas las referencias a datos e instrucciones que incluya el código deben referirse a direcciones de memoria relativas**, basándose en el valor almacenado en un registro. Suele usarse un direccionamiento relativo al contador de programa para lograr este fin. Habitualmente, debido a la pérdida de eficiencia, el ejecutable de un programa no se genera con código PIC, dado que el hardware de gestión de memoria se encarga de la reubicación, sin embargo, se usa frecuentemente para **bibliotecas dinámicas**.
##### Datos dinámicos asociados a la ejecución de una función
Este tipo de objetos de memoria están asociados a la ejecución de una función y se corresponden con las variables locales y los parámetros de la función. Se crean al invocar la función y se destruyen cuando ésta termina. Carecen de espacio asignado en el mapa inicial del proceso o en el ejecutable. Suelen almacenarse dinámicamente en la pila del proceso, dentro del **registro de activación** donde se guarda además la información necesaria para retornar al punto de llamada cuando termina la ejecución. La dirección de éstos se determina en tiempo de ejecución, para acceder a ellos habremos de consultar el puntero de pila. Al usarse direccionamiento relativo estos datos cumplen la propiedad PIC, por lo que el compilador se encarga de su implementación.
Estas variables pueden también tener asignado un valor inicial, sin embargo, la asignación de éstas la hace el propio ensamblador, a diferencia de las estáticas.
###### Gestión de la pila
La pila está organizada en zonas independientes por lo que se trata de un nivel de gestión de zonas y, por tanto, la reserva y liberación de zonas se hacen de acuerdo con ello. Se trata sin embargo de algo trivial, puesto que tiene un comportamiento LIFO (Last In First Out) de forma que nunca quedan huecos entre zonas. Dentro de la pila está el **registro de activación** que almacena variables locales, parámetros y la dirección de retorno.
##### Datos dinámicos controlados por el programa
Se trata de datos dinámicos que el programa crea cuando ve oportuno y almacena en el *heap* donde se van almacenando todos los datos dinámicos usados por el programa y que se liberará cuando sea necesario o bien por el mismo programa o bien por un **recolector de basura**. La dirección de estos datos se determina en tiempo de ejecución por tanto la posición de memoria asignada a la variable solo contiene un puntero con la dirección de memoria donde está almacenado el dato, estos objetos cumplen la propiedad PIC, por lo que el compilador y las bibliotecas son las encargadas de su implementación, sin que intervengan otros componentes del sistema.
###### Gestión del *heap*
El *heap* es la región de memoria donde se almacenan todos los datos dinámicos requeridos por el proceso. Lo gestiona el lenguaje de programación son cierto soporte de S.O. puesto que si lo controlara el S.O. sería mucho menos eficiente puesto que habría que realizar muchas llamadas al sistema y sería además menos flexible puesto que cada lenguaje tiene su propio modelo de memoria dinámica. El *heap* tiene una serie de características:
- Es un espacio dinámico
- Hay varias soluciones, algunas usan una única región de memoria y otras diversas regiones de tamaño fijo para cada expansión de éste.
- Uno de los esquemas más populares, debido a su eficiencia es el de **múltiples listas con huecos de tamaño variable** descrito anteriormente.
- Es necesario tener en cuenta el patrón de uso de memoria dinámica de los procesos para optimizar el rendimiento.
- El *heap* en entornos multitarea o entornos multiprocesador puede ser problemático puesto que se debe acceder de forma secuencial y esto puede causar un cuello de botella.
## Ciclo de vida de un programa
A partir de un código fuente, un programa debe pasar por varias etapas antes de ejecutarse:
- Compilación
- Montaje o enlace
- Carga
- Ejecución
### Compilación
Un compilador procesa cada uno de los archivos de código fuente para generar el correspondiente archivo objeto. Realiza las siguientes acciones:
- Genera el código objeto y determina cuánto espacio ocupan los datos estáticos, distinguiendo los de carácter constante y los de carácter variable y los que tiene valor asignado de los que no. El compilador estructura toda la información en secciones, sus unidades de organización.
- Asigna direcciones a los símbolos estáticos y asigna direcciones consecutivas a los símbolos, las constantes, las variables inicializadas y las variables sin inicializar.
- Resuelve las referencias a los símbolos estáticos, lo que puede hacerse de forma absoluta o de forma relativa, aunque puede requerir reubicación.
- Las referencias a símbolos estáticos definidos en otros módulos se resolverán en la fase de montaje.
- Las referencias a símbolos dinámicos se resuelven usando direccionamiento relativo a pila para datos relacionados a la invocación de una función, o con direccionamiento indirecto para el heap. No necesitan reubicación al no aparecer en el archivo objeto.
Además el compilador genera:
- En la **tabla de símbolos** el compilador recopila qué símbolos globales están definidos en el módulo y a qué símbolos externos se hace referencia.
- La **información de depuración** permite al depurador saber a qué línea de código atañe una determinada instrucción o código máquina o a qué variable corresponde una determinada dirección de memoria en tiempo de ejecución.
### Enlazado
El enlazador *(linker)* debe agrupar los archivos objetos de la aplicación y las bibliotecas, y resolver las referencias entre ellos. En ocasiones, debe realizar reubicaciones dependiendo del esquema de gestión de memoria utilizado.
En primer lugar, se completa la etapa de resolución de símbolos, para ello se buscan todos los símbolos externos usados por cada módulo en las tablas de símbolos de los módulos. Posteriormente, se procede a agrupar en regiones los módulos similares a fin de mejorar la eficiencia puesto que éstas son gestionadas por el S.O.. A continuación, se realiza la **reubicación de módulos**, que resuelve el proceso de reubicación de las referencias. Con los direccionamientos relativos al PC se simplifica la reubicación, pero sigue siendo necesaria en algunos casos.
Dependiendo del entorno, será necesaria la reubicación de regiones o se hará conjuntamente con la de procesos, si fuera necesario, el montador realizaria la reubicación de regiones y dejaría la de procesos para la carga o ejecución del programa.
Se genera un fichero ejecutable en código máquina muy similar al programa objeto. Existen varios tipos de enlazado que definen una especie de ámbito:
- Enlazado externo, con visibilidad global.
- Enlazado interno, con visibilidad de fichero.
- Sin enlazado, con visibilidad de bloque.
#### Reglas de enlazado
1. Cualquier objeto/identificador que tenga ámbito global deberá tener enlazado interno si su declaración contiene el especificador `static`.
2. Si el mismo identificador aparece con enlazados externo e interno, dentro del mismo fichero, tendrá enlazado externo.
3. Si en la declaración de un objeto o función aparece el especificador de tipo de almacenamiento `extern`, el identificador tiene el mismo enlazado que cualquier declaración visible del identificador con ámbito global. Si no existiera tal declaración visible, el identificador tiene enlazado externo.
4. Si una función es declarada sin especificador de tipo de almacenamiento, su enlazado es el que correspondería si se hubiese utilizado `extern` (es decir, `extern` se supone por defecto en los prototipos de funciones).
5. Si un objeto (que no sea una función) de ámbito global a un fichero es declarado sin especificar un tipo de almacenamiento, dicho identificador tendrá enlazado externo (ámbito de todo el programa). Como excepción, los objetos declarados const que no hayan sido declarados explícitamente `extern` tienen enlazado interno.
6. Los identificadores que respondan a alguna de las condiciones que siguen tienen un atributo sin enlazado:
    - Cualquier identificador distinto de un objeto o una función (por ejemplo, un identificador `typedef`).
    - Parámetros de funciones.
    - Identificadores para objetos de ámbito de bloque, entre corchetes {}, que sean declarados sin el especificador de clase `extern`.
### Carga y ejecución
La reubicación del proceso se completa en la carga o ejecución. Tres tipos, según el esquema de gestión de memoria:
- Si se usa segmentación, el cargador copiará el programa en memoria sin modificarlo y será la **MMU** la encargada de la reubicación.
- En paginación, el hardware es capaz de reubicar los procesos en ejecución, por lo que el cargador copiará el programa en memoria sin modificarlo y se encargará el hardware de la reubicación.
- Si no usamos hardware de reubicación, ésta se realiza durante la carga en memoria, por el cargador, se tratará entonces de una reubicación software.
### Diferencias entre archivo objeto y archivo ejecutable
- Los archivos objeto (resultado de la compilación) y ejecutable (resultado del enlazado) son muy similares en cuanto a contenidos.
- Su principales diferencias son:
    - En el ejecutable la cabecera del archivo contiene el punto de inicio del mismo, es decir, la primera instrucción que se cargará en el PC.
    - En cuanto a las regiones, sólo hay información de reubicación si ésta se ha de realizar en la carga.
#### Formato de archivo objeto y ejecutables
Archivo | Descripción
    --- | ---
a.out   | Es el formato original de los sistemas Unix. Consta de tres secciones: text, data y bss que se corresponden con el código, datos inicializados y sin inicializar. No tiene información para depuración.
COFF    | El Common Object File Format posee múltiples secciones cada una con s u cabecera pero están limitadas en número. Aunque permite información de depuración, esta es limitada. Es el formato utilizado por Windows.
ELF     | Executable and Linking Format es similar al COFF pero elimina algunas de sus restricciones. Se utilizaen los sistemas Unix modernos, incluido GNU/Linux y Solaris.
#### Secciones de un archivo
- `.text` – **Instrucciones**. Compartida por todos los procesos que ejecutan el mismo binario. Permisos: r y w. Es de las regiones más afectada por la optimización realizada por parte del compilador.
- `.bss` – **Block Started by Symbol**: datos no inicializados y variables estáticas. El archivo objeto almacena su tamaño pero no los bytes necesarios para su contenido.
- `.data` – **Variables globales y estáticas inicializadas**. Permisos: r y w.
- `.rdata` – **Constantes** o **cadenas literales**.
- `.reloc` – Información de **reubicación** para la **carga**.
- **Tabla de símbolos** – Información necesaria (nombre y dirección) para localizar y **reubicar definiciones** y referencias simbólicas del programa. Cada entrada representa un **símbolo**.
- **Registros de reubicación** – información utilizada por el **enlazador** para ajustar los contenidos de las **secciones** a reubicar.
## Bibliotecas
Una biblioteca es una colección de objetos *(habitualmente relacionados entre si)*.
Favorecen la modularidad y reusabilidad del código.
Se pueden clasificar según se enlacen en:
- **Bibliotecas estáticas** que se enlazan con el programa en la compilación (`.a`).
- **Bibliotecas dinámicas** que se enlazan durante la ejecución (`.so`).
### Bibliotecas estáticas
Una biblioteca estática consiste en un conjunto de archivos que se copian en un único archivo. Cualquier usuario puede crear una biblioteca siguiendo ciertos pasos:
- Construcción del código fuente.
- Generación del objeto.
`gcc -c calc_mean.c -o calc_mean.o`
- Archivación del objeto (creación de la biblioteca).
`ar rcs libmean.a calc_mean.o`
- Utilización de la misma.
`gcc -static prueba.c -L. -lmean -o statically_linked`
Sin embargo, las bibliotecas estáticas tienen algunos inconvenientes:
- El código de la biblioteca esta en todos los ejecutables que la usan, lo que desperdicia disco y memoria.
- Si actualizamos las bibliotecas, debemos recompilar el programa para que se beneficie de la nueva versión.
### Bibliotecas dinámicas
Para resolver estas deficiencias se usan las bibliotecas dinámicas, éstas se integran en ejecución, para ello se ha realizado la reubicación de módulos. Su diferencia con un ejecutable: tienen tabla de símbolos, información de reubicación y no tiene punto de entrada. El mecanismo de bibliotecas dinámicas ha de ser transparente tanto para el programador como para el compilador *(que no sabe si las referencias pendientes están definidas en otro módulo, en una biblioteca estática o una dinámica)*, puesto que de lo contrario podrían generarse problemas al usar éstas, además es necesario que la sobrecarga asociada a las bibliotecas dinámicas se mantenga en términos razonables.
Con este nuevo mecanismo, las bibliotecas ya no se montan en tiempo de montaje sino en tiempo de ejecución del programa. Una vez creada una biblioteca dinámica, puede ser usada por cualquier programa. Las bibliotecas dinámicas se anotan en una parte del ejecutable que reune las distintas bibliotecas dinámicas utilizadas por el programa, para invocarlas en tiempo de ejecución. Las bibliotecas dinámicas pueden ser:
- Bibliotecas compartidas de carga dinámica. La reubicación se realiza en tiempo de enlazado.
- Bibliotecas compartidas enlazadas dinámicamente. El enlazado se realiza en ejecución.
## Automatización en la construcción de software
Automatizar la construcción es la técnica utilizada durante el ciclo de vida de desarrollo de software donde la transformación del código fuente en el ejecutable se realiza mediante un guión (script).
La automatización mejora la calidad del resultado final y permite el control de versiones.
Varias formas:
- Herramienta **make**.
- **IDE** (Integrated Development Environment), que embebe los guiones y el proceso de compilación y enlazado.

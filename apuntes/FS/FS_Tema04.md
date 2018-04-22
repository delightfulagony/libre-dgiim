# Tema 04. Sistemas de archivos. Introducción a las bases de datos
## Concepto de archivo
Un **archivo**/fichero es un conjunto de información sobre un mismo tema, tratada como una unidad de almacenamiento y organizada de forma estructurada para la búsqueda de un dato individual. Está compuesto de **registros** homogéneos que contienen información sobre el tema. El SO permite al usuario aludir a él por medio de un nombre, independiente de cómo se almacene en memoria.
### Registros
Un **registro** es una estructura dentro del archivo que contiene la información correspondiente a un elemento individual. Un registro se puede dividir en **campos**, que representan información unitaria o independiente.
### Vida del archivo
La vida de todo archivo comienza cuando se crea y acaba cuando se borra. Durante la vida de un archivo se suelen realizar sobre él determinadas operaciones:
- Creación/Copia/Borrado/Renombramiento del archivo.
- Establecer/Obtener atributos de un archivo.
- Abrir/Cerrar un archivo.
- Leer/Escribir un registro de un determinado archivo.
El sistema operativo permite que el usuario pueda aludir al archivo mediante un nombre, independientemente de la forma en que se almacene en el dispositivo. Además del nombre, el archivo tiene asociados otros atributos como el tamaño, la fecha de creación, de modificación, propietario, permisos, etc.
### Gestión de archivos
El sistema operativo transporta una cantidad fija de información que depende del hardware de éste y se denomina **bloque físico**. Pueden haber varios registros en un mismo bloque y un único registro puede ocupar varios bloques, la longitud de bloque es un factor imporante en el diseño de archivos, ya que define el número de registros que entran en un bloque.
El sistema operativo además transforma la dirección lógica de los programas de usario en la dirección física. Siendo la lógica la dirección relativa que ocupa el registro en el archivo y la absoluta su dirección real en memoria.
Un archivo es una estructura de datos externa al programa que lo usa; en las operaciones de lectura/escritura se transfiere la información a/desde un buffer en memoria principal asociado a las operaciones de entrada/salida sobre el archivo.
Los archivos se guardan en dispositivos de memoria masiva, estando limitados en tamaño tan solo por el de los dispositivos que los albergan. Sin embargo, los dispositivos de memoria auxiliar
### Clasificación de archivos según el tipo de registros

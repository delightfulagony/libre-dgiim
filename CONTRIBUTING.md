# CONTRIBUTING
Hay varias formas de contribuir a este repositorio
- Creando y/o actualizando apuntes
- Corrigiendo errores y erratas
- Subiendo ejercicios resueltos

## Organización de directorios
El repositorio se divide en dos carpetas principales con cada asignatura
en su interior.
```
└── libre-dgiim
    ├── apuntes
    │	 └──(...)
    │    └──Identificadores de asignaturas
    │	 └──(...)
    └── ejercicios
    	 └──(...)
	 └──Identificadores de asignaturas
    	 └──(...)
```

## Nombramiento de archivos
Los archivos en la carpeta `apuntes` seguirán el siguiente esquema:
```
[SIGLAS]_Tema[00]
```
Los directorios en la carpeta `ejercicios` seguirán el siguiente esquema,
siendo los parámetros `[]` obligatorios y los parámetros `<>` opcionales:
```
[SIGLAS]_<EXAM>_Tema[00]_<G00>_<SOL00>
```
Donde `EXAM` se incluirá de ser un ejercicio de examen, `G00` de haber
ejercicios distintos según el grupo y `SOL00` será añadido de existir
más de una solución posible.

Los ejercicios resueltos deben estar siempre dentro de una carpeta que
siga dicha estructura.

## Guía de estilo
Los apuntes de matemáticas se subirán en formato `.tex` y los de
informática en formato `.md` con el fin de que sea lo más sencillo
posible compilarlos usando `pandoc` o `pdflatex`.

Los archivos habrán de ser siempre texto plano accesible desde cualquier
editor de texto, es decir, si se sube un ejercicio en Máxima, se subirá
en formato `.wxm` y no en `.wxmx`.

## Branches
El repositorio constará de 2 branches:
- `master` contendrá los apuntes finalizados y de acuerdo con el estilo
establecido.
- `wip` contendrá todos los proyectos en los que se esté trabajando pero
no estén listos para commitearlos a `master`.
Además, para commitear a master será necesaria la aprobación de al menos
2 colaboradores del repositorio, a fin de evitar errores y garantizar
concordancia con el resto de la rama.

## Commits
Cada commit irá precedido por las siglas de la asignatura en la cual se
esté editando (`SIGLA:Mensaje del commit`), para distintas asignaturas
se harán commits separados para facilitar el control de versiones.

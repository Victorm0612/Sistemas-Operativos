# REPORTE SOBRE LO REALIZADO - 06_19_2019

## Víctor Manuel Vargas Rojas  - 1842274
## Juan Camilo Gonzalez Berrio - 1735277 
## Juan Esteban Camargo Chacón - 1924984

Los ejercicios realizados fueron los siguientes:

###Virtualización

* [mem.c](mem.c)

Para la realización de este punto, fue necesesario tener en cuenta el archivo de cabecera:

* [common.h](common.h)

Puesto que permitia el correcto funcionamiento del archivo mem.c. Lo siguiente es que
para mostrar la dirección a la que apunta p, fue necesario usar la función getpid() que
obtiene el identificador del proceso que se está ejecutando.
 
Para ver el funcionamiento de este programa, ejecutar la siguiente instrucción:

```
gcc mem.c -o mem && ./mem
```
###Concurrencia

Para cumplir con lo requerido se debía pensar

* [threads.c](threads.c)

```
gcc -pthread threads.c -o threads && ./threads 1000000
```

###Persistencia

* [io.c](io.c)

```
gcc io.c -o io && ./io
```

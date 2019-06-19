# REPORTE SOBRE LO REALIZADO - 06_19_2019

## Víctor Manuel Vargas Rojas  - 1842274
## Juan Camilo Gonzalez Berrio - 1735277 
## Juan Esteban Camargo Chacón - 1924984

Los ejercicios realizados fueron los siguientes:

### Virtualización

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
### Concurrencia

Para cumplir con lo requerido se debía pensar en cómo resolver el problema que se presentaba
cuando dos hilos trataban de acceder a la variable counter de manera concurrente. Para esto,
fue necesario pensar en la creación de una puerta que permitiera/denegara el paso de un hilo
para iterar/afectar la variable counter. Primero, fue necesario agregar los diferentes archivos
de cabecera que permitiera el correcto funcionamiento de la puerta que deseabamos crear. Estos
archivos de cabecera son:

* [common.h](common.h)
* [common_threads.h](common_threads.h)
* [mycommon.h](mycommon.h)

Luego de agregar los respectivos archivos de cabecera, fue necesario pensar cuáles serían los puntos
claves para abrir/cerrar/crear/destruir la puerta. Para crear la puerta, esta debía crearse al principio
del main. Luego, cuando el primer hilo está preparado para iterar y modificar el valor de la variable
counter, la puerta se cierra para que ningún otro hilo afecte el proceso. Cuando el primer hilo que ingresó
ha terminado, la puerta se abrirá para permitir el paso de los hilos que se encuentran atrás y así, que
estos empiecen su respectiva iteración. Finalmente, cuando todo ha terminado, la puerta se eliminará y entonces
el programa finalizará. 

El archivo dónde se encuentra el código de hilos (modificado) es:

* [threads.c](threads.c)

```
gcc -pthread threads.c -o threads && ./threads 1000000
```

### Persistencia

Para resolver este ejercicio era necesario pensar primero en las variables globales que necesitabamos para una futura iteración. 
Estas variables son: Lp (que contiene la última posición a la que deseo llegar) y posActual (que contiene la posición en la que
me estaré ubicando y que inicializará en uno para que al momento de retroceder dos posiciones continue con la penúltima letra del archivo).
Luego de definir las variables globales que vamos a usar; debemos plantear cómo validar que el archivo que se pasa por entrada
exista. Para eso, fue necesario realizar un sencillo if que comprobaba que el parámetro encontrado en la posición
uno(1),al ser abierto, era diferente de NULL. Si es así, quiere decir que el archivo existe y podemos trabajar. Si no,
entonces el programa mostrará un mensaje que solicita revisar lo digitado. Luego de esta comprobación, en caso de que
pueda trabajar el documento de entrada, abrimos el documento que contiene las palabras. Luego, gracias a la función
fseek, nos ubicaremos al final del documento justo en la última letra y seguido, asignamos a la variable Lp la variable númerica a la que deseamos llegar.




El archivo dónde se encuentra el código de io (palabras al revés) es:

* [io.c](io.c)

```
gcc io.c -o io && ./io
```

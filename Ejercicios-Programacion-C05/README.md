# REGISTRO DE LOS EJERCICIOS REALIZADOS DEL CAPÍTULO 5

### Ejercicio 01:

Lo que se puede notar es que ambos procesos modifican su propia copia de la variable x.

* [Ejercicio_01](fork-basico.c)

```
gcc fork-basico_01.c -o fork-basico_01 && ./fork-basico_01
```

### Ejercicio 02:

El proceso niño y el padre pueden acceder al archivo y editarlo. El problema está en que lo escrito por un proceso, modifican lo escrito por el otro.

* [Ejercicio_02](fork-file_02.c)

```
gcc fork-file_02.c -o fork-file_02 && ./fork-file_02 prueba
```





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

### Ejercicio 03:

Sí es posible lograr que el niño diga `hello` y luego el padre diga `goodbye`. Esto se logra agregando al proceso del padre un sleep de un (1) segundo antes 
de pasar por pantalla la palabra. Lo que hace la función `sleep` es realizar un retardo de n segundos.

* [Ejercicio_03](fork_03.c)

```
gcc fork_03.c -o fork_03 && ./fork_03
```

### Ejercicio 04:




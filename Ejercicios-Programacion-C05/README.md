# REGISTRO DE LOS EJERCICIOS REALIZADOS DEL CAPÍTULO 5

### Ejercicio 01:

Lo que se puede notar es que ambos procesos modifican su propia copia de la variable x.

* [Ejercicio_01](punto1.c)

```
gcc punto1.c -o punto1 && ./punto1
```

### Ejercicio 02:

El proceso niño y el padre pueden acceder al archivo y editarlo. El problema está en que lo escrito por un proceso, modifican lo escrito por el otro.

* [Ejercicio_02](punto2.c)

```
gcc punto2.c -o punto2 && ./punto2 prueba
```

### Ejercicio 03:

Sí es posible lograr que el niño diga `hello` y luego el padre diga `goodbye`. Esto se logra agregando al proceso del padre un `sleep` de un (1) segundo antes
de pasar por pantalla la palabra. Lo que hace la función `sleep` es realizar un retardo de n segundos.

* [Ejercicio_03](punto3.c)

```
gcc punto3.c -o punto3 && ./punto3
```

### Ejercicio 04:

La razón por la cuál existan tantas variantes es debido a los argumentos que se pasan por entrada, esto, con el propósito de mejorar la manera de realizar el reemplazo de procesos.

* [Ejercicio_04](punto4.c)

```
gcc punto4.c -o punto4 && ./punto4
```

### Ejercicio 05:

Originalmente, el wait retorna el PID del proceso child. Al poner un wait en el proceso child, el pid que retorna es -1 y esto es debido a que no no hay ningún proceso secundario.

* [Ejercicio_05](punto5.c)

```
gcc punto5.c -o punto5 && ./punto5
```

### Ejercicio 06:

La función waitpid puede ser útil cuando en vez de trabajar con procesos child de manera arbitraria, vamos a trabajar o queremos trabajar con el proceso child en específico.

* [Ejercicio_06](punto6.c)

```
gcc punto6.c -o punto6 && ./punto6
```

### Ejercicio 07:

Al tratar de imprimir algo luego de cerrar el flujo, tal cosa no sucede. Sin importar qué sea, lo que se desea imprimir, no lo hace.

* [Ejercicio_07](punto7.c)

```
gcc punto7.c -o punto7 && ./punto7
```




# Lenguaje C - 101

En esta clase se hizo una revisión muy rápida de un programa sencillo en C que imprime el mensaje "hola mundo". Después se mostró la forma como se genera una librería de enlace estático y cómo la funcionalidad implementada en esta es invocada desde un programa C.

Se desarrollaron cinco programas:

* [basico.c](basico.c)
* [libfun.a](libfun.a)
* [libfun.c](libfun.c)
* [libfun.h](libfun.c)
* [libfun.o](libfun.o)

Para completar el programa se llevaron a cabo los siguientes pasos:

* Generar la librería
```
gcc -c libfun.c -o libfun.o
ar rcs libfun.a libfun.o
```

* En el paso anterior se generó el archivo `libfun.a`. Ahora enlazaremos el programa `basico.c` con la librería `libfun.a`.

```
gcc basico.c -L. -lfun -o basico
```

* Finalmente, el programa se ejecuta:
```
./basico
```

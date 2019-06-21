# 2019_06_21

El día de hoy se revisaron conceptos básicos respecto al estado en el que se puede encontrar un proceso en el Sistema Operativo: *Waiting*, *Ready*, *Running* y *Done*.

Se revisó el comando `process-run.py` que es un aplicativo provisto por el autor del texto guía del libro.

* `process-run.py` aplicativo que simula la ejecución de procesos y sus operaciones o en CPU o de I/O

* `README-process-run` documento que describe la utilización del comando `process-run.py`.

---

Ejecución de ejemplo:

```
./process-run.py -l 3:0,3:100 -L 3 -c -p
```

Esta ejecución lo que permite es simular la ejecución de dos procesos. Un primer proceso intensivo en I/O (`3:0`) y un segundo proceso intensivo en CPU (`3:100`).

Los argumentos `-c -p` dan información adicional relativa al comportamiento de los procesos en el simulador, e.g. porcentaje de uso de la CPU y de operaciones de I/O.




















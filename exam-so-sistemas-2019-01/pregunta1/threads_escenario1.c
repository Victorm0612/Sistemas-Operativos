#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <time.h> //para tomar los tiempos


volatile int counter = 0;
/*Creación de variable global door de tipo puerta*/
puerta door;
int loops;
//VARIABLES GLOBALES PARA TOMA DE TIEMPOS
clock_t t_ini, t_fin;
double secs;

void *worker(void *arg) {
    int i;
/*Cuando uno de los hilos vaya a iterar, cerrará la puerta primero
para evitar conflicto con otro hilo*/
    cerrar_puerta(door);
    for (i = 0; i < loops; i++) {
	counter++;
    }
/*El hilo al terminar su trabajo, le permitirá a otros hilos hacer el suyo
abriendo la puerta*/
    abrir_puerta(door);
    return NULL;
}

int main(int argc, char *argv[]) {
   t_ini=clock();//Inicio conteo
    crear_puerta(door);
    if (argc != 2) { 
         fprintf(stderr, "usage: threads <loops>\n"); 
	 exit(1); 
    } 
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(door);
    t_fin = clock(); //finalizo conteo
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);  
    return 0;
}

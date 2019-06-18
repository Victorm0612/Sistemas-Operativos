#ifndef __MYCOMMON__
#define __MYCOMMON__
 
#include "pthread.h"
#include "common.h"
#define puerta pthread_mutex_t // nuevo tipo de dato
#define crear_puerta(m) Pthread_mutex_init(&m,NULL) // funcion para crear puerta
#define cerrar_puerta(m) Pthread_mutex_lock(&m) // funcion para cerrar la puerta
#define abrir_puerta(m) Pthread_mutex_unlock(&m) //funcion para abrir la puerta
#define destruir_puerta(m) pthread_mutex_destroy(&m) // funcion para destruir puerta

#endif


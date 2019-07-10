/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto5.c
 * Fecha de creacion: 26-Junio-2019
 * Fecha ultima modificacion: 26-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/


#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


//Prototipo de la función
void myfork(pid_t value, pid_t cpid);

//Función principal
int main()
{
	
	pid_t value, cpid;
	


	myfork(value, cpid);//Invocación  de la función

	return 0;
} 

//Definición de la función
void myfork(pid_t value, pid_t cpid)
{
	
	value = fork(); //Crear proceso hijo
	
	if (value < 0) 
	{
		//Error
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar
	}
	else if(value == 0) 
	{
	
		//Proceso hijo
		cpid = wait(NULL);
		printf("%d: Soy el proceso hijo, el pid de mi padre es %d\n", (int)getpid(), (int)cpid);
		
	}else
	{
		//Proceso padre
		
		cpid = wait(NULL);
		printf("%d: Soy el proceso padre, el pid de mi hijo es %d\n", (int)getpid(), (int)cpid);
		
	}
			
}

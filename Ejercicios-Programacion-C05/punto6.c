/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto6.c
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
void myfork(pid_t value, pid_t cpid, int status);

//Función principal
int main()
{
	
	pid_t value, cpid;
	int status;
	
	myfork(value ,cpid, status);//Invocación  de la función

	return 0;
} 

//Definición de la función
void myfork(pid_t value, pid_t cpid, int status)
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
		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
	}else
	{
		//Proceso padre
		//value para el proceso padre contiene el pid del proceso hijo, el parametro 0 especifica que waitpid() sea bloqueante
		cpid = waitpid (value, &status, 0);//Permite especificar el proceso hijo por el que se desea esperar
		printf("%d: Soy el proceso padre, el pid de mi hijo es %d\n", (int)getpid(), (int)cpid);
		
	}
			
}

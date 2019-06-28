/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto3.c
 * Fecha de creacion: 25-Junio-2019
 * Fecha ultima modificacion: 25-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/

#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include <string.h>

//Prototipo de la función
void myfork(pid_t value);

//Función principal
int main()
{
	
	pid_t value;

	myfork(value);//Invocación  de la función
	
	return 0;
} 

//Definición de la función
void myfork(pid_t value)
{
	
	value = fork(); //Crear proceso hijo

	if (value < 0) 
	{
		//Error
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar proceso
	}
	else if(value == 0) 
	{
		//Proceso hijo
		printf("%d: Hello\n", (int)getpid());
					
		
	}else
	{
		//Proceso padre
		//wait(NULL);
		sleep(1);//Invocar llamada al sistema sleep()
		printf("%d:Goodbye\n", (int)getpid());
		
	}

}	

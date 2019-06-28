/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto8.c
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
#include <string.h>
#define MSGSIZE 30 

//Prototipos de las funciones
void myfork(int *fds);
void mywrite (int *fds);
void myread (int *fds);

//Función principal
int main()
{
	
	int fds[2]; //fds: fds[0] file descriptor lectura - fds[1] file descriptor escritura
	
	if (pipe(fds) < 0)
	{
		//Error
		perror("Error: En la apertura del pipe!!");
		exit(1);//Terminar

	}else
	{
		myfork(fds);//Invocación  de la función
	}

	return 0;
} 

//Definición de la función
void myfork(int *fds)
{
	
	pid_t child_pid, pid_child1, pid_child2;
	
	pid_child1 = fork(); //Crear primer proceso hijo
	
	if (pid_child1 < 0) 
	{
		//Error
		perror("Error: La creación del proceso hijo no fue exitosa!!");
		exit(1);//Terminar
	}
	else if(pid_child1 == 0) 
	{
	
		//Primer proceso hijo
		printf("%d: Soy el primer proceso hijo\n", (int)getpid());
		mywrite(fds);//Escribir en el pipe

	}else
	{
		child_pid = wait(NULL);//Espera por la finalización del primer hijo
		printf("%d: Soy el proceso padre, el pid de mi primer hijo es %d\n", (int)getpid(), (int)child_pid);
			
		pid_child2 = fork(); //Crear segundo proceso hijo

		if (pid_child2 < 0) 
		{
			//Error
			perror("Error: La creación del proceso hijo no fue exitosa!!");
			exit(1);//Terminar
		}
		else if(pid_child2 == 0) 
		{
	
			//Segundo proceso hijo
			printf("%d: Soy el segundo proceso hijo\n", (int)getpid());
			myread(fds);//Leer el contenido del pipe

		}else
		{
			child_pid = wait(NULL);//Espera por la finalización del segundo hijo
			printf("%d: Soy el proceso padre, el pid de mi segundo hijo es %d\n", (int)getpid(), (int)child_pid);
		
		}
		
	}
	
			
}

//Definición de la función
void mywrite (int *fds)
{
	char message[MSGSIZE] = "Hola, Buenos dias";

	//Escribir en el pipe
	if (write(fds[1],message,MSGSIZE) < 0) 
	{ 
		perror("w1"); 
		exit(1);
	}else
	{
		close(fds[1]);
		printf("%d: Escribe en el pipe --> %s\n", (int)getpid(), message);
	}
}

//Definición de la función
void myread (int *fds)
{
	char message[MSGSIZE];

	if (read(fds[0],message, MSGSIZE) < 0) 
	{ 	
		perror("r1"); 
		exit(1); 
	}else
	{
		close(fds[0]);
		printf("%d: Lee del pipe --> %s\n", (int)getpid(), message);
	}
}


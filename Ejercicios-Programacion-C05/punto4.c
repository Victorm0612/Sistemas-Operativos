/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto4.c
 * Fecha de creacion: 25-Junio-2019
 * Fecha ultima modificacion: 25-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/


#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


//Prototipo de la función
void myfork(pid_t value, char **args);

//Función principal
int main()
{
	
	pid_t value;
	char *args[] ={"/bin/ls",NULL};


	myfork(value, args);//Invocación  de la función

	return 0;
} 

//Definición de la función
void myfork(pid_t value, char **args)
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
		int i;
		char *envp[] = { NULL };

		//Proceso hijo
		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf(" **Menu**\n1. execvp( )\n2. execlp( )\n3. execve( )\n");
		printf("Digite una opción del Menu:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: execvp(args[0], args);
			break;
			case 2:execlp(args[0],"ls",NULL);
			break;
			case 3: execve(args[0],args,envp);
			default:
				printf("Opción incorrecta");
				exit(1);//Terminar proceso
			break;
		}
		
	}else
	{
		//Proceso padre
		
		wait(NULL);
		printf("%d: Soy el proceso padre\n", (int)getpid());
		
	}
			
}	

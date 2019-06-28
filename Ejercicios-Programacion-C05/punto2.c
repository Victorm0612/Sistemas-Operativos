/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: punto2.c
 * Fecha de creacion: 25-Junio-2019
 * Fecha ultima modificacion: 25-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/


#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//Prototipo de la función
void myfork(int fd, pid_t value, int sz);

//Función principal
int main()
{
	
	int fd, sz;
	pid_t value;

	fd = open ("archivo.txt",O_RDONLY | O_CREAT); //Abrir file descriptor asociado al archivo para solo lectura y si no existe crearlo
	
	if (fd < 0)
	{
		perror("Error al abrir el archivo!!");
		exit(1);//Terminar proceso
	}else
	{
		myfork(fd, value, sz);//Invocación  de la función
	}

	if(close(fd) < 0) //Cerrar file descriptor asociado al archivo
	{
		perror("Error: El archivo no se pudo cerrar!!");
		exit(1);//Terminar proceso
	}
	return 0;
} 

//Definición de la función
void myfork(int fd, pid_t value, int sz)
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
		printf("%d: Soy el proceso hijo\n", (int)getpid());
		
		printf("%d: El file descriptor es %d\n",(int)getpid(), fd);		
		
		sz = write(fd, "Hola, soy el proceso hijo\n", strlen("Hola, soy el proceso hijo\n"));		

		
	}else
	{
		//Proceso padre
		printf("%d: Soy el proceso padre\n", (int)getpid());

		printf("%d: El file descriptor es %d\n",(int)getpid(), fd);

		sz = write(fd, "Hola, soy el proceso padre\n", strlen("Hola, soy el proceso padre\n"));		
		
	}
			
	if(sz < 0)
	{
		//Error
		perror("Error al escribir el archivo!!");
		exit(1);//Terminar proceso
	}

	printf("%d: Escritura exitosa!!!\n", (int)getpid());

}	

/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: shell.c
 * Fecha de creacion: 29-Junio-2019
 * Fecha ultima modificacion: 29-Junio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.0
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void gramatica(char* comando)
{
 //Numero de cadenas x Tamaño max. de cadena
 char comandos[20][10] = {"ls", "cd","clr","dir","environ","echo", "help","pause","quit"};

}

int main(char* command)
{
  printf("prompt> ");
  scanf("%s",command);  
  return 0;
}

void ejecucion_comando(char** comando)
{
  pid_t pid = fork();
  if(pid < 0)
   {
    fprintf(stderr, "fork fallido\n");
    exit(1);
   }
   //Hijo
  else if(pid == 0)
   {
    if (execvp(comando[0], comando) < 0)
    
   }
}

void Help()
{
  printf("\n--- BIENVENIDO AL SHELL ---"
         "\n La lista de comandos disponibles es: "
         "\n * cd <Directorio>"
         "\n * clr"
         "\n * dir <Directorio>"
         "\n * environ"
         "\n * echo <comentario>"
         "\n * help"
         "\n * pause"
         "\n * quit"
         "\n * <ruta>/myshell");
}


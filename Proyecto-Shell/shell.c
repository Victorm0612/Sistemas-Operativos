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
#include <readline/readline.h> 
#include <readline/history.h> 
#include <string.h>

int Numero_caracteres = 500;
int Numero_comandos   = 100;

int entrada(char* command)
{ 
   command = readline("\nprompt> "); 
//strlen toma el argumento y devuelve la longitud de este (hay que ver si me pasan algo o no) 
    if (strlen(command) != 0) {
      //Con add_history puedo acceder a un comando ya utilizado  
        add_history(command); 
        return 0; 
    } else { 
        return 1; 
    } 
} 

void ejecucion_comando(char** comandos)
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
    if (execvp(comandos[0], comandos) < 0)
    {
     printf("\nNo es posible ejecutar el comando.");
    }
    exit(0);
    }
  else
    {
     wait(NULL);
    }
   }
}

int lista_comandos(char** gramatica) 
{ 
    int max = 9, posicion = 0; 
    char* ListaComandos[max]; 
  
    ListaComandos[0] = "cd"; 
    ListaComandos[1] = "clr"; 
    ListaComandos[2] = "dir"; 
    ListaComandos[3] = "environ";
    ListaComandos[4] = "echo";
    ListaComandos[5] = "help";
    ListaComandos[6] = "pause";
    ListaComandos[7] = "quit";
      
    for (int i = 0; i < max; i++) { 
        if (strcmp(gramatica[0], ListaComandos[i]) == 0) { 
            posicion = i + 1; 
            break; 
        } 
    } 
  
    switch (posicion) { 
    case 1: 
        return 1; 
    case 2: 
        clean(); 
        return 1; 
    case 3:
        execlp(ListaComandos[posicion-1],Listacomandos); 
        return 1; 
    case 4: 
        return 1; 
    case 5:
        return 1;
    case 6:
        Help();
        return 1;
    case 7:
        return 1;
    case 8:
        exit(0);
    default: 
        break; 
    } 
    return 0; 
} 

//Mostrando la ayuda
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
return 0;
}

int main()
{
  
}

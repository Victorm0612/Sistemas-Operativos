/*
 * Asignatura: SISTEMAS OPERATIVOS
 * Archivo: shell.c
 * Fecha de creacion: 25-Junio-2019
 * Fecha ultima modificación: 10-Julio-2019
 * Modificación: Juan Gonzales - Victor Vargas - Aida Mina  
 * Version: 1.9
 * ESCUELA DE SISTEMAS Y COMPUTACION
*/

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<dirent.h>
#include<sys/wait.h> 
#include<readline/readline.h> 

  
#define MAXCOM 1000 // máximo número de letras que se pueden soportar 
#define MAXLIST 100 // máximo número de comandos que se pueden soportar

char cwd[1024]; // Aquí guardaré la dirección donde estaré ubicandome.
char shell[1024]; // Aquí guardaré la dirección donde se ejecutó el shell.


// Función que recibe datos de entrada 
int DatosEntrada(char* str) 
{ 
    char* buf;   
    buf = readline("\nprompt> "); 
    if (strlen(buf) != 0) {
       strcpy(str, buf); 
        return 0; 
    } else { 
        return 1; 
    } 
} 
 
 void obtenerShell()
 {
  getcwd(shell,sizeof(shell));
 } 
// Función que imprime el directorio actual. 
void printDir() 
{    
    getcwd(cwd, sizeof(cwd));
    printf("$PWD = %s:   $shell=%s\n",cwd,shell); 
   return;
} 

// Función para ejecución de argumentos 
void execArgs(char** parsed) 
{  
  pid_t pid = fork();    
  if (pid == -1) 
    { 
      printf("\nfork niño fallido.."); 
      return; 
    } 
   else if (pid == 0)
    {
     execvp(parsed[0],parsed);
     exit(0);
    }
   else
    {
       wait(NULL);  
       return; 
    } 
}
// Menú de ayuda
void Ayuda() 
{ 
   printf("\n--- BIENVENIDO A SHELL ---"
                          "\n La lista de comandos internos disponibles es:"
                          "\n * cd <directorio>: Cambiar el directorio"
                          "\n * clr: Limpiar la pantalla"
                          "\n * dir: Listar el contenido del directorio"
                          "\n * environ: Listar todas las cadenas de entorno"
                          "\n * echo <comentario>: Desplegar el comentario en pantalla"
                          "\n * help: Desplegar el manual de usuario"
                          "\n * pause: Deterner la operación del shell hasta que se presiona enter"
                          "\n * quit: Salir de SHELL"); 
}
//Función que pausa el proceso
void parar()
{       
        char op;
        do{
                printf("Pausado..."
                        "\nPresionar enter para continuar...");
                op= getchar();
        }
       while(op != '\n');
}	

//Función para limpiar pantalla
void clrCommand()
{
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
  return;
}



//Función que cambia a otra carpeta si es que esta existe.
void cdDir(char** parsed)
{
  DIR *dir;
  dir = opendir(parsed[1]);
  if (dir == NULL)
    {
     printf("Error!! Al abrir el directorio.\n");
     } 
   else 
    {
     chdir(parsed[1]);
     
    }
 return;
 }

//Función que enlista los archivos contenidos
void dirCommand()
{
  DIR *dir;
  dir = opendir(".");
  struct dirent *ent;
  size_t i=1;
  while((ent = readdir (dir)) != NULL)
   {} 
 return;
}
  
// Función para ejecutar comandos
int ComandosCreados(char** parsed) 
{ 
    int total = 8, i, eleccion = 0; 
    char* Comandos[total];   
    Comandos[0] = "cd"; 
    Comandos[1] = "clr"; 
    Comandos[2] = "dir"; 
    Comandos[3] = "environ";
    Comandos[4] = "echo";
    Comandos[5] = "help";
    Comandos[6] = "pause";
    Comandos[7] = "quit"; 
  
    for (i = 0; i < total; i++) { 
        if (strcmp(parsed[0], Comandos[i]) == 0) { 
            eleccion = i + 1; 
            break; 
        } 
    } 
  
    switch (eleccion) { 
    case 1:
       cdDir(parsed);       
       return 1;
    case 2: 
        clrCommand(); 
        return 1; 
    case 3: 
        dirCommand();
       return 1;
    case 4:
        printDir();
        return 1;
   case 5:
       printf("\n%s",parsed[1]);
       return 1;
   case 6:
        Ayuda();
        return 1;
   case 7:
       parar();
     return 1;
   case 8:
      exit(0);
      break;
    default:
       printf("\nComando incorrecto.\n"); 
        break; 
    } 
    return 0; 
} 


// Función que realiza el parsing de los comandos digitados
void parseSpace(char* str, char** parsed) 
{ 
    int i;  
    for (i = 0; i < MAXLIST; i++) { 
        parsed[i] = strsep(&str, " "); 
        if (parsed[i] == NULL) 
            break; 
        if (strlen(parsed[i]) == 0) 
            i--; 
    } 
} 
  
int processString(char* str, char** parsed) 
{ 
   parseSpace(str, parsed); 
   if(ComandosCreados(parsed))
      return 0; 
    else
      return 1;
} 
  
int main() 
{ 
    char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
    obtenerShell();
    while (1) {
    // Capturar datos de entrada 
    if (DatosEntrada(inputString)) 
       continue; 
      // proceso 
       processString(inputString,parsedArgs); 
        execArgs(parsedArgs);
    } 
    return 0; 
}  


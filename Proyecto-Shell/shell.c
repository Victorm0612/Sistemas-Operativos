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
#include <dirent.h>
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
  
#define MAXCOM 1000 // máximo número de letras que se pueden soportar 
#define MAXLIST 100 // máximo número de comandos que se pueden soportar
char cwd[1024];
char shell[1024];  
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
  
// Función que imprime el directorio actual. 
void printDir() 
{    
    getcwd(cwd, sizeof(cwd));
    getcwd(shell, sizeof(cwd));
   printf("$PWD = %s:   $shell=%s\n",cwd,shell); 
} 

// Función para ejecución de argumentos 
void execArgs(char** parsed) 
{ 
    // Forking a child 
    pid_t pid = fork();  
  
    if (pid == -1) { 
        printf("\nFailed forking child.."); 
        return; 
    } else if (pid == 0) { 
        if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command.."); 
        } 
        exit(0); 
    } else {  
        wait(NULL);  
        return; 
    } 
} 
  
// Function where the piped system commands is executed 
void execArgsPiped(char** parsed, char** parsedpipe) 
{ 
    // 0 is read end, 1 is write end 
    int pipefd[2];  
    pid_t p1, p2; 
  
    if (pipe(pipefd) < 0) { 
        printf("\nPipe could not be initialized"); 
        return; 
    } 
    p1 = fork(); 
    if (p1 < 0) { 
        printf("\nCould not fork"); 
        return; 
    } 
  
    if (p1 == 0) { 
        // Child 1 executing.. 
        // It only needs to write at the write end 
        close(pipefd[0]); 
        dup2(pipefd[1], STDOUT_FILENO); 
        close(pipefd[1]); 
  
        if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command 1.."); 
            exit(0); 
        } 
    } else { 
        // Parent executing 
        p2 = fork(); 
  
        if (p2 < 0) { 
            printf("\nCould not fork"); 
            return; 
        } 
  
        // Child 2 executing.. 
        // It only needs to read at the read end 
        if (p2 == 0) { 
            close(pipefd[1]); 
            dup2(pipefd[0], STDIN_FILENO); 
            close(pipefd[0]); 
            if (execvp(parsedpipe[0], parsedpipe) < 0) { 
                printf("\nCould not execute command 2.."); 
                exit(0); 
            } 
        } else { 
            // parent executing, waiting for two children 
            wait(NULL); 
            wait(NULL); 
        } 
    } 
} 
  
// Menú de ayuda
void Ayuda() 
{ 
   printf("\n--- BIENVENIDO A SHELL ---"
                          "\n La lista de comandos internos disponibles es:"
                          "\n * cd <directorio>: Cambiar el directorio"
                          "\n * clr: Limpiar la pantalla"
                          "\n * dir <directorio>: Listar el contenido del directorio"
                          "\n * environ: Listar todas las cadenas de entorno"
                          "\n * echo <comentario>: Desplegar el comentario en pantalla"
                          "\n * help: Desplegar el manual de usuario"
                          "\n * pause: Deterner la operación del shell hasta que se presiona enter"
                          "\n * quit: Salir de MYSHELL"); 
  
    return; 
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
}

//Función que enlista los archivos contenidos
void dirCommand()
{
  DIR *dir;
  dir = opendir(".");
  struct dirent *ent;
  size_t i=1;
  if(dir == NULL)
 {
  printf("\nDirectorio no encontrado.\n");
 }
 else
 { 
  while((ent = readdir (dir)) != NULL)
   {
    printf("%u. %s\n",i, ent->d_name);
   } 
 }
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
        dirCommand(parsed);
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
    default: 
        break; 
    } 
  
    return 0; 
} 

  
// function for finding pipe 
int parsePipe(char* str, char** strpiped) 
{ 
    int i; 
    for (i = 0; i < 2; i++) { 
        strpiped[i] = strsep(&str, "|"); 
        if (strpiped[i] == NULL) 
            break; 
    } 
  
    if (strpiped[1] == NULL) 
        return 0; // returns zero if no pipe is found. 
    else { 
        return 1; 
    } 
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
  
int processString(char* str, char** parsed, char** parsedpipe) 
{ 
  
    char* strpiped[2]; 
    int piped = 0; 
  
    piped = parsePipe(str, strpiped); 
  
    if (piped) { 
        parseSpace(strpiped[0], parsed); 
        parseSpace(strpiped[1], parsedpipe); 
  
    } else { 
  
        parseSpace(str, parsed); 
    } 
  
    if (ComandosCreados(parsed)) 
        return 0; 
    else
        return 1 + piped; 
} 
  
int main() 
{ 
    char inputString[MAXCOM], *parsedArgs[MAXLIST]; 
    char* parsedArgsPiped[MAXLIST]; 
    int execFlag = 0; 
    
    while (1) { 
        // take input 
        if (DatosEntrada(inputString)) 
            continue; 
        // process 
        execFlag = processString(inputString,parsedArgs, parsedArgsPiped); 
        // execflag returns zero if there is no command 
        // or it is a builtin command, 
        // 1 if it is a simple command 
        // 2 if it is including a pipe. 
  
        // execute 
        if (execFlag == 1) 
            execArgs(parsedArgs); 
  
        if (execFlag == 2) 
            execArgsPiped(parsedArgs, parsedArgsPiped); 
    } 
    return 0; 
}  


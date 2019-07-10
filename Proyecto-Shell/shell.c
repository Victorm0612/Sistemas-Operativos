#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include <stdlib.h>
#include <string.h>
enum internalCommands{cd=1, environ, echo, help, general};
#define MAX_SIZE 100

char* myCommand(char* command, char* subcommand);
void interpretGeneralCommand(char *command, char* args[]);
void interpretInternalCommand(char *command, char* args[]);
void readCommand(char *command);
int countSpaces(char* command);
int takeOption(char* command);
void interCommandsMenu();
void helpCommand(char *aux, char* args[]);
void dirCommand(char * command);
void clrCommand();
void pauseCommand();
void takeDirName(char* command, char* dirname);
void processCommand(char* command, char* args[]);
char* takeSubCommand(char* command);


int main(int argc, char *argv[], char * envp[])
{

	pid_t value; 
	char* command; 
	char *args[20];
	//Reserva memoria de manera dinamica
	command = (char*) malloc(sizeof (char *));
	int cont=0;
	
			
	do{
		
		readCommand(command);//Invoca función para leer el comando
		
		if (strcmp("quit", command) == 0) break;
		
		if (strcmp("clr", command) == 0)
		{
			clrCommand();
		}else
		if(strcmp("pause", command) == 0)
		{
			pauseCommand();
		}else
		if(strcmp("dir <", takeSubCommand(command)) == 0)//Modificar posicion
		{
			dirCommand(command);
		}else
		{
			processCommand(command, args);//Invoca función para procesar el comando
			
			value = fork();
			if(value == 0)
			{
				//Proceso hijo
				execvp(args[0], args);//Invoca una llamada al sistema de la famila exec para ejecutar los comandos
				printf("\nEsto no deberia imprimirse.\n");

			}else
			{
				//Proceso padre
				wait(NULL);//Espera hasta que su hijo finalice
			
			}
		}
		
			
		//Contador provicional
		cont ++;
		

	}while(cont<10);

	//Liberación de memoria
	free(command);
	
	
	return 0;	
}


char* myCommand(char* command, char* subcommand)
{
	//Recorrer comando
	int i=0;
	int j=0;
	int contador=0;
	char *aux;
	aux = (char*) malloc(sizeof (char *));
	while( i < strlen(command) && command[i] != '\n')
	{
			
		if (command[i] == 32)
		{
			
			contador++;
		}

		if (contador == 0)
		{
			aux[i]=command[i]; //Revisar 
		}else
		{
			command[j]=command[i+1];
			
			j++;
		}
	
			i++;
	}
	strcpy(subcommand, aux);
	free(aux);
	return subcommand;
	
}

int countSpaces(char* command)
{
	//Recorrer comando
	int i=0;
	int contador=0;
	while( i < strlen(command) && command[i] != '\n')
	{
			
		if (command[i] == 32)
		{
			
			contador++;
		}

		i++;
	}
	return contador;
}

void interpretInternalCommand(char *command, char* args[])
{
	char * aux;
	aux= (char *)malloc(sizeof(char *));
	int option = takeOption(command);
	switch(option)
	{
		
		case help:
			helpCommand(aux, args);
		break;

		//default:
	}

	free(aux);
}

void interpretGeneralCommand(char *command, char* args[])
{
	char * subcommand;
	subcommand = (char*) malloc(sizeof (char *)); 
	int counter = countSpaces(command);//Invocación de la función

	for(int j=0; j< (counter + 1); j++)
	{
		//Permite strdup duplicar un string
		args[j] =strdup(myCommand(command, subcommand));//Invoca a la función 

	}
	args[counter+1] = NULL;
	free(subcommand);
}

void readCommand(char *command)
{

	printf("prompt>");
	//Leer comando
	fgets(command, MAX_SIZE, stdin);
	//Eliminar la nueva linea final si la hay
	if ((strlen(command) > 0) && (command[strlen (command) - 1] == '\n'))
       	{
		command[strlen (command) - 1] = '\0';
	}

}

int takeOption(char* command)
{
	if(strcmp(command, "cd") == 0)
	{
		return 1;
	}else 
	if(strcmp(command, "environ") == 0)
	{
		return 2;
	}else
	if(strcmp(command, "echo") == 0)
	{
		return 3;
	}else
	if(strcmp(command, "help" )== 0)
	{
		return 4;
	}else 
	{
		return 5;
	}

}
void processCommand(char* command, char* args[])
{
	int option = takeOption(command);
	switch(option)
	{
		case cd:
			printf("cd\n");
		break;
		case environ:
			printf("environ\n");
		break;
		case echo:
			printf("echo\n");
		break;
		case help:
			interpretInternalCommand(command, args);
		break;
		default:
			interpretGeneralCommand(command, args);
	}


}	

void clrCommand()
{
	const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
	
}

void pauseCommand()
{	
	char op;
	do{
		printf("Pausado..."
	       		"\nPresionar enter para continuar...");
		op= getchar();

	}while(op != '\n');

}
void helpCommand(char *aux, char* args[])
{
	aux =strdup("\n--- BIENVENIDO A MYSHELL ---"
			  "\n La lista de comandos internos disponibles es:"
			  "\n * cd <directorio>: Cambiar el directorio"
			  "\n * clr: Limpiar la pantalla"
			  "\n * dir <directorio>: Listar el contenido del directorio"
         		  "\n * environ: Listar todas las cadenas de entorno"
         		  "\n * echo <comentario>: Desplegar el comentario en pantalla"
         		  "\n * help: Desplegar el manual de usuario"
         		  "\n * pause: Deterner la operación del shell hasta que se presiona enter"
         		  "\n * quit: Salir de MYSHELL");
	args[0]= "more";
	args[1]= aux;
	args[2]= NULL;

}
void takeDirName(char* command, char* dirname)
{
	//Recorrer comando
	int i=0, j=0, contador=0;
	char *aux;
	aux = (char*) malloc(sizeof (char *));
	while( i < strlen(command) && command[i] != '>')
	{

		if(command[i] == 32)
		{
			contador ++;
			
		}
		if(contador == 1)
		{
			if(command[i] != '>' && command[i] != '<' && command[i] != 32)
			{
				aux[j]=command[i];
				j++;
			}
		} 
				
		i++;
	}

	strcpy(dirname, aux);
	free(aux);
	
}

void dirCommand(char * command)
{
	DIR *dir;
	struct dirent *sd;
	char *dirname;
	char * path;
	char buffer[1024]=" ";
	dirname = (char*) malloc(sizeof (char *));

	if(countSpaces(command) == 1)
	{
		takeDirName(command,dirname);
		path = realpath(dirname, NULL);
		if (path == NULL)
		{
			perror("Error!!\n");
			exit(1);
		}else
		{
			printf("%s\n", path);
			dir = opendir(path);
			if (dir == NULL)
			{
				printf("\nError!! Al abrir el directorio.\n");
			
			}
			
			while((sd= readdir(dir)) != NULL)
			{
				printf("%s\n", sd->d_name);
			}
			closedir(dir);
			
		}	
		
	}else
	{
		perror("Commando no valido!!");
	} 
	free(dirname);
	
}

char* takeSubCommand(char* command)
{
	//Recorrer comando
	int i=0;
	char *aux=(char*) malloc(10);

	while( i < strlen(command) && command[i] != '\n')
	{
		
		aux[i]=command[i];
		i++;
		if(command[i] == '<')
		{
			aux[i]=command[i];
			break;
	
		}	
		
	}

	return aux;
	
}



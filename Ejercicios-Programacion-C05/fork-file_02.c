#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char** argv)
 {
  FILE *archivo;
  pid_t pid;
  if((archivo = fopen(argv[1],"r"))!=NULL)
  {
   archivo=fopen(argv[1],"w+");
   pid = fork();
   if (pid < 0)
   {
    fprintf(stderr, "fork fallido.\n");
   }
   else if(pid == 0)
   {
    fprintf(archivo, "Soy el hijo...\n");
   }
   else
   {
    fprintf(archivo, "Soy el padre...\n");
   }
  }
 else
  {
   printf("El archivo a editar no existe. Revise lo ingresado.\n");
  }
 }


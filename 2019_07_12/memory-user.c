#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if(argc < 2)
   {
    printf("No se encontraron argumentos\n.");
    exit(1);
   }
   int bytes;
   bytes = atoi(argv[1]);
   int *array = malloc(bytes*1024*1024*(sizeof(int)));
   if(array==NULL)
   { 
    printf("Memoria no asignada.\n");
    exit(-1);
   }
  int i=0;
  for(; i<bytes*1024*1024; i++)
  array[i]=i;
  sleep(10);

 return 0;
}

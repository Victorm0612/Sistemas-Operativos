#include <unistd.h>
#include <stdio.h>

/**
ESte programa en C debe imprimir lo siguiente:

Soy el hijo y mi identificador es 34567
Soy el padre, mi identificador es 34566 y el de mi hijo es 34567

Hacer uso de la función 'getpid()'
*/

int main(int argc, char** argvc) 
{
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
  printf("\nSoy el hijo y mi identificador es: %d\n", (int) getpid());
  
  }
  else
  {
   printf("\nSoy el padre, mi identificador es: %d ",(int) getpid());
   printf(" Y mi hijo es: %d\n",(int) pid);
  }
}

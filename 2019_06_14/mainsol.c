#include "solucion.h"
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
()'
*/


int main(int argc, char** argv) {
  int x = 20;
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
   x = fibonacci(x);
   guardarEntero("archivo",x);

   return 0;
  }
  else
  {
   int var;
   pid_t pid2;
   pid2 = wait(NULL);
   var = leerEntero("archivo");
   printf("El número es: %d ",(int) var);
   printf("y si lo multiplicamos por 100 es: %d\n",(int) var*100);
  }

}

 

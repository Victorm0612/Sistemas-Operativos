#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void iterar(int n, char rol[])
 {
   while(1)
    {
     sleep(1); 
     n++;
     printf("Soy el %s:  %d\n",rol,n);
    }
 }

int main(int argc, char** argv)
 {
  int x = 100;
  char p[] = "padre", h[] = "hijo";
  pid_t pid;
  pid = fork();
  if(pid == 0)
  {
   iterar(x,h);
  }
  else
  {
    iterar(x,p);
  }
 }

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
 {
  pid_t pid;
  pid = fork();
  if(pid == 0)
   {
    printf("hello.\n");
   }
  else
   {
    sleep(1);
    printf("goodbye.\n");
   }
 }

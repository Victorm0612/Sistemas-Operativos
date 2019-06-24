#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
 {
  pid_t pid;
  pid = fork();
  if(pid < 0)
   {
    fprintf(stderr, "fork fallido.\n");
    exit(1);
   }
  else if(pid == 0)
   {
    printf("hello.\n");
   }
  else
   {
    printf("goodbye.\n");
   }
  return 0;
 }

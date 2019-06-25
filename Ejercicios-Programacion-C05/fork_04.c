#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv)
 {
  pid_t pid;
  pid = fork();
  char* args[2];
  args[0]="/bin/ls";
  args[1]=NULL;
   if (pid < 0)
   {
    fprintf(stderr, "fork failed\n");
    exit(1);
   }
   else if(pid == 0)
   {
    printf("Usando execvp:\n");
    execv(args[0],args);
    
   }
  else
   {
    sleep(1);
    printf("Usando exec:\n");
   }
  return 0;
 }

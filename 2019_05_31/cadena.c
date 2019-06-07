#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char cadena[] = "hola mundo";
  char *apcad;

  apcad = (char*)malloc(sizeof(char));
  *apcad = 'h';
  printf("%c\n",*apcad);
  apcad[3] = 'o';
  printf("%c\n",apcad[1]);

  return 0;

  printf("Cadena: %s apcad: %s\n",cadena,apcad);
  apcad = cadena;
  printf("Cadena: %s apcad: %s\n",cadena,apcad);
  cadena[0] = 'H';
  printf("Cadena: %s apcad: %s\n",cadena,apcad);
  apcad[1] = 'O';
  printf("Cadena: %s apcad: %s\n",cadena,apcad);
  apcad = (char*)1024;
  printf("%s\n",apcad);
}

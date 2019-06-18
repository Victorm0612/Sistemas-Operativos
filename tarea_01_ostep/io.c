#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
 {
  FILE *archivo;
  int Lp; //Lp = LastPosition
  int posActual = 0; //posActual = PosiciónActual

//VALIDACIÓN-EXISTENCIA DE ARCHIVO DE TEXTO//
if((archivo = fopen(argv[1],"r"))!=NULL)
     {
         archivo = fopen(argv[1],"r");
         fseek(archivo,0,SEEK_END);
         Lp = ftell(archivo);
         do
          {
           printf("%c",fgetc(archivo));
           fseek(archivo,-posActual,SEEK_END);
           posActual++;
          }
         while(posActual <= (Lp+1));
         printf("\n");
         fclose(archivo);
         return 0;
     }
    else
        {
            printf("Archivo no encontrado, revise lo digitado\n");
        }
 }

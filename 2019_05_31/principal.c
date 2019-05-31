#include <stdio.h>
#include "entero.h"

int main(int argc, char** argv) {
  entero a,b;

  a = 5;
  b = 6;
  printf("la división de %d / %d es %f\n",a,b,(float)div(a,b));
}


#include<stdio.h>

int suma(int *a, int b)
{
*a = *a + b;
return *a;
}
int resta(int a, int b)
{
a = a - b;
return a;
}

int main(int argc, char** argv)
{
 int a = 10, b = 5;

 resta(a,b); printf("Valor de a: %d valor de b: %d\n",a,b);
 suma(&a,b); printf("Valor de a: %d valor de b: %d\n",a,b);

return 0;
}

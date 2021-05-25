#include <stdio.h>
#include <stdlib.h>

// Ponteiros para ponteiros.

int main(){

int a =10;
int *p1 = &a; // Ponteiro inteiro recebendo endereço de a;
int **p2 = &p1; // '**' Ponteiro de ponteiro, pode apenas apontar para ponteiros.

printf("A=%d\n",a);
printf("A=%d\n",*p1);
printf("A=%d\n",**p2);
printf("Endereço de A=%d\n",&a);
printf("Endereço de A=%d\n",p1);
printf("Endereço de A=%d\n",*p2);


return 0;
}

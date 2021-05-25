

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"



void mostrafloat(void *k){
printf("%f\n",*(float*)k);
}

int main(){
Lista l1,l2;
IniciaLista(&l1,sizeof(float));

float x = 1;
insereInicio(&l1, &x);
x = 2;
insereInicio(&l1, &x);
x = 3;
insereInicio(&l1, &x);
x = 4;
insereInicio(&l1, &x);

mostraLista(&l1, mostrafloat);

system("pause");

return 0;
}

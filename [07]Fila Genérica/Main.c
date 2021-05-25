#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaGenerica.h"


void mostraFloat(void *x){
   float *p=x;
   printf("%.2f\n",*(float*)x);
}

int main(){
    FilaGenerica f1;
    incializaFila(&f1,20,sizeof(float));
    float x=4;
    inserir(&f1,&x); // void aceita tudo, portanto precisa mandar um endereço não o valor em si.
    x=8;
    inserir(&f1,&x);
    x=16;
    inserir(&f1,&x);
    mostraFila(p1,mostraFloat);
    remover(&f1,&x);
    printf("Removido %.2f\n",x);
    DesalocaFila(&f1);
return 0;
}

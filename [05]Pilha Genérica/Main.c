#include <stdlib.h>
#include <stdio.h>
#include "PilhaGenerica.h"

// Ponteiros void (void*).
// Ponteiros apontando para uma fun��o void.
// Desta maneira pode guardar dados de qualquer tipo.
// dados/capacidade/topo/tamanho da informa��o/.

void mostraFloat(void *x);

int main(){
PilhaGenerica p1; // Puxa o header e d� um parametro � ele. Sendo p1.
IniciaPilha(&p1,20,sizeof(float)); // Inicia a pilha com os parametros - dados, capacidade, tamanho da informa��o.
float x=3;
Empilha(&p1,&x); // Dados e o valor � passado por refer�ncia, pq � usado ponteiros, e nada de valores.
//           |-> x � um ponteiro do tipo void. (Gen�rico).
x=7;
Empilha(&p1,&x);
x = 11;
Empilha(&p1,&x);
float y;
Desempilha(&p1,&y);
printf("Removido: %.2f\n",y);
Mostra_pilha(p1,mostraFloat);
Desaloca_Pilha(&p1);
}

void mostraFloat(void *x){
   float *p=x;
   printf("%.2f\n",*p);
}


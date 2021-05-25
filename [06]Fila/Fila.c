// FILA: estrutura linear cujo acesso � feito somente nas duas extremidades.
// -> FIM: inser��o.
// -> IN�CIO: remo��o.

// fim -> \o/ \o/ \o/ \o/ -> in�cio.
// Fifo -> First in first out.

// TIPOS
// -> Fila de prioridade.
// |-> Alguns elementos podem ter prioridade � outros, podendo entrar por outro local.
// -> Fila de Duplo Fim (Double-ended queue).

// APLICA��ES
// -> Sistema Operacional.
// |-> Processos, arquivos, impress�es, etc.
// -> Ambientes de simula��o.
// |->Filas de Recursos.

// FILA ABSTRATA, SEM SABER COMO � IMPLEMENTADA
#include <stdlib.h>
#include <stdio.h>
#include "Fila.h" // Fila de inteiros.

int main (){

Fila f1;
InicializaFila(&f1,20); // 20 = capacidade.
int x = 3;
inserir(&f1,x);
x = 7;
inserir(&f1,x);
x = 11;
inserir(&f1,x);
mostraFila(f1);
remover(&f1,&x); //Passado por parametro.
printf("Removido: %i\n",x);

desalocaFila(&f1);
return 0;
}

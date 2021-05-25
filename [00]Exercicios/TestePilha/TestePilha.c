#include <stdlib.h>
#include <stdio.h>
#include "TestePilha.h"

void iniciarPilha (Pilha *p,int d){
p->dados=malloc(sizeof(int)*d);
p->capacidade=d;
p->topo=-1;
}

int Empilha(Pilha *p,int info){

if(PilhaCheia(*p)){
    return ALERTA_PILHA_CHEIA;
}else{
p->topo++;
p->dados[p->topo] = info;
return 1;
 }
}

int Desempilha(Pilha *p, int *info){
 if(PilhaVazia(*p)){
    return ALERTA_PILHA_VAZIA;
 }else{
 *info = p->dados[p->topo];
 p->topo--;
 return 1;
 }
}

void MostrarPilha(Pilha *p){

  if(PilhaVazia(*p)){
    printf("Pilha Vazia\n");
  }else{
  printf("Dados da Pilha\n");
  for(i=0;i<=p;i++){
    printf("%i\n",p.dados[i]);
  }
 }
}

void DesalocaPilha(Pilha *p){
free(p->dados);
}

int PilhaCheia(Pilha p){
	return p.topo == p.capacidade-1; //Retorna 1 se verdade ou 0 se falso
}

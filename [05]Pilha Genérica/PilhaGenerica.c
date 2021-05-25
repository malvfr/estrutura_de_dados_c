#include <stdlib.h>
#include <stdio.h>
#include "PilhaGenerica.h"
#include <string.h> // memcpy est� aqui.

void IniciaPilha(PilhaGenerica *p,int c,int t){
p->dados=malloc(sizeof(void*)*c); // malloc de um ponteiro void. uso da '->' pois � um ponteiro para um ponteiro.
p->capacidade=c; // define a capacidade
p->tamanhoInfo=t; // define o tamanho da informa��o.
p->topo=-1; // aponta o topo.
} // Aqui a pilha � inicializada.

int Pilha_cheia(PilhaGenerica *p){
	return p.topo == p.capacidade-1; //Retorna 1 se verdade ou 0 se falso
} // Verifica se a pilha est� cheia, caso o p.topo seja o limite da pilha, retorna 1 para afirmar cheia.

int Pilha_vazia(PilhaGenerica *p){ // verifica se a pilha est� vazia.
	if(p.topo == -1){
		return 1; // pilha vazia
		}else{
		return 0; // pilha com conteudo.
	}
}

int Empilha(PilhaGenerica *p, void *info){
   if(PilhaCheia(*p)){
    return ERRO_PILHA_CHEIA;
   }
   p->topo++;// aumenta o topo, liberando espa�o.
   p->dados[p->topo]= malloc(p->tamanhoInfo); // j� possui o tamanho, assim aloca ele para a varivel '**'
   memcpy(p->dados[p->topo],info,tamanhoInfo); // Faz a c�pia bruta dos dados.
   //     |-> Parametros, local apontando, informa��o, tamanho da informa��o.
   return 1; // SUCESSO.
}

int Desempilha(PilhaGenerica *p, void *info){
  if(PilhaVazia(*p)){
    return ERRO_PILHA_VAZIA;
  }
  memcpy(info,p->dados[p->topo],p->tamanhoInfo); // invetendo a ordem dos parametros, atribui��o contr�ria ao empilha
  free(p->dados[p->topo]); // libera o ponteiro, para assim n�o ocupar memoria, o memcpy retira o valor daqui.
  p->topo--; // Diminui o topo.
  return 1; // SUCESSO.
}

void Mostra_pilha(PilhaGenerica p, void (*mostra)(void*)){
	if(pilha_vazia(p))
		printf("\nPilha vazia.");
	else{
		printf("\nDados da pilha: \n");
		int i;
		for (i=0;i<=p.topo;i++)
			mostraFloat(p.dados[i]);
	}
}

void Desaloca_Pilha(PilhaGenerica *p){
int i;
for(i=0;i<=p->topo;i++)
    free(p->dados[i])
free(p->dados);
}


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"



void IniciaLista(Lista *l,int t){
    l->tamInfo = t;
    l->cabeca = NULL;
}

Elemento *aloca_elemento(void *info,int tamInfo){
    Elemento *p = malloc(sizeof(Elemento));
    if(p == NULL) return NULL;

    p->info = malloc(tamInfo);

    if(p->info == NULL) {free(p);return NULL;}

    memcpy(p->info,info,tamInfo);
    return p;
}

int insereInicio(Lista *l, void *info){
    Elemento *p = aloca_elemento(info,l->tamInfo);

    if(p == NULL) return 0;

    p->proximo = l->cabeca;
    l->cabeca = p;
    return 1;
}

int insereFim(Lista *l,void *info){
    if(ListaVazia(l)) return insereInicio(l,info);

    Elemento *p = l->cabeca;

    while(p->proximo != NULL){
        p = p->proximo;
    }

    Elemento *novo = aloca_elemento(info,l->tamInfo);
    if(novo == NULL) return 0;

    p->proximo = novo;
    novo->proximo = NULL;
    return 1;
}

int inserePosicao(Lista *l,void *info,int posicao){
 //criar um contador e atualizar a cada inserção e remoção da lista
    if(posicao < 0) return ERRO_POSICAO_INVALIDA;
    if(posicao == 0) return insereInicio(l,info);
    if(ListaVazia(l)) return ERRO_POSICAO_INVALIDA;

    Elemento *p = l->cabeca;
    int cont = 0;

    while((cont < posicao - 1) && (p->proximo != NULL)){
        p = p->proximo;
        cont++;
    }

    if(cont != posicao -1) return ERRO_POSICAO_INVALIDA;

    Elemento *novo = aloca_elemento(info,l->tamInfo);
    if(novo == NULL) return 0;//erro por falta de memória;

    novo->proximo = p->proximo;
    p->proximo = novo;

    return 1;
}



int ListaVazia(Lista *l){
    return l->cabeca == NULL;
}


int removePosicao(Lista *l,void *info,int posicao){

 if(posicao < 0) return ERRO_POSICAO_INVALIDA;
    if(posicao == 0) return insereInicio(l,info);
    if(ListaVazia(l)) return ERRO_POSICAO_INVALIDA;

    Elemento *p = l->cabeca;
    int cont = 0;

    while((cont < posicao - 1) && (p->proximo != NULL)){
        p = p->proximo;
        cont++;
    }

    if(p->proximo == NULL) return ERRO_POSICAO_INVALIDA;

    memcpy(info,p->proximo->info,l->tamInfo);

    Elemento *x = p->proximo;
    p->proximo = x->proximo;
    free(x->info);
    free(x);



}
int removeInicio(Lista *l,void *info){
    if(ListaVazia(l))
        return ERRO_LISTAVAZIA;
    Elemento *p = l->cabeca;
    memcpy(info,p->info,l->tamInfo);
    l->cabeca = p->proximo;
    free(p->info);
    free(p);
    return 1;
}

int removeFim(Lista *l,void *info){
 if(ListaVazia(l)) return ERRO_LISTAVAZIA;

if(l->cabeca->proximo == NULL) //so 1 elemento;
    return removeInicio(l,info);

Elemento *p = l->cabeca;

while(p->proximo->proximo != NULL){
 p = p->proximo;
 }

memcpy(info,p->proximo->info,l->tamInfo);

free(p->proximo->info);
free(p->proximo);
p->proximo = NULL;

return 1;
}

void mostraLista(Lista *l, void(*mostra)(void*)){
    if(ListaVazia(l))
        printf("Lista vazia!");
    else{
        Elemento *p = l->cabeca;
        printf("Dados da lista: \n");
        while(p != NULL){
            mostra(p->info);
            p=p->proximo;
        }
    }
}

int limpa_lista(Lista *l){
  if(ListaVazia(l)) return ERRO_LISTAVAZIA;

Elemento *p = l->cabeca;

while(p !=  NULL){
    Elemento *prox = p->proximo;
    free(p->info);
    free(p);
    l->cabeca = prox;
    p = prox;
}

}

int leNaPosicao(Lista *l, void *info, int posicao){
  if(posicao < 0)
    return ERRO_POSICAO_INVALIDA;

 // if(lista_vazia(l))
   // return ERRO_POSICAO_INVALIDA;

  Elemento *p = l->cabeca;
  int cont = 0;
  while(cont<posicao && p->proximo != NULL){
    p = p->proximo;
    cont++;
  }

  if(cont != posicao)
    return ERRO_POSICAO_INVALIDA;

  memcpy(info, p->info, l->tamInfo); /* para modificar no posição, basta
                                                     inverter a ordem dos parâmetros */
  return 1;// SUCESSO
}

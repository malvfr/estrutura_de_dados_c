#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaGenerica.h"

void inicializaFila(FilaGenerica *f,int c,int t){
      f->dados=malloc(sizeof(void*)*c);
      f->capacidade=c;
      f->inicio=f->fim=f->qtd=0;
      f->tamInfo=t; // inicia o tamanho da informação.
}

int FilaCheia(FilaGenerica *f){
    return f.qtd==0;
}

int FilaVazia(FilaGenerica *f){
    return f.qtd == f.capacidade;
}

int inserir(FilaGenerica *f,void *info){
    if(FilaCheia(*f)){
        return ERRO_FILA_CHEIA;
    }
    f->qtd++;
    f->dados[f->fim]=malloc(f->tamInfo));
    memcpy(f->dados[f->fim],info,f->tamInfo);
    if(f->fim == f->capacidade-1){
        f->fim = 0;
    }else{
        f->fim++;
    }
    return 1; // sucesso.
}

int remover(FilaGenerica *f, void *info){
    if(FilaVazia(*f)){
        return ERRO_FILA_VAZIA;
    }

    memcpy(info,f->dados[f->inicio],f->tamInfo);
    free(f->dados[f->incio]);
    f->inicio--;
    return 1; //sucesso.
}

void DesalocaFila(FilaGenerica *f){
if(!FilaVazia(*f)){
    processaFila(f,free);
}
free(f->dados);
}

void MostraFila(FilaGenerica *f,void(*mostra)(void*)){
    if(FilaVazia(*f)){
        printf("Fila Vazia");
    }else{
    processaFila(&f,mostra);
    }
}

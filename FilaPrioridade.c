#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridade.h"

void inicializaFila(FilaPrioridade *f,int c,int t){
 f->capacidade = c;
 f->qtd = 0;
 f->inicio = 0;
 f->dados = malloc(sizeof(void*) * c);
 f->tamInfo = t;

}

int FilaCheia(FilaPrioridade *f){
    return f->inicio == f->capacidade-1;
}

int FilaVazia(FilaPrioridade *f){
    return f->inicio == -1;
}

int inserir(FilaPrioridade *f,void *info,int (*compara)(void*,void*)){
    if(FilaCheia(&f)){
        return ERRO_FILA_CHEIA;
    }

    int k = 0,i;

    while(k <= f->inicio && compara(info,f->dados[k])< 0){
        k++;
    }

	for (i = f->inicio; i >= k; i--) {
        f->dados[i+1] = f->dados[i];
    }

    f->dados[k] = malloc(f->tamInfo);
    memcpy(f->dados[k],info,f->tamInfo);
    f->inicio++;
    return 1;

}

int remover(FilaPrioridade *f, void *info){
    if(FilaVazia(&f)){
        return ERRO_FILA_VAZIA;
    }

    memcpy(info,f->dados[f->inicio],f->tamInfo);
    free(f->dados[f->inicio]);
    f->inicio--;

    return 1; //sucesso.
}

void DesalocaFila(FilaPrioridade *f){
if(!FilaVazia(&f)){
    processaFila(f,free);
}
free(f->dados);
}

void MostraFila(FilaPrioridade *f,void(*mostra)(void*)){
    if(FilaVazia(&f)){
        printf("Fila Vazia");
    }else{
    processaFila(&f,mostra);
    }
}

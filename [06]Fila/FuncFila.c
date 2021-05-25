#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InicializaFila(Fila *f,int c){
  f->dados = malloc(sizeof(int)*c);
  f->cap = c;
  f->inicio = f->fim = f->qtd = 0;
}

int FilaCheia(Fila f){
   if(f.qtd == f.cap){
    return 1;
   }else{
    return 0;
   }
}

int FilaVazia(Fila f){
   if(f.qtd == 0){
    return 1;
   }else{
    return 0;
   }
}

int inserir(Fila *f, int info){
     if(FilaCheia(*f)){
        return ERRO_FILA_CHEIA;
     }
     f->qtd++;
     f->dados[f->fim]=info;
     if(f->fim == f->cap-1){
        f->fim =0;
     }else{
        f->fim++;
     }
}

int remover(Fila *f, int *info){
    if(FilaVazia(*f)){
        return ERRO_FILA_VAZIA;
    }
    f->qtd--;
    *info = f->dados[f->inicio];
    if(f->inicio==f->cap-1){
        f->inicio = 0;
    }else
        f->inicio++;
    return 1;
}

void mostraFila(Fila f){
    if(FilaVazia(f)){
        printf("Fila vazia!");
    }else{
        printf("Dados da fila: \n");
        int i;
        if(f.inicio<f.fim){
            for(i=f.inicio;i<f.fim;i++){
                printf("%i\n",f.dados);
            }
            }else{
                for(i=f.inicio;i<f.cap;i++){
                    printf("%i\n",f.dados);
                }
                for(i=0;i<f.fim;i++){
                    printf("%i\n",f.dados);
                }
            }
        }
    }


void desalocaFila(Fila *f){
free(f->dados);
}

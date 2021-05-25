#pragma once
#include "lista.h"
#define TRUE 1
#define FALSE 0
#define ERRO_MEMORIA -1
#define ERRO_NUMERO_INVALIDO -2
#define ERRO_NUMERO_NEGATIVO -3


LDE *adiciona(LDE *l1, int pos1, int pos2); //OK
LDE *f_adc(LDE *A, LDE *B);
LDE *subtrai(LDE*l1, int pos1, int pos2); // OK
LDE *f_subt(LDE *l1, LDE *l2);
LDE *multiplica(LDE *l1,int pos1,int pos2); //OK
LDE *f_mult(LDE *A, LDE *B);
LDE *potencia(LDE *l1, int pos1, int pos2); //INCOMPLETO
LDE *raiz(LDE *l1, int pos); //INCOMPLETO
LDE *divide(LDE *l1, int pos1, int pos2);

int mostra_numero(LDE *l1, int pos,void(*mostra)(void*)); //OK
int desaloca(LDE *l1, int pos); //OK
int inicializa_numero(LDE *l1, char *num); // OK
int verifica_caracteres(char *num); // OK
int compara_numeros(LDE *l1, int pos1, int pos2); //OK
int f_comp(LDE *A, LDE *B);

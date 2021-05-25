#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
//Este � o header, para declarar as fun�oes usadas no c�digo.

typedef struct {
void **dados; // vetor de dados, sendo void e um ponteiro de ponteiro.
int capacidade;
int topo;
int tamanhoInfo;
} PilhaGenerica;

 // cria��o da struct da pilha.
 // Declara��o da fun��es.

void IniciaPilha(PilhaGenerica *p,int c,int t);
int Pilha_vazia(PilhaGenerica *p);
int Pilha_cheia(PilhaGenerica *p);
int Empilha(PilhaGenerica *p, void *info);
int Desempilha(PilhaGenerica *p, void *info);
void Mostra_pilha(PilhaGenerica p, void(*mostra)(void*));
void Desaloca_Pilha(PilhaGenerica *p);

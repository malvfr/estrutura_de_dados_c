#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
//Este é o header, para declarar as funçoes usadas no código.

typedef struct {
void **dados; // vetor de dados, sendo void e um ponteiro de ponteiro.
int capacidade;
int topo;
int tamanhoInfo;
} PilhaGenerica;

 // criação da struct da pilha.
 // Declaração da funções.

void IniciaPilha(PilhaGenerica *p,int c,int t);
int Pilha_vazia(PilhaGenerica *p);
int Pilha_cheia(PilhaGenerica *p);
int Empilha(PilhaGenerica *p, void *info);
int Desempilha(PilhaGenerica *p, void *info);
void Mostra_pilha(PilhaGenerica p, void(*mostra)(void*));
void Desaloca_Pilha(PilhaGenerica *p);

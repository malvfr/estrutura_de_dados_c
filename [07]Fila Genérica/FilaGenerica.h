#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
    void **dados; // sendo void, sera um ponteiro de ponteiro.
    int capacidade, inicio, fim;
    int qtd,tamInfo; // tamInfo, faz o malloc pois o tamanha é desconhecido.
}FilaGenerica;
// Funções.

void incializaFila(FilaGenerica *f,int c,int t);
int FilaVazia(FilaGenerica *f);
int FilaCheia(FilaGenerica *f);
int inserir(FilaGenerica *f,void *info);
void mostrarFila(FilaGenerica *f,void(*mostra)(void*));
int remover(FilaGenerica *f1, void *info);
void DesalocaFila(FilaGenerica *f);



#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
    void **dados; // sendo void, sera um ponteiro de ponteiro.
    int capacidade, inicio;
    int qtd,tamInfo; // tamInfo, faz o malloc pois o tamanha é desconhecido.
}FilaPrioridade;
// Funções.

int compara_float(void *x,void *y);
void incializaFila(FilaPrioridade *f,int c,int t);
int FilaVazia(FilaPrioridade *f);
int FilaCheia(FilaPrioridade *f);
int inserir(FilaPrioridade *f, void *info, int(*compara)(void*, void*));
void mostrarFila(FilaPrioridade *f,void(*mostra)(void*));
int remover(FilaPrioridade *f1, void *info);
void DesalocaFila(FilaPrioridade *f);


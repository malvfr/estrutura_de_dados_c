#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct {
int *dados;
int cap;
int fim;
int inicio;
int qtd;
} Fila;

void InicializaFila(Fila *f,int c);
int FilaVazia(Fila f);
int FilaCheia(Fila f);
int inserir(Fila *f, int info);
int remover(Fila *f, int *info);
void mostraFila(Fila f);
void desalocaFila(Fila *f);



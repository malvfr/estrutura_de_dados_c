#define ERRO_LISTAVAZIA -1
#define ERRO_POSICAO_INVALIDA -2

typedef struct ele{
void *info;
struct ele *proximo;
}Elemento;

typedef struct{
int tamInfo;
Elemento *cabeca;
}Lista;


int limpa_lista(Lista *l);
int removeFim(Lista *l,void *info);
void IniciaLista(Lista *l,int t);
int insereInicio(Lista *l, void *info);
int inserePosicao(Lista *l,void *info,int posicao);
int removeInicio(Lista *l,void *info);
void mostraLista(Lista *l, void(*mostra)(void*));
int insereFim(Lista *l,void *info);
int ListaVazia(Lista *l);
int removePosicao(Lista *l,void *info,int posicao);
int leNaPosicao(Lista *l,void *info,int posicao);
Elemento *aloca_elemento(void *info, int tamInfo);

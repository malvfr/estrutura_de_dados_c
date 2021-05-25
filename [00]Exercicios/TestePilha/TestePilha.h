#define ALERTA_PILHA_VAZIA -1
#define ALERTA_PILHA_CHEIA  -2

typedef struct {
int *dados;
int topo,cap;
}Pilha;

int PilhaVazia(Pilha *p);
int PilhaCheia (Pilha *p);
int Empilha(Pilha *p,int info);
int Desempilha(Pilha *p, int *info);
void DesalocaPilha(Pilha *p)
void iniciarPilha (Pilha *p,int d);
void MostrarPilha (Pilha *p);

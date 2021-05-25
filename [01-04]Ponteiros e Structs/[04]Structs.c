#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Calcular a distancia entre dois pontos, usando pitagoras.
//raiz quadrada de((Ax-Bx)^2+(Ay-By)^2)

typedef struct { // usa o typedef para definir um tipo de estrutura, exemplo <--.
float x,y;
}Ponto2D; // Nome do tipo da estrutura exemplo isso eh = int.

float CalcDistancia(Ponto2D a,Ponto2D b){
// necessario chamar a biblioteca math.h , para assim usar expressoes matemáticas.
// sqrt = raiz quadrada.
// pow = Pontencia, (Parametro 1, Expoente);
return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

void LerPonto(Ponto2D *p){
printf("Dgite as coordenadas: ");
scanf("%f %f",&p->x,&p->y);
} // usar seta para ponteiros, assim jogando o resultado coletado no espaço de memoria do x,y.

void MostrarPonto(Ponto2D p){
   printf("\nx=%.1f , y=%.1f\n",p.x,p.y);
} // mostra todo o ponteiro, pois esta dentro do for.

int main(){
int n,i;
printf("Quantos pontos voce deseja inserir?");
scanf("%d",&n);
Ponto2D *v = malloc(sizeof(Ponto2D)*n); // aloca dinamicamente o n, do tamanho da struct Ponto2D.

for(i=0;i<n;i++){
    LerPonto(&v[i]);
} // chama a função LerPonto, para assim receber os valores dos pontos.

for(i=0;i<n-1;i++){
    float x= CalcDistancia(v[i],v[i+1]); // afirma que variavel x terá o valor do return da função CalcDistancia.
    printf("O valor da distancia entre p%d e p%d eh %.1f\n",i,i+1,x); // Printa o valor.
}

for(i=0;i<n;i++){
    MostrarPonto(v[i]);
} // Chama a função para printar os pontos na tela.
return 0;
}

#include <stdlib.h>
#include <stdio.h>

// Matriz din�mica, Dois ponteiros 'Duas dimen��es'

int main(){
int lin,con; // Linhas e Colunas.

printf("Digite o numero de linhas: ");
scanf("%d",&lin);
printf("Digite o numero de colunas: ");
scanf("%d",&con);

float **p = malloc(sizeof(float*)*lin); // Aloca��o de **p, float* um ponteiro float * numero de linhas.
int i,j;
for(i=0;i<lin;i++){
    p[i] = malloc(sizeof(float)*con); // Aloca��o de um vetor cujo tamanho � o numero de colunas.
}

for(i=0;i<lin;i++){
    for(j=0;j<con;j++){
        printf("Digite o valor [%d][%d] da matriz: ",i,j);
        scanf("%f",&p[i][j]);
    }
} // Digita os valores da matriz, usando p[i][j] = *(p+i)+j em aritm�tica de ponteiros.

for(i=0;i<lin;i++){
        printf("\n");
    for(j=0;j<con;j++){
       printf("%6.1f",p[i][j]);
  }
} // Imprime a matriz na tela.

for(i=0;i<lin;i++){
    free(p[i]); // Desalocar a memoria nas linhas, fazer isto primeiro para n�o deixa-las sem acesso ap�s free(p);.
}
free(p); // Desalocar a memoria em P


return 0;
}

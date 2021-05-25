#include <stdio.h>
#include <stdlib.h>

void leVetor(float *v,int k){
int i;
for(i=0;i<k;i++){
    printf("Digite a nota numero %dºº :",i+1);
    scanf("%f",&v[i]);
 }
}

void MediaNotas(float *v,int k){
float soma=0,mediaN,aux=0;
int i;
for(i=0;i<k;i++){
    aux = v[i];
    soma = soma + aux;
}
mediaN = soma/k;
 printf("\nA media do aluno eh de: %.2f",mediaN);
}

void ordena(float *p,int k){ // FUNÇÃO SELECTION!.
int i,j;
  for(i=0;i<k-1;i++){
    int iMenor = i;
    for(j=i+1;j<k;j++){
        if(p[j]<p[iMenor]){
         iMenor=j;
        }
    }
    int aux = p[i];
    p[i] = p[iMenor];
    p[iMenor] = aux;
  }
}

int main(){
int n;
int i;
printf("Digite quantas notas voce deseja inserir: ");
scanf("%d",&n);
float *p;
p = malloc(sizeof(float)*n);
leVetor(p,n);

for(i=0;i<n;i++){
    printf("Nota numero %d = %.2f\n",i+1,p[i]);
 }

 MediaNotas(p,n);
 ordena(p,n);

 printf("\nNota menor = %.2f",p[0]);
 printf("\nNota maior = %.2f",p[n-1]);

 free(p);
 return 0;
}

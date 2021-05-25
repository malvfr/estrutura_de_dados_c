#include <stdlib.h>
#include <stdio.h>

void mostraVetor(int *p,int k){
int i;
for(i=0;i<k;i++){
    printf("%d ",p[i]);
  }
}

void ordena(int *p,int k){ // FUNÇÃO SELECTION!.
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
int v[] ={7,3,-1,12,9,6};
int n =6;

mostraVetor(v,n);

ordena(v,n);
printf("\n--------------------------------------------\n\n");
mostraVetor(v,n);
return 0;
}

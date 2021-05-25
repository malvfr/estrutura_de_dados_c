#include <stdio.h>
#include <stdlib.h>

void leVetor(int *v,int k){
int i;
for(i=0;i<k;i++){
    printf("Digite %dº :",i+1);
    scanf("%d",&v[i]);
 }
}

void mostra(int *v,int k){
int *x=v+k;
while(v<x){
    printf("%d\n",*v);
    v++;
 }
}

void inverteVetor(int *v,int k){
int *p1 = v;
int *p2 = v+k-1;
while(p1<p2){
  int aux=*p1;
  *p1=*p2;
  *p2=aux;
  p1++;
  p2--;
}
}

int main(){
int n;
printf("Digite o tamanho: ");
scanf("%d",&n);
int *p;
p= malloc(sizeof(int)*n);
leVetor(p,n);
inverteVetor(p,n);
mostra(p,n);
free(p);

return 0;
}

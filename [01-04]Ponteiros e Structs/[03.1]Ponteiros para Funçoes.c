#include <stdlib.h>
#include <stdio.h>


int soma(int x,int y){
return x+y;
} // função soma.

int sub(int x,int y){
return x-y;
} // função subtração.

int main(){

int a,b,op;
printf("Digite dois numeros: ");
scanf("%d",&a);
scanf("%d",&b);

printf("Escolha, 1 para soma, 2 para sub.\n");
scanf("%d",&op);

int(*p)(int,int); // *p entre parenteses para ser um ponteiro de funções, e os tipos dos parametros.

switch(op){

case 1:
    p=soma;
    break;
case 2:
    p=sub;
    break;
default:
    printf("ERRRRROOOU!!");
    break;
}

int c = p(a,b);
printf("\n%d\n",c);

return 0;
}



#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nome[50];
char curso[50];
int fase;
float mediaFinal;
}Aluno; // Tipo da struct Aluno == int...


int main(){
    int i; // aux para o for.
//Aluno **v = malloc(sizeof(Aluno*)*n); Ponteiro para ponteiro [Aluno'*'].
Aluno *v = malloc(sizeof(Aluno)*3); // alocação da memoria para o vetor de estruturas, usando o ponteiro *v.

for(i=0;i<3;i++){
        // v[i] = malloc(sizeof(Aluno*)*n); Alocação de Aluno* <- * para afirmar sem um ponteiro
        // Desta maneira, alocando o espaço para o ponteiro, e não a struct.
        // Colocar dentro do for para fazer um ciclo onde exista um vetor de ponteiro alocados em **v.
        // Necessario trocar os '.' por setas '->'.
    printf("Digite o nome do aluno: ");
    gets(v[i].nome); // gets na string do nome;
     setbuf(stdin,NULL); // NULL para retirar o bug do gets.
    printf("Digite o curso do aluno: ");
    gets(v[i].curso); // De ponteiro para ponteiro, trocar para seta -> {v[i]->curso}
    setbuf(stdin,NULL);
    printf("Digite a fase do aluno: ");
    scanf("%i", &v[i].fase);
    printf("Digite a media final do aluno: ");
    scanf("%f",&v[i].mediaFinal); // usar & (E comercial), para recolher dados inteiros ou floats.
    setbuf(stdin,NULL);
}
printf("\n");
for(i=0;i<5;i++){
        if(v[i].mediaFinal <7){
            printf("%O aluno %s, da fase %d ficou em exame com media: %.2f\n", v[i].nome,v[i].fase,v[i].mediaFinal);
        } // for com um if para verificar as notas, e assim imprimir o nome, fase e media do aluno em exame.
}
free(v); // liberar o ponteiro, para liberar o espaço da memoria.
return 0; //fim do exercicio.
}

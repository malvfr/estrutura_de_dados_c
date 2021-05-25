#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"

int f_mostra(LDE *sub, void(*mostra)(void*));


int main() {
	
	LDE *principal = malloc(sizeof(LDE));

	IniciaLista(principal, sizeof(LDE));

	
	int quantidade = 0;
	puts("Digite a quantidade de numeros");
	scanf("%d", &quantidade);

	for (int i = 0; i < quantidade; i++)
	{
		LDE *sub = malloc(sizeof(LDE));
		IniciaLista(sub, sizeof(LDE));

		char numero[1000];
		scanf("%s", numero);
		inicializa_numero(sub,numero);
		insereFim(principal, sub);		
		printf("\n");
	}	
		

	//MAIOR DOS NUMEROS
	int maior = 0;
	for (int x = 0; x < principal->quantidade_elementos; x++) {		
		if (compara_numeros(principal,x,maior) >= 0)
			maior = x;
		else 
			continue;
	}

	//MENOR DOS NUMEROS

	int menor = 0;
	for (int x = 0; x < principal->quantidade_elementos; x++) {
		if (compara_numeros(principal, x, menor) <= 0)
			menor = x;
		else
			continue;
	}

	printf("\nO maior numero e :");
	mostra_numero(principal, maior, mostra_int);
	printf("\nO menor numero e :");
	mostra_numero(principal, menor, mostra_int);		
	
	
	
	printf("\n");
	
	/*SOMA

	for (int i = 0; i < principal->quantidade_elementos-1; i++) {
		printf("\nAdicionando numero %d com %d :  ", i + 1, i + 2);		
		f_mostra(adiciona(principal, i, i + 1), mostra_int);
	}

	printf("\n");
		
	// MULT
	printf("\n");
	
	for (int i = 0; i < principal->quantidade_elementos -1 ; i++) {
		printf("\nMultiplicando numero %d com %d :  ", i + 1, i + 2);
		
		if(compara_numeros(principal,i,i+1) <= 0)
		f_mostra(multiplica(principal,i,i+1),mostra_int);	
		else
		f_mostra(multiplica(principal,i+1,i), mostra_int);
	}	
	
	
	//DIVIDE
	printf("\n");
	for (int i = 0; i < principal->quantidade_elementos - 1; i++) {
		
		printf("\nDividindo numero %d com %d :  ", i + 1, i + 2);
		if (compara_numeros(principal, i + i, i) < 0)
			continue;
		else
			f_mostra(divide(principal, i, i + 1),mostra_int);
		
	}
	

	//potencia

	for (int i = 0; i < principal->quantidade_elementos - 1; i++) {
		printf("\nPotencia numero %d com %d :  ", i + 1, i + 2);
		f_mostra(potencia(principal, i, i + 1), mostra_int);
	}

	
	printf("\n");


	//SUBT

	for (int i = 0; i < principal->quantidade_elementos - 1; i++) {
		printf("\nSubtraindo numero %d com %d :  ", i + 1, i + 2);
		if (subtrai(principal, i, i + 1) == ERRO_NUMERO_NEGATIVO) {
			// printf("NEGATIVO");
		
		}
		//f_mostra(subtrai(principal, i, i + 1), mostra_int);
	}
	*/


	printf("\n\nAdiciona 1 e 2\n");
	f_mostra(adiciona(principal,0,1), mostra_int);
	printf("\n\nAdiciona 2 e 3\n");
	f_mostra(adiciona(principal, 1,2), mostra_int);
	
	printf("\n\nDivide 1 e 2\n");
	f_mostra(divide(principal,0,1), mostra_int);
	printf("\n\nDivide 2 e 3\n");
	f_mostra(divide(principal, 1, 2), mostra_int);
	printf("\n\nPotencia 1 e 2\n");
	f_mostra(potencia(principal,0,1), mostra_int);
	printf("\n\nPotencia 2 e 3 \n");
	f_mostra(potencia(principal, 1, 2), mostra_int);
	printf("\n\nMultiplicacao 1 e 2\n");
	f_mostra(multiplica(principal, 0, 1), mostra_int);
	printf("\n\nMultiplicacao 2 e 3\n");
	f_mostra(multiplica(principal, 1, 2), mostra_int);

	printf("\n\nSubtrai 1 e 2\n");
	f_mostra(subtrai(principal, 0, 1), mostra_int);
	printf("\n\nSubtrai 2 e 3\n");
	f_mostra(subtrai(principal, 1, 2), mostra_int);

	printf("\n");
	system("pause");
	
	return 0;
}

int f_mostra(LDE *sub, void(*mostra)(void*))

{
	ElementoDuplo *p = sub->cabeca;

	if (ListaVazia(sub) == TRUE) return ERRO_LISTA_VAZIA;

	int qtd = sub->quantidade_elementos;


	while (p != NULL)
	{
		if (qtd % 3 != 0) mostra(p->info);
		else
			if (p->ant == NULL) mostra(p->info);
			else
				printf(".%d", *(int*)p->info);

		qtd--;
		p = p->proximo;
	}
	return 1;
}

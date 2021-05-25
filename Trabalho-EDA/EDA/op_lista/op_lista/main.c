#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "op_lista.h"

int main() {
	
	LDE *principal = malloc(sizeof(LDE));

	IniciaLista(principal, sizeof(LDE));

	puts("Digite a quantidade de numeros");
	
	for (int i = 0; i < 2; i++)
	{
		LDE *sub = malloc(sizeof(LDE));
		IniciaLista(sub, sizeof(LDE));

		char numero[1000];
		scanf("%s", numero);
		inicializa_numero(sub,numero);
		insereFim(principal, sub);			
		printf("\n");
	}	
		
	/* O CARA EH BOM, O CARA SABE
	//MAIOR DOS NUMEROS
	int maior = 0;
	for (int x = 0; x < principal->quantidade_elementos-1; x++) {		
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
		
	
	printf("%d maior",maior+1);
	printf("\n%d menor",menor + 1);
	*/

	mostraLista(principal, potencia(principal, 0, 1));
	
	printf("\n");
	system("pause");

		
	return 0;
}


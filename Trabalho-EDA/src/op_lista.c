#include "op_lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int verifica_caracteres(char *num)
{
	/*Verificar caracter por caracter para ver se n tem nenhuma letra ou carac invalido
	se houver,retornar erro
	*/

	int i = 0;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (isdigit(num[i]) == FALSE)
			return FALSE;
	}
		
	return TRUE; // OK;
}

int compara_numeros(LDE * l1, int pos1, int pos2)
{
	/*Compara digito a digito -1 se pos1 < pos 2
							   1 se pos1 > pos 2
							   0 se pos1 == pos2
	*/

	LDE *A,*B;
	A = malloc(sizeof(LDE));
	B = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));

	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);

	ElementoDuplo *p = A->cabeca;
	ElementoDuplo *z = B->cabeca;		
	
	//Testar se os digitos sao iguais
	int cont = A->quantidade_elementos;
	if (A->quantidade_elementos == B->quantidade_elementos) {
		while (p != NULL & z != NULL)
		{
			int _a = 0;
			int _b = 0;

			memcpy(&_a, p->info, sizeof(int));
			memcpy(&_b, z->info, sizeof(int));

			if (_a == _b) {
				cont--;
				p = p->proximo;
				z = z->proximo;
			}
			else {
				break;
			}
			if (cont == 0)				
				return 0; //iguais
			
		}

		/*Se a quantiadde de digitos for igual,mas os digitos forem diferentes
		 Voltar os ponteiros no começo,verificar A e B                                  */

		ElementoDuplo *p = A->cabeca;
		ElementoDuplo *z = B->cabeca;

		while (p != NULL & z != NULL)
		{
			int _a = 0;
			int _b = 0;

			memcpy(&_a, p->info, sizeof(int));
			memcpy(&_b, z->info, sizeof(int));

			if (_a == _b) {
				p = p->proximo;
				z = z->proximo;
				
			}
			else 
				if (_a < _b) 					
					return -1; // pos 1 < pos 2
				else 					
					return 1; //pos 1 > pos 2
				
			}
			
		}

	if (A->quantidade_elementos > B->quantidade_elementos) {
		//limpa_lista(A); free(A);
		// limpa_lista(B); free(B);
		return 1; //como pos1 tem mais digitos,é maior
	} 
	else {
		 free(A);
		 free(B);
		return -1;
	}
	}

int f_comp(LDE *A, LDE *B){
	
	ElementoDuplo *p = A->cabeca;
	ElementoDuplo *z = B->cabeca;

	//Testar se os digitos sao iguais
	int cont = A->quantidade_elementos;
	if (A->quantidade_elementos == B->quantidade_elementos) {
		while (p != NULL & z != NULL)
		{
			int _a = 0;
			int _b = 0;

			memcpy(&_a, p->info, sizeof(int));
			memcpy(&_b, z->info, sizeof(int));

			if (_a == _b) {
				cont--;
				p = p->proximo;
				z = z->proximo;
			}
			else {
				break;
			}
			if (cont == 0)
				return 0; //iguais

		}

		/*Se a quantiadde de digitos for igual,mas os digitos forem diferentes
		Voltar os ponteiros no começo,verificar A e B                                  */

		ElementoDuplo *p = A->cabeca;
		ElementoDuplo *z = B->cabeca;

		while (p != NULL & z != NULL)
		{
			int _a = 0;
			int _b = 0;

			memcpy(&_a, p->info, sizeof(int));
			memcpy(&_b, z->info, sizeof(int));

			if (_a == _b) {
				p = p->proximo;
				z = z->proximo;

			}
			else
				if (_a < _b)
					return -1; // pos 1 < pos 2
				else
					return 1; //pos 1 > pos 2

		}

	}

	if (A->quantidade_elementos > B->quantidade_elementos) return 1; //como pos1 tem mais digitos,é maior
	else return -1;

}



LDE *adiciona(LDE *l1,int pos1,int pos2){
	
	if (pos1 == pos2) return ERRO_POSICAO_INVALIDA;
	if ((pos1 < 0) || (pos2 < 0)) return ERRO_POSICAO_INVALIDA;

	/*Chegar até o final da L1 e L2 - OK

	igualar numero de digitos inserindo 0 no começo - OK

	adicionar info das listas junto com sobra - incompleto

	criar um Elemento para cada soma de l1 e l2 (junto com a sobra) e inserir no inicio da lista; - Incompleto
	*/
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));

	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);

	if (A->quantidade_elementos == 0 || B->quantidade_elementos == 0) {
		puts("Alguma lista esta vazia ou invalida");
		return ERRO_LISTA_VAZIA;
	}

	/*Pegar a diferença de digitos entre as listas e adicionar zero no começo da lista menor*/
	int dif = A->quantidade_elementos - B->quantidade_elementos;
	if (dif < 0) dif = dif * -1;

	
	for (int i = 0;i < dif;i++)
	{
		if (A->quantidade_elementos > B->quantidade_elementos) 
		     { int info = 0; insereInicio(B, &info); }
		else 
		     { int info = 0; insereInicio(A, &info); }
	}	
	
    /*Criar a lista resultante*/

	LDE *lista_resultante = malloc(sizeof(LDE));
	IniciaLista(lista_resultante, sizeof(LDE));	
	
	ElementoDuplo *p = A->cabeca;	//A = pos1, B = pos2
	ElementoDuplo *z = B->cabeca;	
	
	//chegar no ultimo elemento de cada lista
	while ((p->proximo != NULL) && (z->proximo != NULL))
	{			
		p = p->proximo;
		z = z->proximo;		
	}
		
	//somar de tras para frente e add na resultante
	int sobra_soma, soma = 0;
	int a, b = 0;

	while ((p != NULL) && (z != NULL))
	{
	    
		memcpy(&a, p->info, sizeof(int));
		memcpy(&b, z->info, sizeof(int));

		soma = a + b;
			
		if (soma < 10) {
			insereInicio(lista_resultante, &soma);
		}
	
		else {
			sobra_soma = soma - 10;			
			insereInicio(lista_resultante, &sobra_soma);	

			if (z->ant != NULL) {
				int zant = 0;
				memcpy(&zant, z->ant->info, sizeof(int));
				int adc = 1 + zant;
				memcpy(z->ant->info, &adc, sizeof(int));
			}
						
			else {  			
				soma = 1;
				insereInicio(lista_resultante, &soma);
			}
		}
		
		z = z->ant;
		p = p->ant;
	}			
	
	
	return lista_resultante;
}

LDE *f_adc(LDE *A, LDE *B) {
	

	/*Pegar a diferença de digitos entre as listas e adicionar zero no começo da lista menor*/
	int dif = A->quantidade_elementos - B->quantidade_elementos;
	if (dif < 0) dif = dif * -1;


	for (int i = 0; i < dif; i++)
	{
		if (A->quantidade_elementos > B->quantidade_elementos)
		{
			int info = 0; insereInicio(B, &info);
		}
		else
		{
			int info = 0; insereInicio(A, &info);
		}
	}

	/*Criar a lista resultante*/

	LDE *lista_resultante = malloc(sizeof(LDE));
	IniciaLista(lista_resultante, sizeof(LDE));

	ElementoDuplo *p = A->cabeca;	//A = pos1, B = pos2
	ElementoDuplo *z = B->cabeca;

	//chegar no ultimo elemento de cada lista
	while ((p->proximo != NULL) && (z->proximo != NULL))
	{
		p = p->proximo;
		z = z->proximo;
	}

	//somar de tras para frente e add na resultante
	int sobra_soma, soma = 0;
	int a, b = 0;

	while ((p != NULL) && (z != NULL))
	{

		memcpy(&a, p->info, sizeof(int));
		memcpy(&b, z->info, sizeof(int));

		soma = a + b;

		if (soma < 10) {
			insereInicio(lista_resultante, &soma);
		}

		else {
			sobra_soma = soma - 10;
			insereInicio(lista_resultante, &sobra_soma);

			if (z->ant != NULL) {
				int zant = 0;
				memcpy(&zant, z->ant->info, sizeof(int));
				int adc = 1 + zant;
				memcpy(z->ant->info, &adc, sizeof(int));
			}

			else {
				soma = 1;
				insereInicio(lista_resultante, &soma);
			}
		}

		z = z->ant;
		p = p->ant;
	}


	return lista_resultante;
}

LDE *subtrai(LDE * l1, int pos1, int pos2)
{
	/*Chegar ate o fim das listas,contar a diferença entre digitos,adicionar zeros
	  subtrair os digitos e colocá-los no início da resultante */

	if (pos1 == pos2) return ERRO_POSICAO_INVALIDA;
	if ((pos1 < 0) || (pos2 < 0)) return ERRO_POSICAO_INVALIDA;
	
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));
	
	

	LDE *zero = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));
	
	
	IniciaLista(zero, sizeof(int));	

	int _zero = 0;
	insereInicio(zero, &_zero);

	leNaPosicao(l1,A, pos1);
	leNaPosicao(l1,B, pos2);



	if (A->quantidade_elementos == 0 || B->quantidade_elementos == 0) {
		puts("Alguma lista esta vazia ou invalida");
		return ERRO_LISTA_VAZIA;
	}

	/*Guardar a quantidade de elementos antes de igualar as listas*/
	int temp_a, temp_b = 0;

	temp_a = A->quantidade_elementos;
	temp_b = B->quantidade_elementos;

	if (temp_a < temp_b) return zero;

	/*Pegar a diferença de digitos entre as listas e adicionar zero no começo da lista menor*/
	int dif = A->quantidade_elementos - B->quantidade_elementos;
	if (dif < 0) dif = dif * -1;


	for (int i = 0; i < dif; i++)
	{
		if (A->quantidade_elementos > B->quantidade_elementos)
		{
			int info = 0; insereInicio(B, &info);
		}
		else
		{
			int info = 0; insereInicio(A, &info);
		}
	}

	/*Criar a lista resultante*/

	LDE *lista_resultante = malloc(sizeof(LDE));
	IniciaLista(lista_resultante, sizeof(LDE));

	ElementoDuplo *p = A->cabeca;
	ElementoDuplo *z = B->cabeca;

	/*Desse modo,P sempre será a de cima*/
	if (temp_a > temp_b) {
		ElementoDuplo *p = A->cabeca;
		ElementoDuplo *z = B->cabeca;
	}
	else {
		ElementoDuplo *p = B->cabeca;
		ElementoDuplo *z = A->cabeca;
	}

	//chegar no ultimo elemento de cada lista
	while ((p->proximo != NULL) && (z->proximo != NULL))
	{
		p = p->proximo;
		z = z->proximo;
	}

	//Subtrair

	int a, b, resto= 0;

	while (p != NULL && z != NULL)
	{
		memcpy(&a, p->info, sizeof(int));
		memcpy(&b, z->info, sizeof(int));

		resto = a - b;

		if (resto >= 0) insereInicio(lista_resultante, &resto);

		else {
			if (p->ant != NULL) {
				int pant = 0;
				memcpy(&pant, p->ant->info, sizeof(int));

				pant -= 1;

				memcpy(p->ant->info, &pant, sizeof(int));

				a += 10;

				resto = a - b;

				insereInicio(lista_resultante, &resto);
			}
		}

		if (p->ant == NULL) //a mágica do mestre Matheus
			if (a - b < 0) return zero;				
		
		p = p->ant;
		z = z->ant;
	}
		
	
	return lista_resultante;
	
}

LDE *f_subt(LDE *l1, LDE *l2){		
	

	/*Guardar a quantidade de elementos antes de igualar as listas*/
	int temp_a, temp_b = 0;

	temp_a = l1->quantidade_elementos;
	temp_b = l2->quantidade_elementos;

	if (temp_a < temp_b) return ERRO_NUMERO_NEGATIVO;

	/*Pegar a diferença de digitos entre as listas e adicionar zero no começo da lista menor*/
	int dif = l1->quantidade_elementos - l2->quantidade_elementos;
	if (dif < 0) dif = dif * -1;


	for (int i = 0; i < dif; i++)
	{
		if (l1->quantidade_elementos > l2->quantidade_elementos)
		{
			int info = 0; insereInicio(l2, &info);
		}
		else
		{
			int info = 0; insereInicio(l1, &info);
		}
	}

	/*Criar a lista resultante*/

	LDE *lista_resultante = malloc(sizeof(LDE));
	IniciaLista(lista_resultante, sizeof(LDE));

	ElementoDuplo *p = l1->cabeca;
	ElementoDuplo *z = l2->cabeca;

	/*Desse modo,P sempre será a de cima*/
	if (temp_a > temp_b) {
		ElementoDuplo *p = l1->cabeca;
		ElementoDuplo *z = l2->cabeca;
	}
	else {
		ElementoDuplo *p = l2->cabeca;
		ElementoDuplo *z = l1->cabeca;
	}

	//chegar no ultimo elemento de cada lista
	while ((p->proximo != NULL) && (z->proximo != NULL))
	{
		p = p->proximo;
		z = z->proximo;
	}

	//Subtrair

	int a, b, resto = 0;

	while (p != NULL && z != NULL)
	{
		memcpy(&a, p->info, sizeof(int));
		memcpy(&b, z->info, sizeof(int));

		resto = a - b;

		if (resto >= 0) insereInicio(lista_resultante, &resto);

		else {
			if (p->ant != NULL) {
				int pant = 0;
				memcpy(&pant, p->ant->info, sizeof(int));

				pant -= 1;

				memcpy(p->ant->info, &pant, sizeof(int));

				a += 10;

				resto = a - b;

				insereInicio(lista_resultante, &resto);
			}
		}

		if (p->ant == NULL)
			if (a - b < 0) return ERRO_NUMERO_NEGATIVO;

		p = p->ant;
		z = z->ant;
	}

		
	return lista_resultante;
}

LDE *multiplica(LDE *l1, int pos1, int pos2){
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));
	LDE *resultante = malloc(sizeof(LDE));
	LDE *um = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));
	IniciaLista(resultante, sizeof(int));
	IniciaLista(um, sizeof(int));
	int _um = 1;
	insereInicio(um, &_um);

	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);
	
	
	while (f_comp(B, um) != -1) {
		B = f_subt(B, um);
		resultante = f_adc(A, resultante);		
	}	

	free(A); free(B); free(um);
	return resultante;
}

LDE *f_mult(LDE *A, LDE *B) {
	
	LDE *resultante = malloc(sizeof(LDE));
	LDE *um = malloc(sizeof(LDE));


	IniciaLista(resultante, sizeof(int));
	IniciaLista(um, sizeof(int));

	int _um = 1;
	insereInicio(um, &_um);


	int cont = 0;

	while (f_comp(B, um) != -1) {
		B = f_subt(B, um);
		resultante = f_adc(A, resultante);
	}

	
	return resultante;

}
LDE *potencia(LDE *l1,int pos1,int pos2)
{
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));
	LDE *resultante = malloc(sizeof(LDE));
	LDE *um = malloc(sizeof(LDE));

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));
	IniciaLista(resultante, sizeof(int));
	IniciaLista(um, sizeof(int));


	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);

	int _um = 1;
	
	insereInicio(um, &_um);
	resultante = A;
	
	while (f_comp(B, um) != 0) {
		B = f_subt(B, um);
		resultante = f_mult(resultante,A);
	}
	
	free(A);
	free(B);
	free(um);
	return resultante;
}
LDE *raiz(LDE *l1,int pos){
	LDE *num = malloc(sizeof(LDE));
	IniciaLista(num,sizeof(int));
	leNaPosicao(l1, num, pos);

	LDE *lista_impar = malloc(sizeof(LDE));
	IniciaLista(lista_impar, sizeof(int));
	int num_impar = 1;
	insereInicio(lista_impar,&num_impar);


	LDE *i_prox = malloc(sizeof(LDE));
	IniciaLista(i_prox, sizeof(int));
	int num_impar_prox = 3;
	insereInicio(i_prox, &num_impar_prox);
	int cont = 0;	

	LDE *l_cont = malloc(sizeof(LDE));
	IniciaLista(l_cont, sizeof(int));	
	
	
	while (f_comp(num,lista_impar) >= 0)
	{			
		
		int i,z = 0;		
		cont++;
		num = f_subt(num, lista_impar);
		
		if (f_comp(num,i_prox) > 0) {
			
			num_impar_prox += 2;
			limpa_lista(i_prox);
			insereFim(i_prox, &num_impar_prox);			
			
		}	
		else break;
		
		num_impar += 2;
		limpa_lista(lista_impar);
		insereInicio(lista_impar,&num_impar);	
		
	}
	
	insereInicio(l_cont,&cont);
	
	return l_cont;
}

LDE *divide(LDE * l1, int pos1, int pos2)
{
	
	LDE *A = malloc(sizeof(LDE));
	LDE *B = malloc(sizeof(LDE));
	LDE *cont = malloc(sizeof(LDE));
	LDE *um = malloc(sizeof(LDE));
	
	

	IniciaLista(A, sizeof(int));
	IniciaLista(B, sizeof(int));

	

	IniciaLista(cont, sizeof(int));
	IniciaLista(um, sizeof(int));
	int _um = 1;
	insereInicio(um, &_um);


	leNaPosicao(l1, A, pos1);
	leNaPosicao(l1, B, pos2);
	

	while (f_comp(A, B) >= 0) {
		cont = f_adc(um,cont);
		A = f_subt(A, B);
	}
	
	printf("\nResto :");
	mostraLista(A, mostra_int);//A contem o resto da divisao
	printf("\n");
		
	return cont; //retorna a parte inteira da divisao
	
}

int mostra_numero(LDE * l1, int pos,void(*mostra)(void*))
{
	LDE *sub = malloc(sizeof(LDE));
	IniciaLista(sub, sizeof(int));
	leNaPosicao(l1, sub, pos);
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

int desaloca(LDE *l1, int pos){
	LDE *sub = malloc(sizeof(LDE));
	IniciaLista(sub, sizeof(int));
	leNaPosicao(l1, sub, pos);

    if (ListaVazia(sub) == TRUE) return ERRO_LISTA_VAZIA;

	limpa_lista(sub);

	modifica_posicao(l1,sub, pos); //insere a lista modificada em l1
	return 0;
}

int inicializa_numero(LDE *l,char *num)
{
	/*Verificar os caracteres
	
	Inserir números no fim da lista

	Fazer a correção da tabela ASCII diminuindo 48 ou '0'

	*/

	if (verifica_caracteres(num) == FALSE) {
		puts("NUMERO INVALIDO");
		return ERRO_NUMERO_INVALIDO;
	}

 	int i = 0;
		
	for  (i = 0;num[i] != '\0';i++){
		int x = num[i] - '0';
		insereFim(l, &x);
	}
		
		
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5
/* Crie um programa que contenha um vetor de inteiros contendo 5 elementos. 
Utilizando apenas aritmética de ponteiros, leia esse vetor do teclado e imprima o 
dobro de cada valor lido */
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int i, vetor[tam];
	int *p = vetor;
	
	printf("\nInsira 5 valores: ");
	printf("\n\n");
	for(i = 0; i < tam; i++)
	{
		printf("%dº valor: ", i+1);
		scanf("%d", &*(p+i));
	}
	
	printf("\nO dobro dos valores digitados: ");
 	for(i = 0; i < tam; i++)
 	{
 		printf("\n Valor %d: %d", i+1, *(p+i) + *(p+i));
	}
	
	return 0;
}

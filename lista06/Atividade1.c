#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define vet 10

/* Faça um programa que preencha um vetor com 10 números reais, calcule e mostre 
a quantidade de números negativos e a soma dos números positivos desse vetor */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int Contnegativo = 0, i = 0;
	float soma = 0, num[vet];
	
	for(i = 0; i < vet; i++)
	{
		printf("Informe o %dº valor (real) da sequência: ", i+1);
		scanf("%f", &num[i]);
		
		if(num[i] < 0)
			{
				Contnegativo++;
			}
		else
		soma += num[i]; 	
	}
	printf("Quantidade de negativos foi: %d", Contnegativo);
	printf("\nA soma dos positivos foi de: %.2f", soma);
	return 0;
}

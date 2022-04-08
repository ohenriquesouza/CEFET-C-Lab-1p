#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Faça um programa que solicite ao usuário o tamanho de um vetor e utilizando 
ponteiros e alocação dinâmica de memória (utilizando malloc), aloque um vetor 
com a quantidade de números inteiros informada pelo usuário. Em seguida, o 
programa deve solicitar preenchimento do vetor e informar:
a. Os números pares digitados;
b. A soma dos números pares digitados;
c. Os números ímpares digitados;
d. A quantidade de números ímpares digitados.
e. O maior número */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	
	int maior = 0, contI = 0, soma = 0, somaI = 0, num = 0, tam = 0, i, *vet;
	
	printf("\nInsira o tamanho do vetor: ");
	scanf("%d", &tam);
	
	vet = (int *)malloc(tam * sizeof(int));
	
	for(i = 0; i < tam; i++)
	{
		printf("\nInforme os números que preencheram o vetor: ");
		scanf("%d", &*(vet+i));
	}
	
	printf("\n(a) - Números pares digitados: ");
	for(i = 0; i < tam; i++)
	{
		if(*(vet+i) % 2 == 0)
		{
			printf("%d ", *(vet+i));
			soma += *(vet+i);
		}
	}
	
	printf("\n(b) - Soma dos pares: ");
	printf("%d", soma);
	
	for(i = 0; i < tam; i++)
	{
		if(*(vet+i) % 2 != 0)
		{
			somaI += *(vet+i);
		}
	}
	printf("\n(c) - Soma dos ímpares: ");
	printf("%d", somaI);
	
	printf("\n(d) - Quantidade de números ímpares digitados: ");
	for(i = 0; i < tam; i++)
	{
		if(*(vet+i) % 2 != 0)
		{		
			contI++;		
		}
	}
	printf("%d", contI);
	
	printf("\n(e) - O maior número digitado: ");
	for(i = 0; i < tam; i++)
	{
		if(*(vet+i) > maior)
		{
			maior = *(vet+i);
		}
	}
	printf("%d", maior);
	return 0;
}

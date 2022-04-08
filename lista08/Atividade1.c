#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHA 4
#define COLUNA 6
/* 
Faça um programa que carregue uma matriz M de ordem 4 x 6 e uma segunda 
matriz N de ordem 6 x 4. calcule e imprima a soma das linhas de M com as 
colunas de N 
*/

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int matrizM[LINHA][COLUNA], matrizN[COLUNA][LINHA];
	int i = 0, j = 0;
	int soma = 0;
	
	for(i = 0; i < LINHA; i++)
	{
		for(j = 0; j < COLUNA; j++)
		{
			printf("Insira os valores da matriz 'M' [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrizM[i][j]);
		}
	}   
  
	printf("\n");
	
	for(i = 0; i < COLUNA; i++)
	{
		for(j = 0; j < LINHA; j++)
		{
			printf("Insira os valores da matriz 'N' [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrizN[i][j]);
		}
	}
	
	for(i = 0; i < LINHA; i++)
	{
		for(j = 0; j < COLUNA; j++)
		{
			soma += matrizM[i][j] + matrizN[j][i];
		}
		printf("\nA soma da linha %d com a coluna %d foi: %d", i+1, i+1, soma);
		soma = 0;
	}	
//	printf("\n%d", somaL);
//	printf("\n%d", somaC);

	return 0;
}

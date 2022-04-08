#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define vet 10

/* Faça um programa que leia dois vetores de 10 números, o primeiro (int)
representando o número de matrícula do aluno e o segundo representando a sua 
nota (float). Encontre o aluno que tirou a menor nota e o que tirou a maior nota.
Por fim, imprima o número de matrícula do aluno que tirou a maior nota, seguido 
de sua nota e o número do aluno que tirou a nota mais baixa, seguida de sua nota.
As posições do vetor são equivalentes. Ou seja, para encontrar a nota 
correspondente ao aluno cujo número de matrícula está armazenado na posição 2, 
basta verificar a posição 2 do vetor de notas */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int i, j, matricula[vet], posicaoMaior, posicaoMenor;
	float nota[vet], maiorNota = 0, menorNota = 0;
	
	for(i = 0; i < vet; i++)
	{
		printf("Informe o número de matrícula do %dº aluno: ", i+1);
		scanf("%d", &matricula[i]);
		printf("Agora, insira a nota do %dº aluno : ", i+1);
		scanf("%f", &nota[i]);
		printf("\n");
	}
	
		maiorNota = nota[i];
		menorNota = nota[0];
		
	for(i = 0; i < vet; i++)
	{
		if ( i ==0 || nota[i] > maiorNota )
		{
			maiorNota = nota[i];
			posicaoMaior = i;			
		}
		
		for(j = 0; j < vet; j++)
	{
			if ( i == 0 || nota[j] < menorNota )
			{
				menorNota = nota[j];
				posicaoMenor = i;
			}
	}
	}
	printf("\nA maior nota foi '%.2f', do aluno de matricula: %d", maiorNota, matricula[posicaoMaior]);
	printf("\nA menor nota foi: '%.2f', do aluno de matricula: %d", menorNota, matricula[posicaoMenor]);	
	return 0;
}

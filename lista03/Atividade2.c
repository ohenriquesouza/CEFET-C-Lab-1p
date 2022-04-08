#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Faça um algoritmo recebe como entrada o número de alunos de uma turma e calcule as 
médias da 1ª e 2ª avaliações de cada aluno e exiba na tela. Faça com que o algoritmo só 
aceite notas válidas (uma nota válida deve pertencer ao intervalo [0,10]). Cada nota 
deve ser validada separadamente. Deve ser impressa a mensagem "Nota inválida" caso 
a nota informada não pertença ao intervalo [0,10]. Ao fim, o programa deve exibir as 
médias da turma na primeira e na segunda avaliação */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	
	int nmAluno, i = 0;
	float nota1, nota2, media1, media2;
	
	printf("\nInforme o número de alunos: ");
	scanf("%d", &nmAluno);
	while(nmAluno > i)
	{
		do
	{
		printf("\nDigite a primeira nota do aluno %d: ", i + 1);
		scanf("%f", &nota1);
		
		if (nota1 < 0 || nota1 > 10)
		{
			printf("Nota inválida, insira um valor entre '0 e 10'.");
		}
		media1 += (nota1) / (nmAluno);
			
	}while(nota1 < 0 || nota1 > 10);
	do
	{
		printf("\nDigite a segunda nota do aluno %d: ", i + 1);
		scanf("%f", &nota2);
		
		if (nota2 < 0 || nota2 > 10)
		{
			printf("Nota inválida, insira um valor entre '0 e 10'.");
		}
		media2 += (nota2) / (nmAluno);
	}while(nota2 < 0 || nota2 > 10);
	i++;
	}
	
	printf("\nMédia dos alunos na primeira prova: %.2f", media1);
	printf("\nMédia dos alunos na segunda prova: %.2f", media2);
	
	return 0;
}

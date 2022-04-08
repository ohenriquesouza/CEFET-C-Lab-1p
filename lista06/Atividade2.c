#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define vet 5

/* Faça um programa que leia um vetor de 5 posições para números reais e, depois, 
um código inteiro. Se o código for zero, finalize o programa; se for 1, mostre o 
vetor na ordem direta; se for 2, mostre o vetor na ordem inversa. Caso, o código 
seja diferente de 1 e 2 escreva uma mensagem informando que o código é inválido.
 */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int  i, j;
	float num[vet], codigo;
	
	for ( i = 0; i < vet; i++)
	{
		printf("Informe o %dº número real da sequência: ", i + 1);
		scanf("%f", &num[i]);
	}
	
	for(i = 0; i < vet; i++)
	{
		printf("\nInsira o código desejado:\n(0)- Para finalizar o programa\n(1)- Para a seqência digitar ser mostrada\n(2)- Para mostrar a sequência em ordem inversa\n ");
		scanf("%f", &codigo);
	
		if ( codigo == 0)
		{
			printf("Programa finalizado.");
			break;
		}
		
		if(codigo == 1)
		{
			printf("A sequência inseria pelo usuário:\n");
			for(j = 0; j < vet; j++)
			{
				printf(" - %.2f\n", num[j]);
			}
		}
		
		if(codigo == 2)
		{
			printf("A sequência inseria pelo usuário em ordem inversa:\n");
			for(j = 4; j >= 0; j--)
			{
				printf(" - %.2f\n", num[j]);
			}
		}
		
		else if ( codigo != 0 && codigo != 1 && codigo != 2)
		{
			printf("Código inválido, tente novamente.");
		}	
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define vet 10

/* Leia um vetor de 10 números e em seguida, ordene-o em ordem decrescente */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int j, i, num[vet], maior_valor = 0, auxiliar = 0, posicao = 0;
	
	for(i = 0; i < vet; i++)
	{
		printf("Insira o %dº número da sequência: ", i +1);
		scanf("%d", &num[i]);
	}
	for ( i = 0; i < vet; i++)
	{
		maior_valor = num[i];
		//printf("\nTeste: %d", maior_valor);
		
		for(j = i + 1; j < vet; j++)
		{
			if ( num[j] > maior_valor )
			{
				maior_valor = num[j];
				posicao = j;
			}
		}
			
		//printf("\nMaiorV: %d\n", maior_valor);
				
		if(maior_valor > num[i])
		{
			auxiliar = num[i];
			num[i] = maior_valor;
			num[posicao] = auxiliar;
			//printf("\nMaiorVcondição: %d", maior_valor);
		}	
	}
	
	printf("\nSequência inserida em ordem decrescente: ");
	
	for(i = 0; i < vet; i++)
	{
		printf("\n- %d", num[i]);	
	}

	return 0;
}

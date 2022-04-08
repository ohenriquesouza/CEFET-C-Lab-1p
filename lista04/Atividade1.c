#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Escreva um programa que leia um número inteiro positivo n e em seguida imprima 
n linhas do chamado Triangulo de Floyd. Para exemplificar, no Triangulo de 
Floyd, para n = 6, temos:
• 1
• 2 3
• 4 5 6
• 7 8 9 10
• 11 12 13 14 15
• 16 17 18 19 20 21
Para n = 7, temos:
• 1
• 2 3
• 4 5 6
• 7 8 9 10
• 11 12 13 14 15
• 16 17 18 19 20 21
• 22 23 24 25 26 27 28 */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	int i,num, x, n = 0;	
	
	printf("Informe um número inteiro e positivo: ");
	scanf("%.0d",&num);
	
	while(num < 0){
		printf("\nNúmero inválido (negativo), por favor, insira um novo valor.\n");
		printf("\nInforme um número inteiro e positivo: ");
		scanf("%d",&num);
	}
	
	for(i = 0; i <= num; i++){
		for(x = 0; x <= i; x++){
			n++;
			
			printf(" %d", n);		
		}
			printf("\n");
	}	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int num, i;
	double soma = 0, soma1, denominador = 0;
	
	printf("Insira o número de termos desejados: ");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++){
		
		denominador = pow(i,i);
		soma += (1/denominador);
		printf("%.0f\n", denominador);
	}
	
	printf("O resultado da soma foi de: %.2lf\n", soma);
	
	
	
	
	
	
	return 0;
}

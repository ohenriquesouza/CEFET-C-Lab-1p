#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	int i, numerador = 1, denominador = 225;
	float soma, variacao;
	
	variacao = (-2);
	soma = numerador / denominador + numerador / denominador;
	for(i = 0; denominador == 1; i++)
	{
		numerador += numerador;
		denominador -= denominador + variacao;
	}
	printf("Somatório igual a: %.2f", soma);
	
	
	
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int num, i = 0;
	double soma = 0, denominador = 1, pi;
	
	printf("Insira o número de termos da série para que o cálculo seja realizado: ");
	scanf("%d", &num);
	
	while(i < num){
		soma += pow(-1 , i) * (1 / pow(denominador, 3));
		denominador += 2;
		i++;
	}
	
	printf("Soma dos termos: %lf\n", soma);
	
	pi = cbrt(soma * 32);
	printf("Valor de pi calculado através da soma foi de: %lf", pi);
	return 0;
}

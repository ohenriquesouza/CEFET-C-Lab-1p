#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double fat(int n)
{
	int i = 0;
	
	double fat = 1;
	for (i = n; i > 1; i--)
	{
		fat = fat * i;
	}	
	return fat;
}
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	double calculo, radiano, num;
	int pote = 1, numI, i = 1; 

	printf("Digite um número real em graus: ");
	scanf("%lf", &num);	
	printf("Digite um número inteiro e positivo: ");
	scanf("%d", &numI);
	
	radiano = (num * M_PI)/180;

	while(numI > i)
	{
		calculo += pow(-1, i) * pow(radiano, pote) / fat(pote);	
		pote+=2;
		i++;
	}
	printf("\nO valor do seno é: %lf", calculo);
	printf("\nSeno de %.0lf° na biblioteca MATH.H é: %lf", num, sin(num));
	printf("\nA diferença entre o valor calculado e o valor da função SIN(X): %lf ", calculo - sin(num));
	return 0;
}

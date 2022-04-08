#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* A s�rie de RICCI difere da s�rie de FIBONACCI porque os dois primeiros termos 
s�o fornecidos pelo usu�rio. Os demais termos s�o gerados da mesma forma que a 
s�rie de FIBONACCI. Criar uma fun��o em c que imprima os N primeiros termos 
da s�rie de RICCI (N ser� fornecido pelo usu�rio) e a soma dos termos impressos, 
sabendo-se que para existir esta s�rie ser�o necess�rios pelo menos tr�s termos. */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	int i = 0, n1 = 0, n2 = 0, n3 = 0,soma = 0, somaT, termos;
	
	printf("Informe o primeiro n�mero: ");
	scanf("%d", &n1);
	printf("Informe o segundo n�mero: ");
	scanf("%d", &n2);
	
	for(i = 0; termos < 3; i++){
		printf("\nDigite o n�mero de termos desejados para o calculo: ");
		scanf("%d", &termos);
		if (termos < 3){
			printf("N�mero inv�lido, favor insira um valor maior que '3'.\n");
		}
	}
	soma = (n1 + n2);
	printf("%d ", n1);
	printf("%d", n2);
	
	for(i = 2; i<termos; i++){
		somaT = (n1 + n2);
		n1 = n2;
		n2 = somaT;
		soma += n2;
		printf(" %d ", n2);	
	}
	printf("\nA soma total dos termos foi de: %d", soma);

	return 0;
}

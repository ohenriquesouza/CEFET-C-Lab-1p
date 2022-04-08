#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	
	int n1, n2, i, escolha = 0;
	float soma, subtracao, multiplicacao, divisao;
	
	printf("Informe dois algarismos: \n");
	scanf("%d %d", &n1, &n2);
	
	for(i = 0; escolha != 5; i++){
		
		printf("\nEscolha qual operação deseja fazer: \n1- Adição\n2- Subtração\n3- Multiplicação\n4- Divisão\n5- Saída. \t");
		scanf("%f", &escolha);
			
			if(escolha == 1){
				soma = (n1 + n2);
				printf("A soma dos dois algarismos é de: %.0f\n", soma);	
			}
			if (escolha == 2){
				subtracao = (n1 - n2);
				printf("A subtração dos dois algarismos é de: %0.f\n", subtracao);
			}
			if (escolha == 3){
				multiplicacao = (n1 * n2);
				printf("A multiplicação dos dois algarismos digitados é de: %.0f\n", multiplicacao);
			}
			if (escolha == 4){
				divisao = (n1 / n2);
				printf("A divisão dos dois algarismos é de: %.0f\n", divisao);
			}
		}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");	
float n1, n2, n3, resultado;
char media;
	
printf("Digite a primeira nota: \n");
scanf("%f", &n1);

printf("Digite a segunda nota: \n");
scanf("%f", &n2);

printf("Digite a terceira nota: \n");
scanf("%f", &n3);

printf ("Informe qual média desejada, Aritmética (A), Ponderada (P) ou Harmônica (H): \n");
scanf(" %c", &media);
media = toupper (media);	
	

if (media == 'A'){
	resultado = ((n1 + n2 + n3)/3);
	
}

else if (media == 'P'){
 	resultado = (((n1 * 3) + (n2 * 3) + (n3 * 4))/ 3 + 3 + 4);
}
	

else if (media == 'H'){
	resultado = ((3)/(1 / n1) + (1 / n2) + (1 / n3));
	
}

printf ("O resultado da média escolhida foi de: %.2f\n", resultado);


	return 0;
}

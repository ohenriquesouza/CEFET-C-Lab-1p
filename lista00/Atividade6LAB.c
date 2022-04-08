#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* CUSTO CONSUMIDOR = Cf + %d + %i  */
/*O custo ao consumidor, de um carro novo, é a soma do custo de fábrica com a 
percentagem do distribuidor e dos impostos (aplicado ao custo da fábrica). Supondo 
que a percentagem do distribuidor seja de 28% e os impostos de 45%, faça um 
algoritmo para ler o custo de fábrica de um carro e escrever o custo ao consumidor*/

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");	
int n1, porD, imp, custo;

printf ("Digite o preço de fábrica: ");
scanf ("%d", &n1);

porD = (n1 * 0.28);
imp = (n1 * 0.45);
custo = (porD + imp + n1);

printf ("Custo final: %d\n", custo);

	
	return 0;
}

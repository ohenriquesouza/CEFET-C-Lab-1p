#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*Leia o raio de um círculo e mostre como saída o perímetro (2*p*Raio) e a área 
(p*Raio2). Considere p=3,14*/

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");	
int n1, perimetro, area;

printf ("Digite o raio: ");
scanf ("%d", &n1);


area = (3.14 * n1*n1);
perimetro = (2 * 3.14 * n1);

printf ("Perímetro do circulo: %d\n", perimetro);
printf ("Área do circulo: %d\n", area);


	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
float n1, n2, n3;

printf ("Digite um número: ");
scanf ("%f", &n2);
	
n1 = (n2 - 1);
n3 = (n2 + 1);
	
printf ("Antecessor e o Sucessor de %.1f : %.1f %.1f ", n2, n1, n3);
	

return 0;
}

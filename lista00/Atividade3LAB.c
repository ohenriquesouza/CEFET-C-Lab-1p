#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");
int n1, n2, quociente, resto;	
	
printf ("Digite dois números: ");
scanf 	("%d %d", &n1, &n2);
	
quociente = (n1 / n2);
resto = (n1 % n2);	
	
printf ("Dividendo: %d\n", n1);	
printf ("Divisor: %d\n", n2);		
printf ("Quociente: %d\n", quociente);
printf ("Resto: %d\n", resto);			
	return 0;
}

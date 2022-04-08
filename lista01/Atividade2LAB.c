#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*A empresa Eficaz resolveu conceder aumento diferenciado para seus 
funcionários de acordo com a tabela abaixo. Faça um algoritmo que leia 
o salário atual de um funcionário. Escreva então o seu salário atual, o 
percentual que receberá de aumento, o valor deste aumento e o novo 
salário    
 >=1000,00 e <1500,00 100%
>=1500,00 e <2500,00 90%
>=2500,00 e <3000,00 80%
>=3000,00 e < 3500,00 70%
>=3500,00 e < 4000,00 60%
>=4000,00 50%  */


int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");	
float atual, percentual, aumento, final;


printf ("Digite seu salário atual: ");
scanf ("%f", &atual);


if (atual >= 1000 && atual <1500){
	percentual = (100);
	aumento = (atual * 1);
	final = (atual + aumento);
}
else if (atual >= 1500 && atual <2500){
	percentual = (90);
	aumento = (atual * 0.90);
	final = (atual + aumento);
}
else if (atual >= 2500 && atual <3000){
	percentual = (80);
	aumento = (atual * 0.80);
	final = (atual + aumento);
}
else if (atual >=3000 && atual <3500){
	percentual = (70);
	aumento = (atual * 0.70);
	final = (atual + aumento);
}
else if (atual >=3500 && atual <4000){
	percentual = (60);
	aumento = (atual * 0.60);
	final = (atual + aumento);
}
else if (atual >=4000){
	percentual = (50);
	aumento = (atual * 0.50);
	final = (atual + aumento);
}


printf ("Salário atual: %.2f\n", atual);
printf ("Percentual do aumento: %.0f%%\n", percentual);
printf ("Total do aumento: %.2f\n", aumento);
printf ("Novo salário: %.2f\n", final);

	
	return 0;
}

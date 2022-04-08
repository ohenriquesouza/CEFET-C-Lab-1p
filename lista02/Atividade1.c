#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Deseja-se fazer uma pesquisa a respeito do consumo mensal de energia 
elétrica em uma determinada cidade. Para isso, são fornecidos os seguintes 
dados:
• preço do kWh consumido;
• número do consumidor;
• quantidade de kWh consumidos durante o mês;
• código do tipo de consumidor (residencial, comercial, industrial).
O número do consumidor igual a zero deve ser usado para interromper a entrada de 
dados. Faça um algoritmo que leia os dados descritos acima e calcule:
a. para cada consumidor, o total a pagar
b. o maior consumo verificado,
c. o menor consumo verificado,
d. o total do consumo para cada um dos três tipos de consumidores,
e. a média geral de consumo;
e escreva:
I. para cada consumidor, o seu número e o total a pagar,
II. o que foi calculado nos itens b, c, d, e acima especificado */

int main(int argc, char *argv[]) {
setlocale (LC_ALL, "portuguese");	
	
float precokwh, nmconsumidor, qntkwh, totalP, i, maiorconsu = 0, menorconsu = 0, consuR = 0, consuC = 0, consuI = 0, media;
char tipoconsu;	

for (i = 0; nmconsumidor != 0; i++){


 printf("\nInforme o preço por kWh consumido: R$ ");
  scanf("%f", &precokwh);
  
 printf("Agora insira seu número de consumidor: "); 
  scanf("%f", &nmconsumidor);
  
  if (nmconsumidor == 0){
	break;
}

 printf("Quantidade de kWh consumido durante o mês: ");
  scanf("%f", &qntkwh);
  
 printf("Por fim, infome o tipo de consumidor \n(R)- Para Residencial\n(C)- Para Comercial\n(I)- Para Industrial\n\t");
  scanf(" %c", &tipoconsu);
  tipoconsu = toupper (tipoconsu);
	
totalP = (precokwh * qntkwh);



if (tipoconsu == 'R'){
	consuR += qntkwh;
}
else if (tipoconsu == 'C'){
	consuC += qntkwh;
}
else if (tipoconsu == 'I'){
	consuI += qntkwh;
}


if (i == 0 || menorconsu > qntkwh){
	   menorconsu = qntkwh;
}

else if ( i == 0 || maiorconsu < qntkwh){
	 maiorconsu = qntkwh;
}

media = ((consuC + consuR + consuI)/ 3);



printf("\nO total a pagar para o consumidor %.0f, de classe '%c' será de: R$%.2f\n\n",nmconsumidor, tipoconsu, totalP);

}
printf("O maior consumo verificado foi de: %.2f\n", maiorconsu);
printf("O menor consumo verificado foi de: %.2f\n", menorconsu);
printf("Total consumo para o tipo 'R': %.2f\n", consuR);
printf("Total consumo para o tipo 'C': %.2f\n", consuC);
printf("Total consumo para o tipo 'I': %.2f\n", consuI);
printf("A média geral do consumo para os três tipos de consumidores foi de: %.2f", media);


	return 0;
}


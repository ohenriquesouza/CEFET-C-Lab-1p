#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*  Uma empresa deseja presentear seus funcionários com um bônus de Natal, cujo valor é definido do seguinte modo: 
a. Funcionários do sexo masculino com tempo de casa superior a 15 anos terão direito a um bônus de 20% do seu salário; 
b. As funcionárias com tempo de casa superior a 10 anos terão direito a um bônus de 25% do seu salário; e 
c. os demais funcionários terão direito a um bônus de R$ 100,00. 
Faça um algoritmo que leia o código do funcionário, o sexo, o tempo de trabalho (em anos) e o salário. O algoritmo deve calcular 
o valor do bônus */

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "portuguese");	

float tempo, bonus, salario;
char sexo;

printf("Digite, por favor seu tempo de serviço: ");
scanf("%f", &tempo);

printf("Agora, indique seu sexo: ");
scanf(" %c", &sexo);
sexo = toupper (sexo);

printf("Insira seu salário: ");
scanf("%f", &salario);



if (sexo == 'M' && tempo  >15){
	bonus = (salario * 0.20 );
}


else if (sexo == 'F' && tempo > 10){
	bonus = (salario * 0.25);
}

	else 
	bonus = 100;

printf("Seu bônus será: %.0f\n", bonus);


	return 0;
}

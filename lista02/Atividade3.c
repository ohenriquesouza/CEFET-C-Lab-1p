#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");


	int i;
	float populacaoMilanos, populacaoBruzun;	
	
	printf("Sabe-se, que a população da República Democrática dos Bruzundangas é de 90 milhões. \n");
	prtinf("Já na União Federalista Do Milanos, a população é de 200 milhões. \n");
	
	populacaoBruzun = 90000000;
	populacaoMilanos = 200000000;
	
	for(i = 0; populacaoBruzun < populacaoMilanos; i++){
		if (populacaoBruzun < populacaoMilanos){
			populacaoBruzun = populacaoBruzun + (populacaoBruzun * 0.03);
			printf("População: %.2f\n", populacaoBruzun);
			
			populacaoMilanos = populacaoMilanos + (populacaoMilanos * 0.015);
			printf("Populacao M: %.2f\n", populacaoMilanos);			
		}	
	}
	
	printf("\nSão necessários %d anos. \n", i);	

	return 0;
}

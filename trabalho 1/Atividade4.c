#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Em um prédio, com N moradores (onde N é fornecido pelo usuário), há três elevadores 
denominados A, B e C. Para otimizar o sistema de controle dos elevadores, foi realizado um 
levantamento no qual cada usuário respondia: 
a) o elevador que utilizava com mais frequência
b) o período que utilizava o elevador, entre: 
i) “M” = matutino; 
ii) “V” = vespertino; 
iii) “N” = noturno. 
Construa um algoritmo que calcule e imprima: 
• qual é o elevador mais frequentado e em que período se concentra o maior fluxo; 
• qual o período mais usado de todos e qual elevador foi mais utilizado nesse período;
• qual a diferença percentual entre o mais usado dos horários e o menos usado; 
• qual a percentagem sobre o total de serviços prestados do elevador de média utilização*/

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	int qnt_moradores, i, op_invalida, elev_a_p_M = 0, elev_a_p_V = 0, elev_a_p_N = 0, elev_b_p_M = 0;
	int elev_b_p_V = 0, elev_b_p_N = 0, elev_c_p_M = 0, elev_c_p_V = 0, elev_c_p_N = 0;
	float  periodo_m_utl = 0, periodo_v_utl = 0, periodo_n_utl = 0, elev_medio_ult = 0, a_utl = 0, b_utl = 0, c_utl = 0;
	float diferenca = 0;
	char frequencia, horadia;
	int elev_mais_utl, elev_periodo_mais_utl, periodo_menos_utl,  periodo_mais_utl, periodo_elev_mais_ult; 

	printf("Por favor, informe quantos moradores a no prédio: ");
	scanf("%d", &qnt_moradores);
	
	
	for(i = 0; i < qnt_moradores; i++){
		do{
		getchar();	
		printf("\nMorador %d, qual elevador você utiliza com mais frequencia? (A, B ou C)\n", i+1);
		scanf("%c", &frequencia);
		
			switch(frequencia){
				case 'A':
					a_utl++;
					op_invalida = 0;
					break;
				case 'B':
					b_utl++;
					op_invalida = 0;
					break;
				case 'C':
					c_utl++;
					op_invalida = 0;
					break;
				default:
					printf("Operação inválida, tente novamente.");
					op_invalida = 1;
					continue;
			}
		}while(op_invalida == 1);
		
		do{
			getchar();
			printf("E em qual período do dia você mais utiliza os elevadores?\n(M)-Matutino\n(V)-Vespertino\n(N)-Noturno\n");
			scanf("%c", &horadia);
			
			switch(horadia){
				case 'M':
					switch(frequencia){
						case 'A':
							elev_a_p_M++;
							break;
						case 'B':
							elev_b_p_M++;
							break;
						case 'C':
							elev_c_p_M++;
							break;
					}
					periodo_m_utl++;
					op_invalida = 0;
					break;
				case 'V':
					switch(frequencia){
						case 'A':
							elev_a_p_V++;
							break;
						case 'B':
							elev_b_p_V++;
							break;
						case 'C':
							elev_c_p_V++;
							break;	
					}
					periodo_v_utl++;
					op_invalida = 0;
					break;
				case 'N':
					switch(frequencia){
						case 'A':
							elev_a_p_N++;
							break;
						case 'B':
							elev_b_p_N++;
							break;
						case 'C':
							elev_c_p_N++;
							break;
					}
					periodo_n_utl++;
					op_invalida = 0;
					break;
				default:
					printf("\nOperação inválida, tente novamente.\n");
					op_invalida = 1;
					continue;
			}
			
		}while(op_invalida == 1);		
		
		if (a_utl > b_utl && a_utl > c_utl){
			elev_mais_utl = 'A';
			
			if(elev_a_p_M > elev_a_p_V && elev_a_p_M > elev_a_p_N){
				periodo_elev_mais_ult = 'M';
			}
			else if(elev_a_p_V > elev_a_p_M && elev_a_p_V > elev_a_p_N){
				periodo_elev_mais_ult = 'V';
			}
			else if(elev_a_p_N > elev_a_p_M && elev_a_p_N > elev_a_p_V){
				periodo_elev_mais_ult = 'N';
			}
		}
		if (b_utl > a_utl && b_utl > c_utl){
			elev_mais_utl = 'B';
			
			if(elev_b_p_M > elev_b_p_V && elev_b_p_M > elev_b_p_N){
				periodo_elev_mais_ult = 'M';
			}
			else if(elev_b_p_V > elev_b_p_M && elev_b_p_V > elev_b_p_N){
				periodo_elev_mais_ult = 'V';
			}
			else if(elev_b_p_N > elev_b_p_M && elev_b_p_N > elev_b_p_V){
				periodo_elev_mais_ult = 'N';
			}
		}
		if(c_utl > a_utl && c_utl > b_utl){
			elev_mais_utl = 'C';
			
			if(elev_c_p_M > elev_c_p_V && elev_c_p_M > elev_c_p_N){
				periodo_elev_mais_ult = 'M';
			}
			else if(elev_c_p_V > elev_c_p_M && elev_c_p_V > elev_c_p_N){
				periodo_elev_mais_ult = 'V';
			}
			else if(elev_c_p_N > elev_c_p_M && elev_c_p_N > elev_c_p_V){
				periodo_elev_mais_ult = 'N';
			}
		}
		if (periodo_m_utl > periodo_v_utl && periodo_m_utl > periodo_n_utl){
			periodo_mais_utl = 'M';
			
			if(elev_a_p_M > elev_b_p_M && elev_a_p_M > elev_c_p_M){
				elev_periodo_mais_utl = 'A';
	
			}
			else if(elev_b_p_M > elev_a_p_M && elev_b_p_M > elev_c_p_M){
				elev_periodo_mais_utl = 'B';
			}
			else if(elev_c_p_M > elev_a_p_M && elev_c_p_M > elev_b_p_M){
				elev_periodo_mais_utl = 'C';
			}
		}
		if (periodo_v_utl > periodo_m_utl && periodo_v_utl > periodo_n_utl){
			periodo_mais_utl = 'V';
			
			if(elev_a_p_V > elev_b_p_V && elev_a_p_V > elev_c_p_V){
				elev_periodo_mais_utl = 'A';
			}
			else if(elev_b_p_V > elev_a_p_V && elev_b_p_V > elev_c_p_V){
				elev_periodo_mais_utl = 'B';
			}
			else if(elev_c_p_V > elev_a_p_V && elev_c_p_V > elev_b_p_V){
				elev_periodo_mais_utl = 'C';
			}
		}
		if (periodo_n_utl > periodo_m_utl && periodo_n_utl > periodo_v_utl){
			periodo_mais_utl = 'N';
			
			if(elev_a_p_N > elev_b_p_N && elev_a_p_N > elev_c_p_N){
				elev_periodo_mais_utl = 'A';
			}
			else if(elev_b_p_N > elev_a_p_N && elev_b_p_N > elev_c_p_N){
				elev_periodo_mais_utl = 'B';
			}
			else if(elev_c_p_N > elev_a_p_N && elev_c_p_N > elev_b_p_N){
				elev_periodo_mais_utl = 'C';
			}
		}
	}
	         //Verificação de dados//
//	printf("Utilizacoes dos elevadores:\n");
//    printf("A: %.0f\n", a_utl);
//    printf("B: %.0f\n", b_utl);
//    printf("C: %.0f\n", c_utl);
//    printf("--------------------------\n");
//
//    printf("Utilizacoes dos periodos:\n");
//    printf("M: %.0f\n", periodo_m_utl);
//    printf("V: %.0f\n", periodo_v_utl);
//    printf("N: %.0f\n", periodo_n_utl);
//    printf("--------------------------\n");
	printf("\n---------------------------------\n");
	printf("\nO elevador mais utilizado foi: ' %c ',\ne o periodo que ele foi mais utilizado, foi: ' %c '\n", elev_mais_utl, periodo_elev_mais_ult);
	printf("O período mais utilizado de todos foi: ' %c ',\ne o elevador mais utilizado nesse período, foi o: ' %c '", periodo_mais_utl, elev_periodo_mais_utl);
	if (periodo_m_utl < periodo_v_utl && periodo_m_utl < periodo_n_utl){
		periodo_menos_utl = 'M';
	}
	else if (periodo_v_utl < periodo_m_utl && periodo_v_utl < periodo_n_utl){
		periodo_menos_utl = 'V';
	}
	else if (periodo_n_utl < periodo_m_utl && periodo_n_utl < periodo_v_utl){
		periodo_menos_utl = 'N';
	}
	
	if (periodo_m_utl > periodo_v_utl && periodo_m_utl > periodo_n_utl && periodo_v_utl <= periodo_n_utl){
		diferenca = ((periodo_m_utl/qnt_moradores) - (periodo_v_utl/qnt_moradores))*100;
	}
	else if (periodo_m_utl > periodo_v_utl && periodo_m_utl > periodo_n_utl && periodo_n_utl <= periodo_v_utl){
		diferenca = ((periodo_m_utl/qnt_moradores) - (periodo_n_utl/qnt_moradores))*100;
	}
	
	else if (periodo_v_utl > periodo_m_utl && periodo_v_utl > periodo_n_utl && periodo_m_utl <= periodo_n_utl){
		diferenca = ((periodo_v_utl/qnt_moradores) - (periodo_m_utl/qnt_moradores))*100;
	}
	else if (periodo_v_utl > periodo_m_utl && periodo_v_utl > periodo_n_utl && periodo_n_utl <= periodo_m_utl){
		diferenca = ((periodo_v_utl/qnt_moradores) - (periodo_n_utl/qnt_moradores))*100;
	}
	else if (periodo_n_utl > periodo_m_utl && periodo_m_utl > periodo_v_utl && periodo_v_utl <= periodo_m_utl){
		diferenca = ((periodo_n_utl/qnt_moradores) - (periodo_v_utl/qnt_moradores))*100;
	}
	else if (periodo_n_utl > periodo_m_utl && periodo_n_utl > periodo_v_utl && periodo_m_utl <= periodo_v_utl){
		diferenca = ((periodo_n_utl/qnt_moradores) - (periodo_m_utl/qnt_moradores))*100;
	}
		
	printf("\nA diferença entre o turno mais usado e o menos usado é: %.0f%%\n", diferenca);
	
	if (a_utl > b_utl && a_utl < c_utl){
		elev_medio_ult = (a_utl/qnt_moradores)*100;
	}
	if (a_utl > c_utl && a_utl < b_utl){
		elev_medio_ult = (a_utl/qnt_moradores)*100;
	}
	if (b_utl > a_utl && b_utl < c_utl){
		elev_medio_ult = (b_utl/qnt_moradores)*100;
	}
	if (b_utl > c_utl && b_utl < a_utl){
		elev_medio_ult = (b_utl/qnt_moradores)*100;
	}
	if (c_utl > a_utl && c_utl < b_utl){
		elev_medio_ult = (c_utl/qnt_moradores)*100;
	}
	if (c_utl > b_utl && c_utl < a_utl){
		elev_medio_ult = (c_utl/qnt_moradores)*100;
	}
	
	if (elev_medio_ult != 0){
		printf("O total de serviços do elevador de média utilização é: %.0f%%\n", elev_medio_ult);
	}else{
		printf("\nNão há elevadores de média utilização.\n");
	}
	return 0;
}

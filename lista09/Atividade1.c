#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define vet 100

/* 
Defina uma Struct que representa um carro. Essa estrutura criada deve permitir 
armazenar: modelo do carro, fabricante, ano de fabricação e consumo (em km/l).
Em seguida, crie um menu que permita:
a) Cadastrar carro
b) Remover carro
c) Listar carros de determinado fabricante 
d) Listar carro mais econômico
e) listar o carro com o maior consumo
f) listar o carro mais novo */

typedef struct
{
	char modelo[40];
	char marca[20];
	int ano;
	int consu;
	
}carro;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int i = 0;
	int cont = 0;
	char remover[40];
	carro lista[vet];
	char opcao;
	int pos = 0;
	int menorano = 0;
	int maiorconsu = 0;
	int menorconsu = 0;
	char busca[20];
	
		do{
			printf("\n-------------------------------------------------------\n");
			printf("\tMenu de escolhas\n");
			printf("\n(A)- Cadastrar novo carro\n(B)- Remover carro cadastrado\n(C)- Pesquisar carro por fabricante\n(D)- Exibir carro mais econômico\n");
			printf("(E)- Exibir carro menos econômico\n(F)- Exibir o carro mais novo\n");
			printf("\n-------------------------------------------------------\n");
			printf("\n\nInsira com qual opção você deseja seguir: ");
			scanf(" %c", &opcao);
			opcao = toupper(opcao);
		
		
			if(opcao == 'A')
			{	
				printf("\n-------------------------------------------------------\n");
				while(i < vet)
				{
					printf("\nInsira o modelo do carro: ");
					fflush(stdin);
					fgets(lista[cont].modelo,40,stdin);
					lista[cont].modelo[strlen(lista[cont].modelo)-1]='\0';
					printf("Informe o fabricante: ");
					fflush(stdin);
					fgets(lista[cont].marca, 20, stdin);
					lista[cont].marca[strlen(lista[cont].marca)-1]='\0';
					printf("Informe o ano de fabricação: ");
					scanf("%d", &lista[cont].ano);
					if(lista[cont].ano < 0)
					{
						break;
					}
					printf("Insira o consumo do carro Km/L: ");
					scanf("%d", &lista[cont].consu);
				cont++;
				break;
				}
			}
			if(opcao == 'B')
			{
				i = 0;
				printf("\n-------------------------------------------------------\n");
				printf("\nInsira o modelo do carro que deseja remover: ");
				fflush(stdin);
				fgets(remover,40,stdin);
				remover[strlen(remover)-1]='\0';
				while(i < vet)
				{
					if(strcmp(remover, lista[i].modelo) == 0 && lista[i].ano > 0)
					{
						printf("\nCarro '%s' removido!", lista[i].modelo);
						lista[i].ano = -1;
						break;
					}
					i++;
				}
				if(i >= vet)
				{
					lista[i].ano = -1;
					printf("\nCarro '%s' removido!", lista[i].modelo);	
				}
			}
			if(opcao == 'C')
			{
				i = 0;
				printf("\n-------------------------------------------------------\n");
				printf("Insira o fabricante para filtrar a busca: ");
				fflush(stdin);
				fgets(busca,20,stdin);
				busca[strlen(busca)-1] = '\0';
				while(i < cont)
				{
					if(strcmp(busca,lista[i].marca) == 0 && lista[i].ano > 0)
					{
						printf("\n");
						printf("\nCarros da fabricante '%s' que constam na lista.", busca);
						printf("\nModelo: %s", lista[i].modelo);
						printf("\nAno de fabricação: %d", lista[i].ano);
						printf("\nConsumo de gasolina por litro: %d", lista[i].consu);
						printf("\n");
					}
					i++;
				}	
			}
			if(opcao == 'D')
			{
				for (i = 0; i < cont; i++)
				{
					if(i == 0 || menorconsu < lista[i].consu && lista[i].ano > 0)
					{
						menorconsu = lista[i].consu;
						pos = i;
					}
				}
				printf("O menor consumo foi %.0fKm/L, do carro '%s'.", menorconsu, lista[pos].modelo);
			}
			if(opcao == 'E')
			{
				for (i = 0; i < cont; i++)
				{
					if(i == 0 || maiorconsu > lista[i].consu && lista[i].ano > 0)
					{
						maiorconsu = lista[i].consu;
						pos = i;
					}
				}
				printf("O maior consumo foi %.0fKm/L, do carro '%s'.", maiorconsu, lista[pos].modelo);
			}
			if(opcao == 'F')
			{
				for (i = 0; i < cont; i++)
				{
					if(i == 0 || menorano < lista[i].ano && lista[i].ano > 0)
					{
						menorano = lista[i].ano;
						pos = i;
					}
				}
				printf("O carro mais novo inserido é '%s'.", lista[pos].modelo);
			}
			if(opcao != 'A' && opcao != 'B' && opcao != 'C' && opcao != 'D' && opcao != 'E' && opcao != 'F')
			{
				printf("\nOpção não idetentificada.");
			}
	}while(opcao == 'A' || opcao == 'B' || opcao == 'C' || opcao == 'D' || opcao == 'E' || opcao == 'F');
	
	
	
	
	
	
	return 0;
}

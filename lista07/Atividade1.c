#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* 
Um palíndromo é uma palavra ou frase que tenha a propriedade de ser a mesma palavra ou 
frase tanto quando ela é lida da direita para a esquerda quanto quando ela é lida da esquerda 
para a direita. Faça um programa que, dada uma string, diga se ela e um palíndromo ou não. 
O programa deve imprimir “É Palíndromo” caso a string seja um palíndromo e “Não é 
palíndromo”, caso não seja. Lembre de tratar a pontuação e acentuação na resolução do 
exercício.
Nos exemplos abaixo, por exemplo, o programa deve retornar que as palavras/frases abaixo 
são palíndromos: 
a. ovo 
b. arara 
c. Socorram-me, subi no ônibus em Marrocos. 
d. Anotaram a data da maratona. 
e. mega bobagem 
*/

int main() 
{
    setlocale(LC_ALL,"portuguese");
    int i = 0,j = 0, cont=0;
    char frase[80], frase2[80];
    
    fflush(stdin);
    printf("Informe a frase a ser testada: ");
    fgets(frase,80,stdin);
    frase[strlen(frase)-1] = '\0';
    
    for(i=0; i < strlen(frase); i++)
	{
    	if(frase[i] != '!' && frase[i] != '?' && frase[i] != ' ' && frase[i] != '.')
        frase2[j++] = frase[i];
    }

    
    for(i = 0; i < ((strlen(frase))/2); i++)
    {
        if(frase[i] != frase[strlen(frase)-1-i])
        {
            cont++;
        }   
    } 
    
    if(cont == (strlen(frase)/2))
    {
        printf("\nA frase inserida não é um palíndromo.");
    } else
    {
        printf("\nA frase inserida é um palídromo.");
    }
             
    return 0;
}

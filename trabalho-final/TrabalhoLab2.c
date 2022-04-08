#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define tamanho 10

typedef struct local{
    int linha;
    int coluna;
};

struct local caca_tesouro (char mat[tamanho][tamanho], int localL, int localC);
struct local retorno_inicio (char mat[tamanho][tamanho], int localL, int localC);
struct local validar_rota (char mat[tamanho][tamanho], int localL, int localC, struct local vet[], int cont);
struct local melhor_rota (char mat[tamanho][tamanho], int localL, int localC, struct local vet[], int cont);

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(65001);

    FILE *p;

    int qntd_Tesouro = 0, rota_aventura = 0,i, j, linhas = 0, colunas = 0, leitura_mapa = 0, aux = 0;
    struct local aventura[1000];
    struct local verifica;
    struct local esconderijo_tesouro;
    struct local retorno_aventura;
    struct local jack_sparrow_local;
    struct local destino_tesouro;
    char nome[30]; 
    char mat[tamanho][tamanho];
    
    printf("\nEntre com o nome do arquivo: ");
    fgets(nome, 30, stdin);
    nome[strlen(nome) -1] = '\0';

    p = fopen(nome, "r");

    if(p == NULL)
    {
        printf("\nArquivo não válido,\n");
        return 0;
    }

    do {
        fscanf (p,"%d %d\n", &linhas, &colunas);
        // printf("\n%d %d", linhas, colunas);
        if(linhas == 0)
        {   
            printf("\nO mapa está rasgado, impossível de se orientrar por ele. Certamente o pirata Davy Jones está por trás disso...\n");
            break;
        }

        for (i = 0; i < linhas; i++)
        {
            fgets (mat[i], colunas + 2, p);
            leitura_mapa = strlen(mat[i]) - 1;
            mat[i][leitura_mapa] = '\0';
        }

        for (i = 0; i < tamanho; i++){
            for (j = 0; j < tamanho; j++){
                if (mat[i][j] == '@'){
                    jack_sparrow_local.linha = i;
                    jack_sparrow_local.coluna = j;
                }
            }
        }
        for (i = 0; i < tamanho; i++){
            for (j = 0; j < tamanho; j++){
                if (mat[i][j] == '~'){
                    mat[i][j] = '0';
                }
                if (mat[i][j] == '#'){
                    mat[i][j] = '0';
                }
                if (mat[i][j] == '*'){
                    mat[i][j] = '0';

                    if (mat[i+1][j] != '*' && mat[i+1][j] == '.'){
                        mat[i+1][j] = '0';
                    }
                    if (mat[i-1][j] != '*' && mat[i-1][j] == '.'){
                        mat[i-1][j] = '0';
                    }

                    if (mat[i][j+1] != '*' && mat[i][j+1] == '.'){
                        mat[i][j+1] = '0';
                    }
                    if (mat[i][j-1] != '*' && mat[i][j-1] == '.'){
                        mat[i][j-1] = '0';
                    }

                    if (mat[i+1][j+1] != '*' && mat[i+1][j+1] == '.'){
                        mat[i+1][j+1] = '0';
                    }

                    if (mat[i+1][j-1] != '*' && mat[i+1][j-1] == '.'){
                        mat[i+1][j-1] = '0';
                    }
                    
                    if (mat[i-1][j+1] != '*' && mat[i-1][j+1] == '.'){
                        mat[i-1][j+1] = '0';
                    }

                    if (mat[i-1][j-1] != '*' && mat[i-1][j-1] == '.'){
                        mat[i-1][j-1] = '0';
                    }
                } 
            }
        }
        for (i = 0; i < tamanho; i++){
            for (j = 0; j < tamanho; j++){
                if (mat[i][j] == '!'){
                    destino_tesouro.linha = i;
                    destino_tesouro.coluna = j;
                    if(mat [destino_tesouro.linha + 1][destino_tesouro.coluna] == '0' && (mat [destino_tesouro.linha - 1][destino_tesouro.coluna]) == '0'&& (mat [destino_tesouro.linha][destino_tesouro.coluna + 1]) == '0' && (mat [destino_tesouro.linha][destino_tesouro.coluna - 1]) == '0' || (mat[destino_tesouro.linha][destino_tesouro.coluna] == '0'))
                    {
                        printf("\nHá boatos que essa ilha esconde tesouros inalcançáveis, nenhum que ousou pisar por essas terras voltou com vida. Jack não quer arriscar e volta para o mar... '-1'");
                        exit(1);
                    }
                    else
                    {
                        qntd_Tesouro++;
                    }
                }
            }  
        }

        if(qntd_Tesouro > 0)
        {
            printf("\nTesouros escondidos na ilha: %d", qntd_Tesouro);
            printf("\nSerá que algum deles será a lendária fonte da Juventude?\n");
            printf("\nJack se encontra nas coordenadas [%d] [%d] do mapa, ele partirá em busca dos tesouros a partir de lá.\n", jack_sparrow_local.linha, jack_sparrow_local.coluna);
            printf("\n-------------------------------------------------");
        }

        else if(qntd_Tesouro <= 0)
        {
            printf("\nTesouros escondidos na ilha: %d :(", qntd_Tesouro);
            printf("\nInfelizmente, esta ilha não possui tesouros escondidos, volte para o mar!");
        }
        do{
            aventura[rota_aventura] = jack_sparrow_local;
            
            if (mat[jack_sparrow_local.linha + 1][jack_sparrow_local.coluna] == '.')
            {
                jack_sparrow_local.linha += 1;  
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '1';
                aventura[rota_aventura] = jack_sparrow_local;
                rota_aventura++;
            }
            else if (mat[jack_sparrow_local.linha - 1][jack_sparrow_local.coluna] == '.')
            {
                jack_sparrow_local.linha -= 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '1';
                aventura[rota_aventura] = jack_sparrow_local;
                rota_aventura++;
            }
            else if (mat[jack_sparrow_local.linha][jack_sparrow_local.coluna + 1] == '.')
            {
                jack_sparrow_local.coluna += 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '1';
                aventura[rota_aventura] = jack_sparrow_local;
                rota_aventura++;
            }
            else if (mat[jack_sparrow_local.linha][jack_sparrow_local.coluna - 1] == '.')
            { 
                jack_sparrow_local.coluna -= 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '1';
                aventura[rota_aventura] = jack_sparrow_local;
                rota_aventura++;
            } 

            esconderijo_tesouro = caca_tesouro(mat, jack_sparrow_local.linha, jack_sparrow_local.coluna);

            if (mat[esconderijo_tesouro.linha][esconderijo_tesouro.coluna] == '!')
            {
                jack_sparrow_local.linha = esconderijo_tesouro.linha;
                jack_sparrow_local.coluna = esconderijo_tesouro.coluna;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '.';
                printf("\nTesouro descoberto em [%d] [%d]!\n", jack_sparrow_local.linha, jack_sparrow_local.coluna);
                printf("\n-------------------------------------------------");
                aventura[rota_aventura] = jack_sparrow_local;
                qntd_Tesouro--;
            }

            verifica = validar_rota(mat, jack_sparrow_local.linha, jack_sparrow_local.coluna, aventura, rota_aventura);
            
            if(verifica.linha == jack_sparrow_local.linha)
            {
                if (verifica.coluna == jack_sparrow_local.coluna){
                    rota_aventura--;
                    mat[aventura[rota_aventura-1].linha][aventura[rota_aventura-1].coluna] = '.';
            }
            }
        }while(qntd_Tesouro > 0);
        // printf("\n%d\n", rota_aventura);
        do{
        
            if (mat[jack_sparrow_local.linha + 1][jack_sparrow_local.coluna] == '1' || mat[jack_sparrow_local.linha + 1][jack_sparrow_local.coluna] == '.')
            {   
                 jack_sparrow_local.linha += 1;
                 mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '0';
                 rota_aventura++;
                    
            }
            else if (mat[jack_sparrow_local.linha - 1][jack_sparrow_local.coluna] == '1' || mat[jack_sparrow_local.linha - 1][jack_sparrow_local.coluna] == '.'){
                jack_sparrow_local.linha -= 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '0';
                rota_aventura++;
            }
            else if (mat[jack_sparrow_local.linha][jack_sparrow_local.coluna + 1] == '1' || mat[jack_sparrow_local.linha][jack_sparrow_local.coluna + 1] == '.'){
                jack_sparrow_local.coluna += 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '0';
                rota_aventura++;
            }
            else if (mat[jack_sparrow_local.linha][jack_sparrow_local.coluna - 1] == '1' || mat[jack_sparrow_local.linha][jack_sparrow_local.coluna - 1] == '.'){
                jack_sparrow_local.coluna -= 1;
                mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] = '0';
                rota_aventura++;
            }  
            retorno_aventura =  retorno_inicio(mat, jack_sparrow_local.linha, jack_sparrow_local.coluna);
        
            if (mat[retorno_aventura.linha][retorno_aventura.coluna] == '@')
            {
                // aux++;
                rota_aventura++;
                jack_sparrow_local.linha = retorno_aventura.linha;
                jack_sparrow_local.coluna = retorno_aventura.coluna;
                printf("\n\nApós todas dificuldades enfrenteadas, Jack Sparrow caminhou por %dKm para ir e voltar em segurança. Viva! Agora Jack pode comemorar com Angelica.\n", rota_aventura);
                rota_aventura = 0;
                printf("\n-------------------------------------------------------------\n");
                // break;
            }
        }while(mat[jack_sparrow_local.linha][jack_sparrow_local.coluna] != '@');
        // if(aux > 0)
        // {
        //     break;
        // }
    }while(linhas > 0);
    fclose(p);
    return 0;
}

struct local caca_tesouro (char mat[tamanho][tamanho], int localL, int localC){
    struct local tesouro;

    tesouro.linha = tamanho + 1;
    tesouro.coluna = tamanho + 1;

    if (mat[localL + 1][localC] == '!')
    {
        tesouro.linha = localL + 1;
        tesouro.coluna = localC;
        mat[localL][localC] = '.';

    }else if (mat[localL - 1][localC] == '!')
    {
        tesouro.linha = localL - 1;
        tesouro.coluna = localC;
        mat[localL][localC] = '.';

    }else if (mat[localL][localC - 1] == '!')
    {
        tesouro.linha = localL;
        tesouro.coluna = localC - 1;
        mat[localL][localC] = '.';

    }else if (mat[localL][localC + 1] == '!')
    {
        tesouro.linha = localL;
        tesouro.coluna = localC + 1;
        mat[localL][localC] = '.';

    }
    return tesouro;
}

struct local retorno_inicio (char mat[tamanho][tamanho], int localL, int localC){
    struct local inicio;

    inicio.linha = tamanho + 1;
    inicio.coluna = tamanho + 1;

    if (mat[localL + 1][localC] == '@')
    {
        inicio.linha = localL + 1;
        inicio.coluna = localC;
        mat[localL][localC] = '1';

    }else if (mat[localL - 1][localC] == '@')
    {
        inicio.linha = localL - 1;
        inicio.coluna = localC;
        mat[localL][localC] = '1';

    }else if (mat[localL][localC + 1] == '@')
    {
        inicio.linha = localL;
        inicio.coluna = localC + 1;
        mat[localL][localC] = '1';

    }else if (mat[localL][localC - 1] == '@')
    {
        inicio.linha = localL;
        inicio.coluna = localC - 1;
        mat[localL][localC] = '1';
    }
    return inicio;
}
struct local validar_rota (char mat[tamanho][tamanho], int localL, int localC, struct local vet[], int cont){
    struct local aventura_certo = vet[cont];

    if (mat[localL][localC] == '1'){
        if (mat[localL - 1][localC] == '0' || mat[localL - 1][localC] == '1'){
            if (mat[localL + 1][localC] == '0' || mat[localL + 1][localC] == '1'){
                if(mat[localL][localC - 1] == '0' || mat[localL][localC - 1] == '1'){
                    if(mat[localL][localC + 1] == '0' || mat[localL][localC + 1] == '1'){
                        mat[localL][localC] = '0';
                        aventura_certo = vet[cont--];
                    }
                }
            }
        }
    }

    return aventura_certo;
}
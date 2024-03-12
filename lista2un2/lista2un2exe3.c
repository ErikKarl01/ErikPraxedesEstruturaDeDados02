#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[15];
    float preco;
}Fruta;


int main(void)
{
    FILE* frutas = fopen("frutas.txt", "w");
    Fruta fruta;
    char condicao_parada[4];

    if (frutas == NULL)
    {
        printf("Erro ao criar arquivo!");
        exit(1);
    }

    while (1)
    {
        printf("Se deseja cadastrar uma fruta digite Sim, senão digite Nao: \n");
        scanf(" %s", condicao_parada);
        
        if (strcmp(condicao_parada, "Sim") == 0)
        {
            printf("Nome da fruta: \n");
            scanf(" %s", fruta.nome);
            printf("Preço da fruta: \n");
            scanf(" %f", &fruta.preco);
            fprintf(frutas, "%s, %f\n", fruta.nome, fruta.preco);
        }
        else if (strcmp(condicao_parada, "Nao") == 0)
        {
            printf("Frutas cadastradas, encerrando programa!");
            break;
        }
        else
            printf("Opcão inválida!");
    }
    fclose(frutas);
    return 0;
}
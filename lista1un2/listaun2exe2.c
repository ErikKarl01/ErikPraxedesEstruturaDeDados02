#include <stdio.h>
#include <stdlib.h>

void calcula_maior_menor(int vet[], int* maior, int* menor, float* media)
{
    *maior = vet[0];
    *menor = vet[0];

    float soma = 0;

    for (int i = 0; i < 10; i++)
    {
        if (*maior < vet[i])
        {
            *maior = vet[i];
        }

        if (*menor > vet[i])
        {
            *menor = vet[i];
        }

        soma += vet[i];
    }

    *media = soma / 2.0;
}

int main(void)
{
    FILE* arquivoEscrita = fopen("arquivoEscrita.txt", "r");
    FILE* arquivoLeitura = fopen("arquivoLeitura.txt", "w");
    int vet[10];
    int maior;
    int menor;
    float media;
    if(arquivoLeitura == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    int i = 0;

    while (i < 10)
    {
        if (fscanf(arquivoEscrita, "%d", &vet[i]) != 1)
        {
            printf("Erro ao ler valor do arquivo!");
            exit(1);
        }
        i++;
    }
    calcula_maior_menor(vet, &maior, &menor, &media);

    fprintf(arquivoLeitura, "menor elemento: %d\n maior elemento: %d\n media: %.2f\n", maior, menor, media);

    fclose(arquivoEscrita);
    fclose(arquivoLeitura);
    return 0;
}
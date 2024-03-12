#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[20];
    float n1;
    float n2;
    float n3;
    float media;
    char situacao[15];
} Aluno;

void calculamedia(Aluno* aluno)
{
    aluno->media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;
    if (aluno->media >= 7)
    {
        strcpy(aluno->situacao , "Aprovado");
    }
    else
    {
        strcpy(aluno->situacao , "Reprovado");
    }
}

int main(void)
{
    Aluno aluno;
    FILE* arquivoLeitura = fopen("arquivoLeitura.txt", "r");
    FILE* arquivoReceber = fopen("arquivoEditar.txt", "a+");

    if (arquivoLeitura == NULL)
    {
        printf("Erro ao abrir arquivo de leitura!\n");
        exit(1);
    }
    if (arquivoReceber == NULL)
    {
        printf("Erro ao abrir arquivo de escrita!\n");
        fclose(arquivoLeitura);
        exit(1);
    }

    while (fscanf(arquivoLeitura, "%s\t%f\t%f\t%f", aluno.nome, &aluno.n1, &aluno.n2, &aluno.n3) != EOF)
    {
        calculamedia(&aluno);
        printf("Nome: %s, Média: %.2f, Situação: %s\n", aluno.nome, aluno.media, aluno.situacao);
        fprintf(arquivoReceber, "%s\t%.2f\t%s\n", aluno.nome, aluno.media, aluno.situacao);
    }

    fclose(arquivoLeitura);
    fclose(arquivoReceber);

    return 0;
}
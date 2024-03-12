#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* notas = fopen("notas.txt", "w");
    int i = 0, n_alunos = 0;
    float nota1, nota2, nota3;
    char nome[50], *linha = NULL;
    size_t tamanho = 0;

    if (notas == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    printf("Escolha uma quantidade de alunos: \n");
    scanf("%d", &n_alunos);

    while (i<n_alunos)
    {
        printf("Aluno %d, digite os dados: \n", i+1);
        printf("Nome: \n");
        scanf(" %[^\n]", nome);
        printf("Nota 1: \n");
        scanf("%f", &nota1);
        printf("Nota 2: \n");
        scanf("%f", &nota2);
        printf("Nota 3: \n");
        scanf("%f", &nota3);

        fprintf(notas, "Nome:\t%s\nNota\t1:\t%f\nNota\t2:\t%f\nNota\t3:\t%f\n\n", nome, nota1, nota2, nota3);
        i++;
    }
    fclose(notas);

    notas = fopen("notas.txt", "r");
    if (notas == NULL)
    {
        printf("Erro!");
        exit(1);
    }

   while (getline(&linha, &tamanho, notas) != -1) {
        printf("%s", linha);
    }
    fclose(notas);
    
    
    return 0;
}
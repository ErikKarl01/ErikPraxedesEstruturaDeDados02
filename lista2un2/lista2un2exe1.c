#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE* funcionarios = fopen("funcionarios.txt", "w");
    int id;
    char nome[50], *linha;
    size_t tamanho;
    float salario;
    int quantidade;
    int i = 0;
    printf("Escolha uma quantidade de funcionarios: \n");
    scanf("%d", &quantidade);

    while (i<quantidade)
    {
        printf("Digite o nome do funcionario: \n");
        scanf(" %[^\n]", nome);
        printf("digite o id do funcionario: \n");
        scanf("%d", &id);
        printf("Digite o salario: \n");
        scanf("%f", &salario);

        fprintf(funcionarios, "Id:\t%d\nNome:\t%s\nSalario:\t%.2f\n\n", id, nome, salario);
        i++;
    }
    fclose(funcionarios);

    funcionarios = fopen("funcionarios.txt", "r");
    if (funcionarios == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

   while (getline(&linha, &tamanho, funcionarios) != -1)
   {
        printf("%s", linha);
   }


    fclose(funcionarios);

    return 0;
}
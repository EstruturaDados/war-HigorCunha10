#include <stdio.h>
#include <string.h>

// 1. Criando a Struct 
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // 2. Criando o vetor para guardar 5 territórios
    Territorio lista[5];
    int i;

    printf("---  CADASTRO DE TERRITÓRIOS --- \n\n");

    // 3. Entrada de Dados 
    for(i = 0; i < 5; i++) {
        printf("Digite o nome do %dº território: ", i + 1);
        scanf("%s", lista[i].nome); // Pega o nome

        printf("Qual a cor do exército: ");
        scanf("%s", lista[i].cor); // Pega a cor

        printf("Quantidade de tropas: ");
        scanf("%d", &lista[i].tropas); // Pega o número

        printf("---------------------------\n");
    }

    // 4. Exibição dos Dados 
    printf("\n---  RELATÓRIO DE CONQUISTAS --- \n");
    for(i = 0; i < 5; i++) {
        printf("\n Território: %s", lista[i].nome);
        printf("\n Cor: %s", lista[i].cor);
        printf("\n Tropas: %d", lista[i].tropas);
        printf("\n---------------------------");
    }

    return 0;
}
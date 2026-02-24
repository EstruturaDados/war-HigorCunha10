#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função de ataque usando ponteiros e a seta ->
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n--- BATALHA: %s vs %s ---\n", atacante->nome, defensor->nome);
    printf("Dado Atacante: %d | Dado Defensor: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Vitoria do atacante! Territorio conquistado.\n");
        strcpy(defensor->cor, atacante->cor); // Muda o dono
        defensor->tropas = atacante->tropas / 2; // Transfere metade das tropas
        atacante->tropas /= 2;
    } else {
        printf("Defesa resistiu! Atacante perdeu 1 tropa.\n");
        if (atacante->tropas > 1) {
            atacante->tropas--;
        }
    }
}

int main() {
    srand(time(NULL));
    int n, i, atq, def;

    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);

    // Alocação dinamica conforme solicitado
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));

    if (mapa == NULL) return 1;

    // Cadastro dos dados
    for (i = 0; i < n; i++) {
        printf("\nTerritorio %d:\n", i);
        printf("Nome: "); scanf("%s", mapa[i].nome);
        printf("Cor: "); scanf("%s", mapa[i].cor);
        printf("Tropas: "); scanf("%d", &mapa[i].tropas);
    }

    // Escolha de alvos 
    printf("\nEscolha o indice do Atacante (0 a %d): ", n - 1);
    scanf("%d", &atq);
    printf("Escolha o indice do Defensor (0 a %d): ", n - 1);
    scanf("%d", &def);

    // Validacao de cor
    if (strcmp(mapa[atq].cor, mapa[def].cor) == 0) {
        printf("Erro: Nao pode atacar seu proprio exercito.\n");
    } else {
        atacar(&mapa[atq], &mapa[def]); // Passa o endereço (ponteiro)
    }

    // Exibicao final
    printf("\n--- ESTADO ATUAL DO MAPA ---\n");
    for (i = 0; i < n; i++) {
        printf("[%s] Cor: %s | Tropas: %d\n", mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    // Desalocação obrigatoria
    free(mapa);

    return 0;
}
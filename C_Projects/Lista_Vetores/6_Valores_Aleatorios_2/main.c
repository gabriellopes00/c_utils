#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 60

int i, j;

void zerarVetor(int vetor[]) {
    for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = -1;
    }
}

void carregarAleatorio(int vetor[]) {
    srand(time(NULL));
    for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 60 + 1;
    }
}

void imprimirVetor(int vetor[]) {
    printf("\nValores carregados:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("Posicao %d: %d\n", i + 1, vetor[i]);
    }
}

void entreValores(int vetor[], int valor1, int valor2) {
    printf("\nValores entre %d e %d:\n", valor1, valor2);
    for (i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor[i] >= valor1 && vetor[i] <= valor2) {
            printf("Posicao %d: %d\n", i + 1, vetor[i]);
        }
    }
}

void exibirRepetidos(int vetor[]) {
    printf("\nValores repetidos:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor[i] != -1) {
            int contagem = 0;
            for (j = i; j < TAMANHO_VETOR; j++) {
                if (vetor[i] == vetor[j]) {
                    contagem++;
                    vetor[j] = -1; // Marcar como processado
                }
            }
            if (contagem > 1) {
                printf("%d = %d\n", vetor[i], contagem);
            }
        }
    }
}

int main() {
    int valores[TAMANHO_VETOR];

    int opcao;
    int valor1, valor2;

    do {
        printf("\n..:: SORTEIO 2 ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar aleatorio\n");
        printf("3. Imprimir\n");
        printf("4. Entre valores\n");
        printf("5. Exibir repetidos\n");
        printf("0. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                zerarVetor(valores);
                printf("Valores zerados.\n");
                break;

            case 2:
                carregarAleatorio(valores);
                printf("Valores carregados aleatoriamente.\n");
                break;

            case 3:
                imprimirVetor(valores);
                break;

            case 4:
                printf("Digite dois valores entre 1 e 60 (separados por espaco): ");
                scanf("%d %d", &valor1, &valor2);
                entreValores(valores, valor1, valor2);
                break;

            case 5:
                exibirRepetidos(valores);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


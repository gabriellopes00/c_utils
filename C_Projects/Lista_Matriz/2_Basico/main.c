#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int i, j;

void carregarMatriz(int matriz[LINHAS][COLUNAS]) {
    printf("Digite os valores para preencher a matriz:\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz carregada com sucesso.\n");
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    printf("\nMatriz:\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int somarMatriz(int matriz[LINHAS][COLUNAS]) {
    int soma = 0;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
    }

    return soma;
}

void zerarMatriz(int matriz[LINHAS][COLUNAS]) {
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }

    printf("Matriz zerada.\n");
}

int main() {
    int matriz[LINHAS][COLUNAS];
    int opcao;

    do {
        printf("\nMENU\n");
        printf("1. Carregar\n");
        printf("2. Imprimir\n");
        printf("3. Somar\n");
        printf("4. Zerar\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarMatriz(matriz);
                break;
            case 2:
                imprimirMatriz(matriz);
                break;
            case 3:
                printf("Soma dos valores na matriz: %d\n", somarMatriz(matriz));
                break;
            case 4:
                zerarMatriz(matriz);
                break;
            case 9:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}


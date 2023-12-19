#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 6

int i, j;

void carregarUsuario(int matriz[LINHAS][COLUNAS]) {
    printf("Digite os valores para preencher a matriz:\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz carregada com sucesso.\n");
}

void carregarAleatorio(int matriz[LINHAS][COLUNAS]) {
    srand(time(NULL));

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 51;  // Números aleatórios entre 0 e 50
        }
    }

    printf("Matriz carregada aleatoriamente.\n");
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    printf("\nMatriz:\n");

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("Endereco: %p\tValor: %d\n", (void*)&matriz[i][j], matriz[i][j]);
        }
    }
}

void imprimirLinhaX(int matriz[LINHAS][COLUNAS], int linha) {
    if (linha >= 0 && linha < LINHAS) {
        printf("\nValores da linha %d:\n", linha);

        for (j = 0; j < COLUNAS; j++) {
            printf("%d\t", matriz[linha][j]);
        }

        printf("\n");
    } else {
        printf("Linha invalida. Tente novamente.\n");
    }
}

int somarLinhaX(int matriz[LINHAS][COLUNAS], int linha) {
    if (linha >= 0 && linha < LINHAS) {
        int soma = 0;

        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[linha][j];
        }

        return soma;
    } else {
        printf("Linha invalida. Retornando 0.\n");
        return 0;
    }
}

void imprimirColunaY(int matriz[LINHAS][COLUNAS], int coluna) {
    if (coluna >= 0 && coluna < COLUNAS) {
        printf("\nValores da coluna %d:\n", coluna);

        for (i = 0; i < LINHAS; i++) {
            printf("%d\n", matriz[i][coluna]);
        }

        printf("\n");
    } else {
        printf("Coluna invalida. Tente novamente.\n");
    }
}

int somarColunaY(int matriz[LINHAS][COLUNAS], int coluna) {
    if (coluna >= 0 && coluna < COLUNAS) {
        int soma = 0;

        for (i = 0; i < LINHAS; i++) {
            soma += matriz[i][coluna];
        }

        return soma;
    } else {
        printf("Coluna invalida. Retornando 0.\n");
        return 0;
    }
}

int somarLinhaXComColunaY(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        int soma = 0;

        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[linha][j];
        }

        for (i = 0; i < LINHAS; i++) {
            soma += matriz[i][coluna];
        }

        return soma;
    } else {
        printf("Linha ou coluna invalida. Retornando 0.\n");
        return 0;
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];
    int opcao, linha, coluna;

    do {
        printf("\nMENU - LINHAS X COLUNAS\n");
        printf("1. Carregar usuario\n");
        printf("2. Carregar aleatorio\n");
        printf("3. Imprimir\n");
        printf("4. Imprimir linha X\n");
        printf("5. Somar linha X\n");
        printf("6. Imprimir coluna Y\n");
        printf("7. Somar linha X com coluna Y\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarUsuario(matriz);
                break;
            case 2:
                carregarAleatorio(matriz);
                break;
            case 3:
                imprimirMatriz(matriz);
                break;
            case 4:
                printf("Digite o numero da linha: ");
                scanf("%d", &linha);
                imprimirLinhaX(matriz, linha);
                break;
            case 5:
                printf("Digite o numero da linha: ");
                scanf("%d", &linha);
                printf("Soma da linha %d: %d\n", linha, somarLinhaX(matriz, linha));
                break;
            case 6:
                printf("Digite o numero da coluna: ");
                scanf("%d", &coluna);
                imprimirColunaY(matriz, coluna);
                break;
            case 7:
                printf("Digite o numero da linha: ");
                scanf("%d", &linha);
                printf("Digite o numero da coluna: ");
                scanf("%d", &coluna);
                printf("Soma da linha %d com coluna %d: %d\n", linha, coluna, somarLinhaXComColunaY(matriz, linha, coluna));
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


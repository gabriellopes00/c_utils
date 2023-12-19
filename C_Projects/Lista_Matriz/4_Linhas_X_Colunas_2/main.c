#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 6

int i, j;

void carregarAleatorio(int matriz[LINHAS][COLUNAS]) {
    srand(time(NULL));

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 51;  
        }
    }

    printf("Matriz carregada aleatoriamente.\n");
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

void somaPorLinha(int matriz[LINHAS][COLUNAS]) {
    printf("\nSoma por linha:\n");

    for (i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: %d\n", i + 1, soma);
    }
}

void somaPorColuna(int matriz[LINHAS][COLUNAS]) {
    printf("\nSoma por coluna:\n");

    for (j = 0; j < COLUNAS; j++) {
        int soma = 0;
        for (i = 0; i < LINHAS; i++) {
            soma += matriz[i][j];
        }
        printf("Coluna %d: %d\n", j + 1, soma);
    }
}

void maiorSomaLinha(int matriz[LINHAS][COLUNAS]) {
    int maiorSoma = 0;
    int linhaMaiorSoma = 0;

    for (i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
        if (soma > maiorSoma) {
            maiorSoma = soma;
            linhaMaiorSoma = i + 1;
        }
    }

    printf("Linha com a maior soma: %d (Soma: %d)\n", linhaMaiorSoma, maiorSoma);
}

void maiorSomaColuna(int matriz[LINHAS][COLUNAS]) {
    int maiorSoma = 0;
    int colunaMaiorSoma = 0;
    
    for (j = 0; j < COLUNAS; j++) {
        int soma = 0;
        for (i = 0; i < LINHAS; i++) {
            soma += matriz[i][j];
        }
        if (soma > maiorSoma) {
            maiorSoma = soma;
            colunaMaiorSoma = j + 1;
        }
    }
    
    if (i < 1 | i > 3 | j < 1 | j > 3){
    	printf("Valores de x e y nao permitidos");
    	return 0;
	}else{
	printf("Coluna com a maior soma: %d (Soma: %d)\n", colunaMaiorSoma, maiorSoma);
	}
}

void maiorSomaLinhaColuna(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha >= 1 && linha <= LINHAS && coluna >= 1 && coluna <= COLUNAS) {
        int somaLinha = 0;
        int somaColuna = 0;

        for (j = 0; j < COLUNAS; j++) {
            somaLinha += matriz[linha - 1][j];
        }

        for (i = 0; i < LINHAS; i++) {
            somaColuna += matriz[i][coluna - 1];
        }

        printf("Soma da linha %d: %d\n", linha, somaLinha);
        printf("Soma da coluna %d: %d\n", coluna, somaColuna);

        if (somaLinha > somaColuna) {
            printf("A linha %d possui a maior soma.\n", linha);
        } else if (somaColuna > somaLinha) {
            printf("A coluna %d possui a maior soma.\n", coluna);
        } else {
            printf("A linha %d e a coluna %d têm a mesma soma.\n", linha, coluna);
        }
    } else {
        printf("Linha ou coluna invalida. Tente novamente.\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];
    int opcao, linha, coluna;

    do {
        printf("\nMENU - LINHAS X COLUNAS 2\n");
        printf("1. Carregar aleatorio\n");
        printf("2. Imprimir todos\n");
        printf("6. Coluna com maior soma\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarAleatorio(matriz);
                break;
            case 2:
                imprimirMatriz(matriz);
                break;
            case 6:
            	maiorSomaColuna(matriz);
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


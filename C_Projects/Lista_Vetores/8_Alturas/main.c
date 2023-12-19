#include <stdio.h>

#define TAMANHO_VETOR 10

int i;

void adicionarAltura(float alturas[], int *quantidade) {
    int posicao;
    float valor;

    printf("Digite a POSICAO onde deseja adicionar a altura (entre 1 e %d): ", TAMANHO_VETOR);
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= TAMANHO_VETOR) {
        printf("Digite o VALOR da altura: ");
        scanf("%f", &valor);

        alturas[posicao - 1] = valor;
        (*quantidade)++;
        printf("Altura adicionada com sucesso.\n");
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", TAMANHO_VETOR);
    }
}

void lerAltura(float alturas[], int quantidade) {
    int posicao;

    printf("Digite a POSICAO do vetor que deseja ler: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= quantidade) {
        printf("Altura na posicao %d: %.2f\n", posicao, alturas[posicao - 1]);
    } else {
        printf("Posicao invalida ou vazia. A posicao deve estar entre 1 e %d.\n", quantidade);
    }
}

void somarAlturas(float alturas[], int quantidade) {
    float soma = 0;

    for (i = 0; i < quantidade; i++) {
        soma += alturas[i];
    }

    printf("Soma das alturas: %.2f\n", soma);
}

void contarAlturasPositivas(float alturas[], int quantidade) {
    int contador = 0;

    for (i = 0; i < quantidade; i++) {
        if (alturas[i] > 0) {
            contador++;
        }
    }

    printf("Quantidade de alturas maiores que zero: %d\n", contador);
}

void contarPosicoesVazias(float alturas[], int quantidade) {
    int contador = TAMANHO_VETOR - quantidade;

    printf("Quantidade de posicoes vazias: %d\n", contador);
}

int main() {
    float alturas[TAMANHO_VETOR] = {0};
    int quantidade = 0;
    int opcao;

    do {
        printf("\nMENU\n");
        printf("1 - Adicionar\n");
        printf("2 - Ler\n");
        printf("3 - Somar\n");
        printf("4 - Contar alturas maiores que zero\n");
        printf("5 - Contar posicoes vazias\n");
        printf("9 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAltura(alturas, &quantidade);
                break;

            case 2:
                lerAltura(alturas, quantidade);
                break;

            case 3:
                somarAlturas(alturas, quantidade);
                break;

            case 4:
                contarAlturasPositivas(alturas, quantidade);
                break;

            case 5:
                contarPosicoesVazias(alturas, quantidade);
                break;

            case 9:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 9);

    return 0;
}


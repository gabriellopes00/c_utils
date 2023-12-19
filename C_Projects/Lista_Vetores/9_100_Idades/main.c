#include <stdio.h>

#define TAMANHO_VETOR 100

int i;

struct Idades {
    int idades[TAMANHO_VETOR];
    int quantidade;
};

void adicionarIdade(struct Idades *pIdades) {
    if (pIdades->quantidade < TAMANHO_VETOR) {
        printf("Digite a idade a ser adicionada: ");
        scanf("%d", &pIdades->idades[pIdades->quantidade]);
        pIdades->quantidade++;
        printf("Idade adicionada com sucesso.\n");
    } else {
        printf("Limite de idades atingido. Impossivel adicionar mais.\n");
    }
}

void adicionarIdadeNaPosicao(struct Idades *pIdades) {
    int posicao, idade;

    printf("Digite a POSICAO onde deseja adicionar a idade (entre 1 e %d): ", TAMANHO_VETOR);
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= TAMANHO_VETOR) {
        if (pIdades->idades[posicao - 1] == 0) {
            printf("Digite a idade a ser adicionada: ");
            scanf("%d", &idade);
            pIdades->idades[posicao - 1] = idade;
            pIdades->quantidade++;
            printf("Idade adicionada com sucesso.\n");
        } else {
            printf("Posicao ocupada. Nao foi possivel adicionar a idade.\n");
        }
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", TAMANHO_VETOR);
    }
}

void imprimirPosicao(struct Idades *pIdades) {
    int posicao;

    printf("Digite a POSICAO do vetor que deseja imprimir: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= pIdades->quantidade) {
        printf("Idade na posicao %d: %d\n", posicao, pIdades->idades[posicao - 1]);
    } else {
        printf("Posicao invalida ou vazia. A posicao deve estar entre 1 e %d.\n", pIdades->quantidade);
    }
}

void imprimirTodas(struct Idades *pIdades) {
    printf("\nTodas as idades cadastradas:\n");
    for (i = 0; i < pIdades->quantidade; i++) {
        printf("Posicao %d: %d\n", i + 1, pIdades->idades[i]);
    }
}

void removerIdadeDaPosicao(struct Idades *pIdades) {
    int posicao;

    printf("Digite a POSICAO do vetor que deseja remover: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= pIdades->quantidade) {
        pIdades->idades[posicao - 1] = 0;
        printf("Idade removida com sucesso.\n");
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", pIdades->quantidade);
    }
}

void removerTodas(struct Idades *pIdades) {
    for (i = 0; i < TAMANHO_VETOR; i++) {
        pIdades->idades[i] = 0;
    }
    pIdades->quantidade = 0;
    printf("Todas as idades removidas com sucesso.\n");
}

void contarIdades(struct Idades *pIdades) {
    printf("Total de idades cadastradas: %d\n", pIdades->quantidade);
}

void somarIdades(struct Idades *pIdades) {
    int soma = 0;

    for (i = 0; i < pIdades->quantidade; i++) {
        soma += pIdades->idades[i];
    }

    printf("Soma das idades: %d\n", soma);
}

void somarIdadesImpares(struct Idades *pIdades) {
    int soma = 0;

    for (i = 0; i < pIdades->quantidade; i++) {
        if (pIdades->idades[i] % 2 != 0) {
            soma += pIdades->idades[i];
        }
    }

    printf("Soma das idades impares: %d\n", soma);
}

void imprimirIdadesPares(struct Idades *pIdades) {
    printf("\nIdades pares cadastradas:\n");
    for (i = 0; i < pIdades->quantidade; i++) {
        if (pIdades->idades[i] % 2 == 0) {
            printf("Posicao %d: %d\n", i + 1, pIdades->idades[i]);
        }
    }
}

int main() {
    struct Idades idades = {0};
    int opcao;

    do {
        printf("\nMENU - IDADES\n");
        printf("1 - Adicionar\n");
        printf("2 - Adicionar Idade na Posicao X\n");
        printf("3 - Imprimir Posicao X\n");
        printf("4 - Imprimir Todas\n");
        printf("5 - Remover Idade da Posicao X\n");
        printf("6 - Remover Todas\n");
        printf("7 - Contar Idades\n");
        printf("8 - Somar Idades\n");
        printf("9 - Somar Idades Impares\n");
        printf("10 - Imprimir Idades Pares\n");
        printf("99 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarIdade(&idades);
                break;

            case 2:
                adicionarIdadeNaPosicao(&idades);
                break;

            case 3:
                imprimirPosicao(&idades);
                break;

            case 4:
                imprimirTodas(&idades);
                break;

            case 5:
                removerIdadeDaPosicao(&idades);
                break;

            case 6:
                removerTodas(&idades);
                break;

            case 7:
                contarIdades(&idades);
                break;

            case 8:
                somarIdades(&idades);
                break;

            case 9:
                somarIdadesImpares(&idades);
                break;

            case 10:
                imprimirIdadesPares(&idades);
                break;

            case 99:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 99);

    return 0;
}


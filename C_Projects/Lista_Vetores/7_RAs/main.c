#include <stdio.h>
#include <stdbool.h>

#define MAX_RAS 10
#define RA_INVALIDO -1

int i;

struct RegistroAcademico {
    int ra;
    // Adicione outros campos conforme necessário
};

void adicionarRA(struct RegistroAcademico ras[], int* quantidade) {
    if (*quantidade < MAX_RAS) {
        printf("Digite o RA a ser adicionado: ");
        scanf("%d", &ras[*quantidade].ra);
        // Adicione aqui a lógica para outros campos do RA, se necessário
        (*quantidade)++;
        printf("RA adicionado com sucesso.\n");
    } else {
        printf("Limite de RA's atingido. Impossível adicionar mais.\n");
    }
}

void removerRA(struct RegistroAcademico ras[], int* quantidade) {
    int raRemover;
    printf("Digite o RA a ser removido: ");
    scanf("%d", &raRemover);

    int posicao = RA_INVALIDO;
    for (i = 0; i < *quantidade; i++) {
        if (ras[i].ra == raRemover) {
            posicao = i;
            break;
        }
    }

    if (posicao != RA_INVALIDO) {
        // Remover o RA movendo os elementos à frente para trás
        for (i = posicao; i < *quantidade - 1; i++) {
            ras[i] = ras[i + 1];
        }
        (*quantidade)--;
        printf("RA removido com sucesso.\n");
    } else {
        printf("RA nao encontrado. Nada foi removido.\n");
    }
}

void imprimirPosicao(struct RegistroAcademico ras[], int quantidade) {
    int raProcurar;
    printf("Digite o RA a ser procurado: ");
    scanf("%d", &raProcurar);

    int posicao = RA_INVALIDO;
    for (i = 0; i < quantidade; i++) {
        if (ras[i].ra == raProcurar) {
            posicao = i;
            break;
        }
    }

    if (posicao != RA_INVALIDO) {
        printf("O RA %d esta na posicao %d.\n", raProcurar, posicao + 1);
    } else {
        printf("O RA %d nao foi encontrado.\n", raProcurar);
    }
}

void imprimirTodos(struct RegistroAcademico ras[], int quantidade) {
    printf("\nTodos os RA's cadastrados:\n");
    for (i = 0; i < quantidade; i++) {
        printf("Posicao %d: %d\n", i + 1, ras[i].ra);
        // Adicione aqui a lógica para outros campos do RA, se necessário
    }
}

void contarRAs(int quantidade) {
    printf("Total de RA's cadastrados: %d\n", quantidade);
}

int main() {
    struct RegistroAcademico ras[MAX_RAS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\nMENU\n");
        printf("1 - Adicionar\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir posicao\n");
        printf("4 - Imprimir todos\n");
        printf("5 - Contar\n");
        printf("9 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRA(ras, &quantidade);
                break;

            case 2:
                removerRA(ras, &quantidade);
                break;

            case 3:
                imprimirPosicao(ras, quantidade);
                break;

            case 4:
                imprimirTodos(ras, quantidade);
                break;

            case 5:
                contarRAs(quantidade);
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


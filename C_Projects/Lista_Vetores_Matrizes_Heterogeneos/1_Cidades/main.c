#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 10
#define TAM_NOME 50

int i, j;

struct Cidade {
    int codigo;
    char nome[TAM_NOME];
    int numHabitantes;
};

void inserirCidade(struct Cidade cidades[], int *numCidades) {
    if (*numCidades < MAX_CIDADES) {
        printf("Digite o codigo da cidade: ");
        scanf("%d", &cidades[*numCidades].codigo);
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", cidades[*numCidades].nome);
        printf("Digite o numero de habitantes: ");
        scanf("%d", &cidades[*numCidades].numHabitantes);
        (*numCidades)++;
        printf("Cidade inserida com sucesso.\n");
    } else {
        printf("Limite de cidades atingido. Impossivel inserir mais.\n");
    }
}

void alterarCidade(struct Cidade cidades[], int numCidades) {
    int codigo;
    printf("Digite o codigo da cidade que deseja alterar: ");
    scanf("%d", &codigo);

    for (i = 0; i < numCidades; i++) {
        if (cidades[i].codigo == codigo) {
            printf("Digite o novo nome da cidade: ");
            scanf(" %[^\n]", cidades[i].nome);
            printf("Digite o novo numero de habitantes: ");
            scanf("%d", &cidades[i].numHabitantes);
            printf("Cidade alterada com sucesso.\n");
            return;
        }
    }

    printf("Cidade nao encontrada.\n");
}

void excluirCidade(struct Cidade cidades[], int *numCidades) {
    int codigo;
    printf("Digite o codigo da cidade que deseja excluir: ");
    scanf("%d", &codigo);

    for (i = 0; i < *numCidades; i++) {
        if (cidades[i].codigo == codigo) {
            for (j = i; j < *numCidades - 1; j++) {
                cidades[j] = cidades[j + 1];
            }
            (*numCidades)--;
            printf("Cidade excluida com sucesso.\n");
            return;
        }
    }

    printf("Cidade nao encontrada.\n");
}

void pesquisarCidade(struct Cidade cidades[], int numCidades) {
    int codigo;
    printf("Digite o codigo da cidade que deseja pesquisar: ");
    scanf("%d", &codigo);

    for (i = 0; i < numCidades; i++) {
        if (cidades[i].codigo == codigo) {
            printf("Codigo: %d\n", cidades[i].codigo);
            printf("Nome: %s\n", cidades[i].nome);
            printf("Numero de habitantes: %d\n", cidades[i].numHabitantes);
            return;
        }
    }

    printf("Cidade nao encontrada.\n");
}

void imprimirTodasCidades(struct Cidade cidades[], int numCidades) {
    printf("\nCidades:\n");
    for (i = 0; i < numCidades; i++) {
        printf("Codigo: %d, Nome: %s, Habitantes: %d\n", cidades[i].codigo, cidades[i].nome, cidades[i].numHabitantes);
    }
}

int main() {
    struct Cidade cidades[MAX_CIDADES];
    int numCidades = 0;
    int opcao;

    do {
        // Exibe o menu
        printf("\nMENU\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar (codigo)\n");
        printf("5. Imprimir todas\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Realiza a operação de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                inserirCidade(cidades, &numCidades);
                break;
            case 2:
                alterarCidade(cidades, numCidades);
                break;
            case 3:
                excluirCidade(cidades, &numCidades);
                break;
            case 4:
                pesquisarCidade(cidades, numCidades);
                break;
            case 5:
                imprimirTodasCidades(cidades, numCidades);
                break;
            case 9:
                printf("Saindo do programa de manipulacao de cidades.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}


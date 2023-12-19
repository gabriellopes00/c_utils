#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define TAM_RA 10
#define ARQUIVO "alunos.dat"

int i;

typedef struct {
    char ra[TAM_RA];
} Aluno;

void imprimirMenu() {
    printf("\nCONTROLE DE RAs\n");
    printf("1. Inserir\n");
    printf("2. Alterar\n");
    printf("3. Excluir\n");
    printf("4. Pesquisar\n");
    printf("5. Imprimir analitico\n");
    printf("6. Imprimir sintetico\n");
    printf("7. Contar\n");
    printf("8. Salvar em banco\n");
    printf("9. Carregar do banco\n");
    printf("20. Sair\n");
    printf("Escolha uma opcao: ");
}

int buscarPosicaoVazia(Aluno alunos[]) {
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ra[0] == '\0') {
            return i;
        }
    }
    return -1;  // Não há posição vazia
}

int buscarAlunoPorRA(Aluno alunos[], char ra[]) {
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (strcmp(alunos[i].ra, ra) == 0) {
            return i;  // Retorna a posição se encontrar
        }
    }
    return -1;  // Não encontrado
}

void inserirAluno(Aluno alunos[]) {
    char novoRA[TAM_RA];
    printf("Digite o RA do aluno a ser inserido: ");
    scanf("%s", novoRA);

    // Verifica se o RA já existe
    if (buscarAlunoPorRA(alunos, novoRA) != -1) {
        printf("RA ja existe. Insercao cancelada.\n");
        return;
    }

    int posicaoVazia = buscarPosicaoVazia(alunos);

    if (posicaoVazia != -1) {
        strcpy(alunos[posicaoVazia].ra, novoRA);
        printf("Aluno inserido com sucesso.\n");
    } else {
        printf("Nao ha posicoes vazias para insercao.\n");
    }
}

void alterarAluno(Aluno alunos[]) {
    char raOrigem[TAM_RA], raDestino[TAM_RA];
    printf("Digite o RA de origem: ");
    scanf("%s", raOrigem);

    int posicaoOrigem = buscarAlunoPorRA(alunos, raOrigem);

    if (posicaoOrigem != -1) {
        printf("Digite o novo RA: ");
        scanf("%s", raDestino);

        strcpy(alunos[posicaoOrigem].ra, raDestino);
        printf("RA alterado com sucesso.\n");
    } else {
        printf("RA de origem nao encontrado.\n");
    }
}

void excluirAluno(Aluno alunos[]) {
    char raExcluir[TAM_RA];
    printf("Digite o RA do aluno a ser excluido: ");
    scanf("%s", raExcluir);

    int posicaoExcluir = buscarAlunoPorRA(alunos, raExcluir);

    if (posicaoExcluir != -1) {
        alunos[posicaoExcluir].ra[0] = '\0';  // Marca como posição vazia
        printf("Aluno excluido com sucesso.\n");
    } else {
        printf("RA nao encontrado.\n");
    }
}

void pesquisarAluno(Aluno alunos[]) {
    char raPesquisar[TAM_RA];
    printf("Digite o RA do aluno a ser pesquisado: ");
    scanf("%s", raPesquisar);

    int posicao = buscarAlunoPorRA(alunos, raPesquisar);

    if (posicao != -1) {
        printf("Aluno encontrado na posicao %d.\n", posicao);
    } else {
        printf("RA nao encontrado.\n");
    }
}

void imprimirAnalitico(Aluno alunos[]) {
    printf("Imprimindo analitico:\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Posicao %d: %s\n", i, alunos[i].ra);
    }
}

void imprimirSintetico(Aluno alunos[]) {
    printf("Imprimindo sintetico:\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ra[0] != '\0') {
            printf("Posicao %d: %s\n", i, alunos[i].ra);
        }
    }
}

void contarAlunos(Aluno alunos[]) {
    int contador = 0;
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ra[0] != '\0') {
            contador++;
        }
    }
    printf("Total de alunos cadastrados: %d\n", contador);
}

void salvarEmBanco(Aluno alunos[]) {
    FILE *arquivo = fopen(ARQUIVO, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(alunos, sizeof(Aluno), MAX_ALUNOS, arquivo);

    fclose(arquivo);

    printf("Dados salvos em banco com sucesso.\n");
}

void carregarDoBanco(Aluno alunos[]) {
    FILE *arquivo = fopen(ARQUIVO, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(alunos, sizeof(Aluno), MAX_ALUNOS, arquivo);

    fclose(arquivo);

    printf("Dados carregados do banco com sucesso.\n");
}

int main() {
    Aluno alunos[MAX_ALUNOS] = {0};  // Inicializa o vetor de alunos

    int opcao;

    do {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAluno(alunos);
                break;
            case 2:
                alterarAluno(alunos);
                break;
            case 3:
                excluirAluno(alunos);
                break;
            case 4:
                pesquisarAluno(alunos);
                break;
            case 5:
                imprimirAnalitico(alunos);
                break;
            case 6:
                imprimirSintetico(alunos);
                break;
            case 7:
                contarAlunos(alunos);
                break;
            case 8:
                salvarEmBanco(alunos);
                break;
            case 9:
                carregarDoBanco(alunos);
                break;
            case 20:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 20);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ALUNOS 30
#define TAM_RA 10
#define TAM_CURSO 5
#define TAM_NOME 50

int i;

struct Aluno {
    char ra[TAM_RA];
    char curso[TAM_CURSO];
    int periodo;
    char nome[TAM_NOME];
};

void inicializarSistema(struct Aluno sistema[], int *numAlunos) {
    for (i = 0; i < MAX_ALUNOS; i++) {
        sistema[i].ra[0] = '\0'; // Inicializa os RA como vazios
    }
    *numAlunos = 0; // Inicializa o número de alunos como zero
}

int buscarAluno(struct Aluno sistema[], int numAlunos, const char *ra) {
    for (i = 0; i < numAlunos; i++) {
        if (strcmp(sistema[i].ra, ra) == 0) {
            return i; // Retorna o índice do aluno se encontrado
        }
    }
    return -1; // Retorna -1 se o aluno não for encontrado
}

int buscarPosicaoVazia(struct Aluno sistema[]) {
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (sistema[i].ra[0] == '\0') {
            return i; // Retorna o índice da primeira posição vazia encontrada
        }
    }
    return -1; // Retorna -1 se não encontrar posição vazia
}

void inserirAluno(struct Aluno sistema[], int *numAlunos) {
    if (*numAlunos < MAX_ALUNOS) {
        int posicao = buscarPosicaoVazia(sistema);
        if (posicao != -1) {
            printf("Digite o RA do aluno: ");
            scanf("%s", sistema[posicao].ra);
            if (buscarAluno(sistema, *numAlunos, sistema[posicao].ra) == -1) {
                printf("Digite o curso do aluno (sigla): ");
                scanf("%s", sistema[posicao].curso);
                printf("Digite o periodo do aluno: ");
                scanf("%d", &sistema[posicao].periodo);
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", sistema[posicao].nome);
                (*numAlunos)++;
                printf("Aluno inserido com sucesso.\n");
            } else {
                printf("RA duplicado. Nao e possivel cadastrar o aluno.\n");
            }
        } else {
            printf("Sistema lotado. Nao e possivel cadastrar mais alunos.\n");
        }
    } else {
        printf("Sistema lotado. Nao e possivel cadastrar mais alunos.\n");
    }
}

void alterarAluno(struct Aluno sistema[], int numAlunos) {
    char ra[TAM_RA];
    printf("Digite o RA do aluno que deseja alterar: ");
    scanf("%s", ra);

    int posicao = buscarAluno(sistema, numAlunos, ra);
    if (posicao != -1) {
        printf("Digite o novo curso do aluno (sigla): ");
        scanf("%s", sistema[posicao].curso);
        printf("Digite o novo periodo do aluno: ");
        scanf("%d", &sistema[posicao].periodo);
        printf("Digite o novo nome do aluno: ");
        scanf(" %[^\n]", sistema[posicao].nome);
        printf("Aluno alterado com sucesso.\n");
    } else {
        printf("Aluno nao encontrado. Nao e possivel alterar.\n");
    }
}

void excluirAluno(struct Aluno sistema[], int *numAlunos) {
    char ra[TAM_RA];
    printf("Digite o RA do aluno que deseja excluir: ");
    scanf("%s", ra);

    int posicao = buscarAluno(sistema, *numAlunos, ra);
    if (posicao != -1) {
        // Exclui o aluno da posição
        sistema[posicao].ra[0] = '\0';
        (*numAlunos)--;
        printf("Aluno excluido com sucesso.\n");
    } else {
        printf("Aluno nao encontrado. Nao e possivel excluir.\n");
    }
}

void pesquisarAluno(struct Aluno sistema[], int numAlunos) {
    char ra[TAM_RA];
    printf("Digite o RA do aluno que deseja pesquisar: ");
    scanf("%s", ra);

    int posicao = buscarAluno(sistema, numAlunos, ra);
    if (posicao != -1) {
        printf("Aluno encontrado:\n");
        printf("RA: %s\n", sistema[posicao].ra);
        printf("Curso: %s\n", sistema[posicao].curso);
        printf("Periodo: %d\n", sistema[posicao].periodo);
        printf("Nome: %s\n", sistema[posicao].nome);
    } else {
        printf("Aluno nao encontrado.\n");
    }
}

void imprimirInscritos(struct Aluno sistema[], int numAlunos) {
    printf("\nLista de alunos inscritos:\n");
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (sistema[i].ra[0] != '\0') {
            printf("RA: %s, Curso: %s, Periodo: %d, Nome: %s\n",
                   sistema[i].ra, sistema[i].curso, sistema[i].periodo, sistema[i].nome);
        }
    }
}

void sortearAluno(struct Aluno sistema[], int numAlunos) {
    if (numAlunos == 0) {
        printf("Nao ha alunos inscritos. Nao e possivel realizar o sorteio.\n");
        return;
    }

    srand(time(NULL));
    int sorteio;
    int posicaoSorteada;

    do {
        sorteio = rand() % MAX_ALUNOS;
        posicaoSorteada = sorteio;
    } while (sistema[posicaoSorteada].ra[0] == '\0');

    printf("Aluno sorteado:\n");
    printf("RA: %s, Curso: %s, Periodo: %d, Nome: %s\n",
           sistema[posicaoSorteada].ra, sistema[posicaoSorteada].curso,
           sistema[posicaoSorteada].periodo, sistema[posicaoSorteada].nome);
}

int main() {
    struct Aluno sistema[MAX_ALUNOS];
    int numAlunos;

    inicializarSistema(sistema, &numAlunos);

    int opcao;
    do {
        printf("\nSORTEIO FACIL\n");
        printf("1. Inserir aluno\n");
        printf("2. Alterar aluno\n");
        printf("3. Excluir aluno\n");
        printf("4. Pesquisar aluno\n");
        printf("5. Imprimir inscritos\n");
        printf("6. Numero de inscritos\n");
        printf("7. Sortear aluno\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAluno(sistema, &numAlunos);
                break;
            case 2:
                alterarAluno(sistema, numAlunos);
                break;
            case 3:
                excluirAluno(sistema, &numAlunos);
                break;
            case 4:
                pesquisarAluno(sistema, numAlunos);
                break;
            case 5:
                imprimirInscritos(sistema, numAlunos);
                break;
            case 6:
                printf("Numero de inscritos: %d\n", numAlunos);
                break;
            case 7:
                sortearAluno(sistema, numAlunos);
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 5
#define TAM_NOME 50

int i;

struct Aluno {
    char ra[15];
    char nome[TAM_NOME];
    float mensalidade;
};

struct ControleAlunos {
    struct Aluno alunos[MAX_ALUNOS];
    int quantidade;
};

void cadastrarAluno(struct ControleAlunos *controle) {
    if (controle->quantidade < MAX_ALUNOS) {
        printf("Digite o RA do aluno: ");
        scanf("%s", controle->alunos[controle->quantidade].ra);
        printf("Digite o primeiro nome do aluno: ");
        scanf("%s", controle->alunos[controle->quantidade].nome);
        printf("Digite a mensalidade do aluno: ");
        scanf("%f", &controle->alunos[controle->quantidade].mensalidade);

        controle->quantidade++;
        printf("Aluno cadastrado com sucesso.\n");
    } else {
        printf("Limite de alunos atingido. Impossivel cadastrar mais.\n");
    }
}

void relatorioAlunos(struct ControleAlunos *controle) {
    printf("\nRelatorio de Alunos:\n");
    printf("%-15s %-20s %-15s\n", "RA", "Nome", "Mensalidade");

    for (i = 0; i < controle->quantidade; i++) {
        // Verifica se o RA está vazio antes de exibir
        if (strlen(controle->alunos[i].ra) > 0) {
            printf("%-15s %-20s %-15.2f\n", controle->alunos[i].ra, controle->alunos[i].nome, controle->alunos[i].mensalidade);
        }
    }
}

void pesquisarAlunoPorRA(struct ControleAlunos *controle) {
    char raPesquisado[15];
    printf("Digite o RA do aluno que deseja pesquisar: ");
    scanf("%s", raPesquisado);

    int encontrado = 0;

    for (i = 0; i < controle->quantidade; i++) {
        if (strcmp(controle->alunos[i].ra, raPesquisado) == 0) {
            printf("\nDados do aluno:\n");
            printf("RA: %s\n", controle->alunos[i].ra);
            printf("Nome: %s\n", controle->alunos[i].nome);
            printf("Mensalidade: %.2f\n", controle->alunos[i].mensalidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com RA %s nao encontrado.\n", raPesquisado);
    }
}

void removerAlunoPorRA(struct ControleAlunos *controle) {
    char raRemover[15];
    printf("Digite o RA do aluno que deseja remover: ");
    scanf("%s", raRemover);

    int encontrado = 0;

    for (i = 0; i < controle->quantidade; i++) {
        if (strcmp(controle->alunos[i].ra, raRemover) == 0) {
            // Limpa os dados do aluno encontrado
            controle->alunos[i].ra[0] = '\0';
            controle->alunos[i].nome[0] = '\0';
            controle->alunos[i].mensalidade = 0;

            printf("Aluno com RA %s removido com sucesso.\n", raRemover);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com RA %s nao encontrado. Nenhum aluno removido.\n", raRemover);
    }
}

void calcularMediaMensalidades(struct ControleAlunos *controle) {
    float somaMensalidades = 0;
    int count = 0;

    for (i = 0; i < controle->quantidade; i++) {
        if (strlen(controle->alunos[i].ra) > 0) {
            somaMensalidades += controle->alunos[i].mensalidade;
            count++;
        }
    }

    if (count > 0) {
        float media = somaMensalidades / count;
        printf("Media das mensalidades: %.2f\n", media);
    } else {
        printf("Nenhum aluno cadastrado. Impossivel calcular a media.\n");
    }
}

void encontrarMenorMensalidade(struct ControleAlunos *controle) {
    float menorMensalidade = -1;
    int indiceMenor = -1;

    for (i = 0; i < controle->quantidade; i++) {
        if (strlen(controle->alunos[i].ra) > 0) {
            if (menorMensalidade == -1 || controle->alunos[i].mensalidade < menorMensalidade) {
                menorMensalidade = controle->alunos[i].mensalidade;
                indiceMenor = i;
            }
        }
    }

    if (indiceMenor != -1) {
        printf("\nAluno com menor mensalidade:\n");
        printf("RA: %s\n", controle->alunos[indiceMenor].ra);
        printf("Nome: %s\n", controle->alunos[indiceMenor].nome);
        printf("Mensalidade: %.2f\n", controle->alunos[indiceMenor].mensalidade);
    } else {
        printf("Nenhum aluno cadastrado. Impossivel encontrar o menor valor.\n");
    }
}

void limparBase(struct ControleAlunos *controle) {
    for (i = 0; i < MAX_ALUNOS; i++) {
        controle->alunos[i].ra[0] = '\0';
        controle->alunos[i].nome[0] = '\0';
        controle->alunos[i].mensalidade = 0;
    }

    controle->quantidade = 0;
    printf("Base de dados limpa. Todos os registros removidos.\n");
}

int main() {
    struct ControleAlunos controle = {0};
    int opcao;

    do {
        printf("\nCONTROLE DE ALUNOS\n");
        printf("1 - Cadastrar\n");
        printf("2 - Relatorio\n");
        printf("3 - Pesquisar RA\n");
        printf("4 - Remover (RA)\n");
        printf("5 - Media Mensalidades\n");
        printf("6 - Menor Mensalidade\n");
        printf("7 - Limpar Base\n");
        printf("99 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(&controle);
                break;
            case 2:
                relatorioAlunos(&controle);
                break;
            case 3:
                pesquisarAlunoPorRA(&controle);
                break;
            case 4:
                removerAlunoPorRA(&controle);
                break;
            case 5:
                calcularMediaMensalidades(&controle);
                break;
            case 6:
                encontrarMenorMensalidade(&controle);
                break;
            case 7:
                limparBase(&controle);
                break;
            case 99:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 99);

    return 0;
}


#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define TAM_NOME 50

int i, j;

struct Aluno {
    int ra;
    char nome[TAM_NOME];
    int idade;
    float valorMensalidade;
};

void inserirAluno(struct Aluno alunos[], int *numAlunos) {
    if (*numAlunos < MAX_ALUNOS) {
        printf("Digite o RA do aluno: ");
        scanf("%d", &alunos[*numAlunos].ra);
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[*numAlunos].nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[*numAlunos].idade);
        printf("Digite o valor da mensalidade do aluno: ");
        scanf("%f", &alunos[*numAlunos].valorMensalidade);
        (*numAlunos)++;
        printf("Aluno inserido com sucesso.\n");
    } else {
        printf("Limite de alunos atingido. Impossivel inserir mais.\n");
    }
}

void alterarAluno(struct Aluno alunos[], int numAlunos) {
    int ra;
    printf("Digite o RA do aluno que deseja alterar: ");
    scanf("%d", &ra);

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].ra == ra) {
            printf("Digite o novo nome do aluno: ");
            scanf(" %[^\n]", alunos[i].nome);
            printf("Digite a nova idade do aluno: ");
            scanf("%d", &alunos[i].idade);
            printf("Digite o novo valor da mensalidade do aluno: ");
            scanf("%f", &alunos[i].valorMensalidade);
            printf("Aluno alterado com sucesso.\n");
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void excluirAluno(struct Aluno alunos[], int *numAlunos) {
    int ra;
    printf("Digite o RA do aluno que deseja excluir: ");
    scanf("%d", &ra);

    for (i = 0; i < *numAlunos; i++) {
        if (alunos[i].ra == ra) {
            for (j = i; j < *numAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*numAlunos)--;
            printf("Aluno excluido com sucesso.\n");
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void pesquisarAluno(struct Aluno alunos[], int numAlunos) {
    int ra;
    printf("Digite o RA do aluno que deseja pesquisar: ");
    scanf("%d", &ra);

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].ra == ra) {
            printf("RA: %d\n", alunos[i].ra);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Valor da mensalidade: %.2f\n", alunos[i].valorMensalidade);
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void imprimirTodosAlunos(struct Aluno alunos[], int numAlunos) {
    printf("\nAlunos:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("RA: %d, Nome: %s, Idade: %d, Mensalidade: %.2f\n",
               alunos[i].ra, alunos[i].nome, alunos[i].idade, alunos[i].valorMensalidade);
    }
}

float somarMensalidades(struct Aluno alunos[], int numAlunos) {
    float soma = 0;
    for (i = 0; i < numAlunos; i++) {
        soma += alunos[i].valorMensalidade;
    }
    return soma;
}

int numeroAlunosCadastrados(int numAlunos) {
    return numAlunos;
}

float valorMedioMensalidade(struct Aluno alunos[], int numAlunos) {
    if (numAlunos > 0) {
        float soma = somarMensalidades(alunos, numAlunos);
        return soma / numAlunos;
    } else {
        return 0;
    }
}

float maiorMensalidade(struct Aluno alunos[], int numAlunos) {
    if (numAlunos > 0) {
        float maior = alunos[0].valorMensalidade;
        for (i = 1; i < numAlunos; i++) {
            if (alunos[i].valorMensalidade > maior) {
                maior = alunos[i].valorMensalidade;
            }
        }
        return maior;
    } else {
        return 0;
    }
}

float menorMensalidade(struct Aluno alunos[], int numAlunos) {
    if (numAlunos > 0) {
        float menor = alunos[0].valorMensalidade;
        for (i = 1; i < numAlunos; i++) {
            if (alunos[i].valorMensalidade < menor) {
                menor = alunos[i].valorMensalidade;
            }
        }
        return menor;
    } else {
        return 0;
    }
}

void mensalidadeMaiorQueX(struct Aluno alunos[], int numAlunos, float valorX) {
    printf("\nAlunos com mensalidade maior que %.2f:\n", valorX);
    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].valorMensalidade > valorX) {
            printf("RA: %d, Nome: %s, Idade: %d, Mensalidade: %.2f\n",
                   alunos[i].ra, alunos[i].nome, alunos[i].idade, alunos[i].valorMensalidade);
        }
    }
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {
        // Exibe o menu
        printf("\nMENU SYSACAD\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar (ra)\n");
        printf("5. Imprimir todas\n");
        printf("6. Somar mensalidades\n");
        printf("7. Numero alunos cadastrados\n");
        printf("8. Valor medio mensalidade\n");
        printf("9. Valor maior mensalidade\n");
        printf("10. Valor menor mensalidade\n");
        printf("11. Mensalidade maior valor\n");
        printf("12. Mensalidade menor valor\n");
        printf("13. Imprimir mensalidade valor maior que X\n");
        printf("20. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Realiza a operação de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                inserirAluno(alunos, &numAlunos);
                break;
            case 2:
                alterarAluno(alunos, numAlunos);
                break;
            case 3:
                excluirAluno(alunos, &numAlunos);
                break;
            case 4:
                pesquisarAluno(alunos, numAlunos);
                break;
            case 5:
                imprimirTodosAlunos(alunos, numAlunos);
                break;
            case 6:
                printf("Soma total das mensalidades: %.2f\n", somarMensalidades(alunos, numAlunos));
                break;
            case 7:
                printf("Numero de alunos cadastrados: %d\n", numeroAlunosCadastrados(numAlunos));
                break;
            case 8:
                printf("Valor medio das mensalidades: %.2f\n", valorMedioMensalidade(alunos, numAlunos));
                break;
            case 9:
                printf("Maior valor de mensalidade: %.2f\n", maiorMensalidade(alunos, numAlunos));
                break;
            case 10:
                printf("Menor valor de mensalidade: %.2f\n", menorMensalidade(alunos, numAlunos));
                break;
            case 11:
                printf("Maior mensalidade:\n");
                pesquisarAluno(alunos, numAlunos);
                break;
            case 12:
                printf("Menor mensalidade:\n");
                pesquisarAluno(alunos, numAlunos);
                break;
            case 13:
                {
                    float valorX;
                    printf("Digite o valor X: ");
                    scanf("%f", &valorX);
                    mensalidadeMaiorQueX(alunos, numAlunos, valorX);
                }
                break;
            case 20:
                printf("Saindo do programa SYSACAD.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 20);

    return 0;
}


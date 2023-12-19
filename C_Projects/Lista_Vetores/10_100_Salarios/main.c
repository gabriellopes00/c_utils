#include <stdio.h>

#define TAMANHO_VETOR 100

int i, j;

struct Salarios {
    float salarios[TAMANHO_VETOR];
    int quantidade;
};

void adicionarSalario(struct Salarios *pSalarios) {
    if (pSalarios->quantidade < TAMANHO_VETOR) {
        printf("Digite o salario a ser adicionado: ");
        scanf("%f", &pSalarios->salarios[pSalarios->quantidade]);
        pSalarios->quantidade++;
        printf("Salario adicionado com sucesso.\n");
    } else {
        printf("Limite de salarios atingido. Impossivel adicionar mais.\n");
    }
}

void removerPosicao(struct Salarios *pSalarios) {
    int posicao;

    printf("Digite a POSICAO do vetor que deseja remover: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= pSalarios->quantidade) {
        for (i = posicao - 1; i < pSalarios->quantidade - 1; i++) {
            pSalarios->salarios[i] = pSalarios->salarios[i + 1];
        }
        pSalarios->quantidade--;
        printf("Salario removido com sucesso.\n");
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", pSalarios->quantidade);
    }
}

void imprimirTodos(struct Salarios *pSalarios) {
    printf("\nTodos os salarios cadastrados:\n");
    for (i = 0; i < pSalarios->quantidade; i++) {
        printf("Posicao %d: %.2f\n", i + 1, pSalarios->salarios[i]);
    }
}

void pesquisarSalario(struct Salarios *pSalarios) {
    float salario;
    int encontrado = 0;

    printf("Digite o salario a ser pesquisado: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] == salario) {
            printf("Salario %.2f encontrado na posicao %d.\n", salario, i + 1);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Salario %.2f nao encontrado.\n", salario);
    }
}

void adicionarNaPosicao(struct Salarios *pSalarios) {
    int posicao;
    float salario;

    printf("Digite a POSICAO onde deseja adicionar o salario (entre 1 e %d): ", TAMANHO_VETOR);
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= TAMANHO_VETOR) {
        if (pSalarios->salarios[posicao - 1] == 0) {
            printf("Digite o salario a ser adicionado: ");
            scanf("%f", &salario);
            pSalarios->salarios[posicao - 1] = salario;
            pSalarios->quantidade++;
            printf("Salario adicionado com sucesso.\n");
        } else {
            printf("Posicao ocupada. Nao foi possivel adicionar o salario.\n");
        }
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", TAMANHO_VETOR);
    }
}

void pesquisarQuantidadeSalarios(struct Salarios *pSalarios) {
    float salario;
    int contador = 0;

    printf("Digite o salario a ser pesquisado: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] == salario) {
            contador++;
        }
    }

    printf("Quantidade de salarios %.2f encontrados: %d\n", salario, contador);
}

void somarSalarios(struct Salarios *pSalarios) {
    float soma = 0;

    for (i = 0; i < pSalarios->quantidade; i++) {
        soma += pSalarios->salarios[i];
    }

    printf("Soma de todos os salarios: %.2f\n", soma);
}

void somarSalariosX(struct Salarios *pSalarios) {
    float salario;
    float soma = 0;

    printf("Digite o salario a ser somado: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] == salario) {
            soma += pSalarios->salarios[i];
        }
    }

    printf("Soma dos salarios %.2f: %.2f\n", salario, soma);
}

void contarSalarios(struct Salarios *pSalarios) {
    printf("Total de salarios cadastrados: %d\n", pSalarios->quantidade);
}

void contarSalariosX(struct Salarios *pSalarios) {
    float salario;
    int contador = 0;

    printf("Digite o salario a ser contado: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] == salario) {
            contador++;
        }
    }

    printf("Quantidade de salarios %.2f encontrados: %d\n", salario, contador);
}

void contarSalariosMaioresQueX(struct Salarios *pSalarios) {
    float salario;
    int contador = 0;

    printf("Digite o valor de X: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] > salario) {
            contador++;
        }
    }

    printf("Quantidade de salarios maiores que %.2f: %d\n", salario, contador);
}

void maiorSalario(struct Salarios *pSalarios) {
    if (pSalarios->quantidade > 0) {
        float max = pSalarios->salarios[0];

        for (i = 1; i < pSalarios->quantidade; i++) {
            if (pSalarios->salarios[i] > max) {
                max = pSalarios->salarios[i];
            }
        }

        printf("Maior salario: %.2f\n", max);
    } else {
        printf("Nenhum salario cadastrado.\n");
    }
}

void menorSalario(struct Salarios *pSalarios) {
    if (pSalarios->quantidade > 0) {
        float min = pSalarios->salarios[0];

        for (i = 1; i < pSalarios->quantidade; i++) {
            if (pSalarios->salarios[i] < min) {
                min = pSalarios->salarios[i];
            }
        }

        printf("Menor salario: %.2f\n", min);
    } else {
        printf("Nenhum salario cadastrado.\n");
    }
}

void mediaSalarios(struct Salarios *pSalarios) {
    if (pSalarios->quantidade > 0) {
        float soma = 0;

        for (i = 0; i < pSalarios->quantidade; i++) {
            soma += pSalarios->salarios[i];
        }

        float media = soma / pSalarios->quantidade;

        printf("Media dos salarios: %.2f\n", media);
    } else {
        printf("Nenhum salario cadastrado.\n");
    }
}

void removerSalariosValorX(struct Salarios *pSalarios) {
    float salario;

    printf("Digite o salario a ser removido: ");
    scanf("%f", &salario);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] == salario) {
            pSalarios->salarios[i] = 0;
        }
    }

    printf("Salarios %.2f removidos com sucesso.\n", salario);
}

void removerTodosSalarios(struct Salarios *pSalarios) {
    for (i = 0; i < TAMANHO_VETOR; i++) {
        pSalarios->salarios[i] = 0;
    }
    pSalarios->quantidade = 0;
    printf("Todos os salarios removidos com sucesso.\n");
}

void imprimirSalarioPosicaoY(struct Salarios *pSalarios) {
    int posicao;

    printf("Digite a POSICAO do vetor que deseja imprimir: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= pSalarios->quantidade) {
        printf("Salario na posicao %d: %.2f\n", posicao, pSalarios->salarios[posicao - 1]);
    } else {
        printf("Posicao invalida ou vazia. A posicao deve estar entre 1 e %d.\n", pSalarios->quantidade);
    }
}

void imprimirSalariosMenoresQueX(struct Salarios *pSalarios) {
    float salario;

    printf("Digite o valor de X: ");
    scanf("%f", &salario);

    printf("\nSalarios menores que %.2f cadastrados:\n", salario);
    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] < salario) {
            printf("Posicao %d: %.2f\n", i + 1, pSalarios->salarios[i]);
        }
    }
}

void aplicarAcrescimoEmTodos(struct Salarios *pSalarios) {
    float acrescimo;

    printf("Digite a porcentagem de acrescimo: ");
    scanf("%f", &acrescimo);

    for (i = 0; i < pSalarios->quantidade; i++) {
        pSalarios->salarios[i] += pSalarios->salarios[i] * (acrescimo / 100);
    }

    printf("Acrescimo de %.2f%% aplicado em todos os salarios.\n", acrescimo);
}

void aplicarDescontoEmMaioresQueX(struct Salarios *pSalarios) {
    float desconto, salario;

    printf("Digite o valor de X: ");
    scanf("%f", &salario);

    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &desconto);

    for (i = 0; i < pSalarios->quantidade; i++) {
        if (pSalarios->salarios[i] > salario) {
            pSalarios->salarios[i] -= pSalarios->salarios[i] * (desconto / 100);
        }
    }

    printf("Desconto de %.2f%% aplicado em salarios maiores que %.2f.\n", desconto, salario);
}

int main() {
    struct Salarios salarios = {0};
    int opcao;

    do {
        printf("\nMENU - SALARIOS\n");
        printf("01 - Adicionar\n");
        printf("02 - Remover posicao Y\n");
        printf("03 - Imprimir todos\n");
        printf("04 - Pesquisar salario X\n");
        printf("05 - Adicionar na posicao\n");
        printf("05 - Adicionar na posicao\n");
printf("06 - Pesquisar a quantidade salarios X\n");
printf("07 - Somar salarios\n");
printf("08 - Somar salarios X\n");
printf("09 - Contar salarios\n");
printf("10 - Contar salarios X\n");
printf("11 - Contar salarios maiores que X\n");
printf("12 - Maior salario\n");
printf("13 - Menor salario\n");
printf("14 - Media salarios\n");
printf("15 - Remover salarios valor X\n");
printf("16 - Remover todos os salarios\n");
printf("17 - Imprimir salario posicao Y\n");
printf("18 - Imprimir salarios menores que X\n");
printf("19 - Aplicar acrescimo de Z%% em todos os salarios\n");
printf("20 - Aplicar desconto de Z%% em salarios maiores que X\n");
printf("99 - Sair.\n");
            printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            adicionarSalario(&salarios);
            break;

        case 2:
            removerPosicao(&salarios);
            break;

        case 3:
            imprimirTodos(&salarios);
            break;

        case 4:
            pesquisarSalario(&salarios);
            break;

        case 5:
            adicionarNaPosicao(&salarios);
            break;

        case 6:
            pesquisarQuantidadeSalarios(&salarios);
            break;

        case 7:
            somarSalarios(&salarios);
            break;

        case 8:
            somarSalariosX(&salarios);
            break;

        case 9:
            contarSalarios(&salarios);
            break;

        case 10:
            contarSalariosX(&salarios);
            break;

        case 11:
            contarSalariosMaioresQueX(&salarios);
            break;

        case 12:
            maiorSalario(&salarios);
            break;

        case 13:
            menorSalario(&salarios);
            break;

        case 14:
            mediaSalarios(&salarios);
            break;

        case 15:
            removerSalariosValorX(&salarios);
            break;

        case 16:
            removerTodosSalarios(&salarios);
            break;

        case 17:
            imprimirSalarioPosicaoY(&salarios);
            break;

        case 18:
            imprimirSalariosMenoresQueX(&salarios);
            break;

        case 19:
            aplicarAcrescimoEmTodos(&salarios);
            break;

        case 20:
            aplicarDescontoEmMaioresQueX(&salarios);
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

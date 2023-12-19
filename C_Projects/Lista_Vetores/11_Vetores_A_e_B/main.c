#include <stdio.h>

#define TAMANHO_VETOR 10

int i;

struct Vetor {
    int vetorA[TAMANHO_VETOR];
    int vetorB[TAMANHO_VETOR];
    int tamanhoA;
    int tamanhoB;
};

void adicionarVetorA(struct Vetor *pVetor) {
    if (pVetor->tamanhoA < TAMANHO_VETOR) {
        printf("Digite um valor inteiro para adicionar ao vetor A: ");
        scanf("%d", &pVetor->vetorA[pVetor->tamanhoA]);
        pVetor->tamanhoA++;
        printf("Valor adicionado ao vetor A com sucesso.\n");
    } else {
        printf("Limite de elementos atingido para o vetor A. Impossivel adicionar mais.\n");
    }
}

void adicionarVetorB(struct Vetor *pVetor) {
    if (pVetor->tamanhoB < TAMANHO_VETOR) {
        printf("Digite um valor inteiro para adicionar ao vetor B: ");
        scanf("%d", &pVetor->vetorB[pVetor->tamanhoB]);
        pVetor->tamanhoB++;
        printf("Valor adicionado ao vetor B com sucesso.\n");
    } else {
        printf("Limite de elementos atingido para o vetor B. Impossivel adicionar mais.\n");
    }
}

void removerDoVetorA(struct Vetor *pVetor, int posicao) {
    if (posicao >= 1 && posicao <= pVetor->tamanhoA) {
        for (i = posicao - 1; i < pVetor->tamanhoA - 1; i++) {
            pVetor->vetorA[i] = pVetor->vetorA[i + 1];
        }
        pVetor->tamanhoA--;
        printf("Valor removido do vetor A com sucesso.\n");
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", pVetor->tamanhoA);
    }
}

void removerDoVetorB(struct Vetor *pVetor, int posicao) {
    if (posicao >= 1 && posicao <= pVetor->tamanhoB) {
        for (i = posicao - 1; i < pVetor->tamanhoB - 1; i++) {
            pVetor->vetorB[i] = pVetor->vetorB[i + 1];
        }
        pVetor->tamanhoB--;
        printf("Valor removido do vetor B com sucesso.\n");
    } else {
        printf("Posicao invalida. A posicao deve estar entre 1 e %d.\n", pVetor->tamanhoB);
    }
}

void imprimirVetorA(struct Vetor *pVetor) {
    printf("\nVetor A:\n");
    for (i = 0; i < pVetor->tamanhoA; i++) {
        printf("Posicao %d: %d\n", i + 1, pVetor->vetorA[i]);
    }
}

void imprimirVetorB(struct Vetor *pVetor) {
    printf("\nVetor B:\n");
    for (i = 0; i < pVetor->tamanhoB; i++) {
        printf("Posicao %d: %d\n", i + 1, pVetor->vetorB[i]);
    }
}

void contarValoresVetorA(struct Vetor *pVetor) {
    printf("Total de valores no vetor A: %d\n", pVetor->tamanhoA);
}

void contarValoresVetorB(struct Vetor *pVetor) {
    printf("Total de valores no vetor B: %d\n", pVetor->tamanhoB);
}

void somarValores(struct Vetor *pVetor) {
    int somaA = 0, somaB = 0;

    for (i = 0; i < pVetor->tamanhoA; i++) {
        somaA += pVetor->vetorA[i];
    }

    for (i = 0; i < pVetor->tamanhoB; i++) {
        somaB += pVetor->vetorB[i];
    }

    printf("Soma dos valores do vetor A: %d\n", somaA);
    printf("Soma dos valores do vetor B: %d\n", somaB);
}

void compararQuantidadeValores(struct Vetor *pVetor) {
    if (pVetor->tamanhoA > pVetor->tamanhoB) {
        printf("O vetor A tem mais valores.\n");
    } else if (pVetor->tamanhoB > pVetor->tamanhoA) {
        printf("O vetor B tem mais valores.\n");
    } else {
        printf("Os vetores A e B tem a mesma quantidade de valores.\n");
    }
}

void compararSomaValores(struct Vetor *pVetor) {
    int somaA = 0, somaB = 0;

    for (i = 0; i < pVetor->tamanhoA; i++) {
        somaA += pVetor->vetorA[i];
    }

    for (i = 0; i < pVetor->tamanhoB; i++) {
        somaB += pVetor->vetorB[i];
    }

    if (somaA > somaB) {
        printf("O vetor A tem uma soma maior.\n");
    } else if (somaB > somaA) {
        printf("O vetor B tem uma soma maior.\n");
    } else {
        printf("Os vetores A e B tem a mesma soma de valores.\n");
    }
}

void transferirParesAparaB(struct Vetor *pVetor) {
    for (i = 0; i < pVetor->tamanhoA; i++) {
        if (pVetor->vetorA[i] % 2 == 0) {
            if (pVetor->tamanhoB < TAMANHO_VETOR) {
                pVetor->vetorB[pVetor->tamanhoB] = pVetor->vetorA[i];
                pVetor->tamanhoB++;
            } else {
                printf("Limite de elementos atingido para o vetor B. Impossivel transferir mais valores.\n");
                return;
            }
        }
    }

    printf("Valores pares transferidos do vetor A para o vetor B com sucesso.\n");
}

void transferirImparesBparaA(struct Vetor *pVetor) {
    for (i = 0; i < pVetor->tamanhoB; i++) {
        if (pVetor->vetorB[i] % 2 != 0) {
            if (pVetor->tamanhoA < TAMANHO_VETOR) {
                pVetor->vetorA[pVetor->tamanhoA] = pVetor->vetorB[i];
                pVetor->tamanhoA++;
            } else {
                printf("Limite de elementos atingido para o vetor A. Impossivel transferir mais valores.\n");
                return;
            }
        }
    }

    printf("Valores impares transferidos do vetor B para o vetor A com sucesso.\n");
}

float calcularMedia(int *vetor, int tamanho) {
    if (tamanho > 0) {
        int soma = 0;

        for (i = 0; i < tamanho; i++) {
            soma += vetor[i];
        }

        return (float)soma / tamanho;
    } else {
        return 0;
    }
}

void mediaValoresVetores(struct Vetor *pVetor) {
    float mediaA = calcularMedia(pVetor->vetorA, pVetor->tamanhoA);
    float mediaB = calcularMedia(pVetor->vetorB, pVetor->tamanhoB);

    printf("Media dos valores do vetor A: %.2f\n", mediaA);
    printf("Media dos valores do vetor B: %.2f\n", mediaB);
}

void compararMediaValores(struct Vetor *pVetor) {
    float mediaA = calcularMedia(pVetor->vetorA, pVetor->tamanhoA);
    float mediaB = calcularMedia(pVetor->vetorB, pVetor->tamanhoB);

    if (mediaA > mediaB) {
        printf("O vetor A tem uma media maior.\n");
    } else if (mediaB > mediaA) {
        printf("O vetor B tem uma media maior.\n");
    } else {
        printf("Os vetores A e B tem a mesma media de valores.\n");
    }
}

void maiorValorVetores(struct Vetor *pVetor) {
    int maiorA = pVetor->vetorA[0], maiorB = pVetor->vetorB[0];

    for (i = 1; i < pVetor->tamanhoA; i++) {
        if (pVetor->vetorA[i] > maiorA) {
            maiorA = pVetor->vetorA[i];
        }
    }

    for (i = 1; i < pVetor->tamanhoB; i++) {
        if (pVetor->vetorB[i] > maiorB) {
            maiorB = pVetor->vetorB[i];
        }
    }

    printf("Maior valor do vetor A: %d\n", maiorA);
    printf("Maior valor do vetor B: %d\n", maiorB);
}

void menorValorVetores(struct Vetor *pVetor) {
    int menorA = pVetor->vetorA[0], menorB = pVetor->vetorB[0];

    for (i = 1; i < pVetor->tamanhoA; i++) {
        if (pVetor->vetorA[i] < menorA) {
            menorA = pVetor->vetorA[i];
        }
    }

    for (i = 1; i < pVetor->tamanhoB; i++) {
        if (pVetor->vetorB[i] < menorB) {
            menorB = pVetor->vetorB[i];
        }
    }

    printf("Menor valor do vetor A: %d\n", menorA);
    printf("Menor valor do vetor B: %d\n", menorB);
}

void compararMaiorValor(struct Vetor *pVetor) {
    int maiorA = pVetor->vetorA[0], maiorB = pVetor->vetorB[0];

    for (i = 1; i < pVetor->tamanhoA; i++) {
        if (pVetor->vetorA[i] > maiorA) {
            maiorA = pVetor->vetorA[i];
        }
    }

    for (i = 1; i < pVetor->tamanhoB; i++) {
        if (pVetor->vetorB[i] > maiorB) {
            maiorB = pVetor->vetorB[i];
        }
    }

    if (maiorA > maiorB) {
        printf("O vetor A tem um maior valor.\n");
    } else if (maiorB > maiorA) {
        printf("O vetor B tem um maior valor.\n");
    } else {
        printf("Os vetores A e B tem o mesmo maior valor.\n");
    }
}

int main() {
    struct Vetor vetores = {0};
    int opcao, posicao;

    do {
        printf("\nMENU - VETORES A e B\n");
        printf("1 - Adicionar vetor A\n");
        printf("2 - Adicionar vetor B\n");
        printf("3 - Remover do vetor A valor da posicao X\n");
        printf("4 - Remover do vetor B valor da posicao X\n");
        printf("5 - Imprimir vetor A\n");
        printf("6 - Imprimir vetor B\n");
        printf("7 - Contar valores vetor A\n");
        printf("8 - Contar valores vetor B\n");
        printf("9 - Somar valores de cada vetor e apresentar\n");
        printf("10 - Qual vetor tem maior quantidade de valores?\n");
        printf("11 - Qual vetor tem a maior soma de valores?\n");
        printf("12 - Transferir valores Pares do vetor A para o B\n");
        printf("13 - Transferir valores Impares do vetor B para o A\n");
        printf("14 - Media de valores de cada vetor\n");
        printf("15 - Qual vetor apresenta a maior media?\n");
        printf("16 - Maior valor de cada vetor\n");
        printf("17 - Menor valor de cada vetor\n");
        printf("18 - Qual vetor apresenta o maior valor?\n");
        printf("99 - Sair.\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVetorA(&vetores);
                break;
            case 2:
                adicionarVetorB(&vetores);
                break;
            case 3:
                printf("Digite a posicao no vetor A que deseja remover: ");
                scanf("%d", &posicao);
                removerDoVetorA(&vetores, posicao);
                break;
            case 4:
                printf("Digite a posicao no vetor B que deseja remover: ");
                scanf("%d", &posicao);
                removerDoVetorB(&vetores, posicao);
                break;
            case 5:
                imprimirVetorA(&vetores);
                break;
            case 6:
                imprimirVetorB(&vetores);
                break;
            case 7:
                contarValoresVetorA(&vetores);
                break;
            case 8:
                contarValoresVetorB(&vetores);
                break;
            case 9:
                somarValores(&vetores);
                break;
            case 10:
                compararQuantidadeValores(&vetores);
                break;
            case 11:
                compararSomaValores(&vetores);
                break;
            case 12:
                transferirParesAparaB(&vetores);
                break;
            case 13:
                transferirImparesBparaA(&vetores);
                break;
            case 14:
                mediaValoresVetores(&vetores);
                break;
            case 15:
                compararMediaValores(&vetores);
                break;
            case 16:
                maiorValorVetores(&vetores);
                break;
            case 17:
                menorValorVetores(&vetores);
                break;
            case 18:
                compararMaiorValor(&vetores);
                break;
            case 99:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 99);

    return 0;
}


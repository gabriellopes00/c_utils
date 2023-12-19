#include <stdio.h>
#include <stdlib.h>

#define vet 8

int idades[vet] = {0}, i;

void zerarIdades() {
    for (i = 0; i < vet; i++) {
        idades[i] = 0;
    }
}

void carregarIdades() {
    printf("Digite as 8 idades dos alunos:\n");
    for (i = 0; i < vet; i++) {
        printf("Idade do aluno %d: ", i + 1);
        scanf("%d", &idades[i]);
    }
}

void imprimirIdades() {
    printf("Idades dos alunos:\n");
    for (i = 0; i < vet; i++) {
        printf("Aluno %d: %d anos\n", i + 1, idades[i]);
    }
}

void somarIdades() {
    int soma = 0;
    for (i = 0; i < vet; i++) {
        soma += idades[i];
    }
    printf("Soma das idades: %d\n", soma);
}

void exibirIdadesPares() {
    printf("Idades pares:\n");
    for (i = 0; i < vet; i++) {
        if (idades[i] % 2 == 0) {
            printf("Aluno %d: %d anos\n", i + 1, idades[i]);
        }
    }
}

void contarIdadesPares() {
    int contador = 0;
    for (i = 0; i < vet; i++) {
        if (idades[i] % 2 == 0) {
            contador++;
        }
    }
    printf("Total de idades pares: %d\n", contador);
}

void somarIdadesPares() {
    int soma = 0;
    for (i = 0; i < vet; i++) {
        if (idades[i] % 2 == 0) {
            soma += idades[i];
        }
    }
    printf("Soma das idades pares: %d\n", soma);
}

void exibirMenoresIdade() {
    printf("Idades menores que 18 anos:\n");
    for (i = 0; i < vet; i++) {
        if (idades[i] < 18) {
            printf("Aluno %d: %d anos\n", i + 1, idades[i]);
        }
    }
}

void contarMaioresIdade() {
    int contador = 0;
    for (i = 0; i < vet; i++) {
        if (idades[i] >= 18) {
            contador++;
        }
    }
    printf("Total de idades maiores ou iguais a 18 anos: %d\n", contador);
}

void somarMaioresIdade() {
    int soma = 0;
    for (i = 0; i < vet; i++) {
        if (idades[i] >= 18) {
            soma += idades[i];
        }
    }
    printf("Soma das idades maiores ou iguais a 18 anos: %d\n", soma);
}

int main() {
    int opcao;

    do {
        printf("\n..:: IDADES ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar\n");
        printf("3. Imprimir\n");
        printf("4. Somar\n");
        printf("5. Pares\n");
        printf("6. Contar pares\n");
        printf("7. Somar pares\n");
        printf("8. Menores idade\n");
        printf("9. Contar maiores idade\n");
        printf("10. Somar maiores idade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                zerarIdades();
                break;
            case 2:
                carregarIdades();
                break;
            case 3:
                imprimirIdades();
                break;
            case 4:
                somarIdades();
                break;
            case 5:
                exibirIdadesPares();
                break;
            case 6:
                contarIdadesPares();
                break;
            case 7:
                somarIdadesPares();
                break;
            case 8:
                exibirMenoresIdade();
                break;
            case 9:
                contarMaioresIdade();
                break;
            case 10:
                somarMaioresIdade();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

	system("pause");
    return 0;
}

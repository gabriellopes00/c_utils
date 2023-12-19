#include <stdio.h>

#define TAMANHO_VETOR 8

int main() {
    int idades[TAMANHO_VETOR] = {0};
    int opcao, i;
    int soma = 0;
    int somaPares = 0;
    int contagemPares = 0;
    int contagemMaiores = 0;
    int somaMaiores = 0;

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
                // Zerar
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    idades[i] = 0;
                }
                printf("Idades zeradas.\n");
                break;

            case 2:
                // Carregar
                printf("Digite as 8 idades:\n");
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    printf("Idade %d: ", i + 1);
                    scanf("%d", &idades[i]);
                }
                printf("Idades carregadas.\n");
                break;

            case 3:
                // Imprimir
                printf("\nIdades carregadas:\n");
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    printf("Posicao %d: %d\n", i + 1, idades[i]);
                }
                break;

            case 4:
                // Somar
                
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    soma += idades[i];
                }
                printf("Soma das idades: %d\n", soma);
                break;

            case 5:
                // Pares
                printf("\nIdades pares:\n");
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] % 2 == 0) {
                        printf("Posicao %d: %d\n", i + 1, idades[i]);
                    }
                }
                break;

            case 6:
                // Contar pares
                
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] % 2 == 0) {
                        contagemPares++;
                    }
                }
                printf("Total de idades pares: %d\n", contagemPares);
                break;

            case 7:
                // Somar pares
                
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] % 2 == 0) {
                        somaPares += idades[i];
                    }
                }
                printf("Soma das idades pares: %d\n", somaPares);
                break;

            case 8:
                // Menores idade
                printf("\nIdades menores que 18:\n");
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] < 18) {
                        printf("Posicao %d: %d\n", i + 1, idades[i]);
                    }
                }
                break;

            case 9:
                // Contar maiores idade
                
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] >= 18) {
                        contagemMaiores++;
                    }
                }
                printf("Total de idades maiores ou iguais a 18: %d\n", contagemMaiores);
                break;

            case 10:
                // Somar maiores idade
                
                for (i = 0; i < TAMANHO_VETOR; i++) {
                    if (idades[i] >= 18) {
                        somaMaiores += idades[i];
                    }
                }
                printf("Soma das idades maiores ou iguais a 18: %d\n", somaMaiores);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


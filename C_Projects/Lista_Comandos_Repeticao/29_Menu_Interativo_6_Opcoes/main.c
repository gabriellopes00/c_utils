#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int escolha, i;
    int numero;
    int resultado = 1; // Inicializado como 1 para operações de multiplicação

    while (1) {
        printf("\nMenu:\n");
        printf("1. Contar pares\n");
        printf("2. Contar ímpares\n");
        printf("3. Produto pares\n");
        printf("4. Produto ímpares\n");
        printf("9. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 9) {
            printf("Saindo do programa.\n");
            break;
        }

        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);

        switch (escolha) {
            case 1:
                // Contar pares
                for (i = 1; i <= numero; i++) {
                    if (i % 2 == 0) {
                        resultado++;
                    }
                }
                printf("Total de pares: %d\n", resultado - 1); // Ajuste para compensar a inicialização em 1
                break;

            case 2:
                // Contar ímpares
                for (i = 1; i <= numero; i++) {
                    if (i % 2 != 0) {
                        resultado++;
                    }
                }
                printf("Total de impares: %d\n", resultado - 1);
                break;

            case 3:
                // Produto pares
                for (i = 1; i <= numero; i++) {
                    if (i % 2 == 0) {
                        resultado *= i;
                    }
                }
                printf("Produto dos pares: %d\n", resultado);
                break;

            case 4:
                // Produto ímpares
                for (i = 1; i <= numero; i++) {
                    if (i % 2 != 0) {
                        resultado *= i;
                    }
                }
                printf("Produto dos impares: %d\n", resultado);
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
	
	system("pause");
	return 0;
}

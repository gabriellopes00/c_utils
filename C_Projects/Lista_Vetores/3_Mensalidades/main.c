#include <stdio.h>
#include <stdlib.h>

#define MAX_MENSALIDADES 10

int main(int argc, char *argv[]) {
	float mensalidades[MAX_MENSALIDADES] = {0};
    int opcao, i;
    float soma = 0;

    do {
        printf("\n..:: MENSALIDADES ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar\n");
        printf("3. Imprimir\n");
        printf("4. Somar\n");
        printf("0. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Zerar
                for (i = 0; i < MAX_MENSALIDADES; i++) {
                    mensalidades[i] = 0;
                }
                printf("Mensalidades zeradas.\n");
                break;

            case 2:
                // Carregar
                printf("Digite as 10 mensalidades:\n");
                for (i = 0; i < MAX_MENSALIDADES; i++) {
                    printf("Mensalidade %d: ", i + 1);
                    scanf("%f", &mensalidades[i]);
                }
                printf("Mensalidades carregadas.\n");
                break;

            case 3:
                // Imprimir
                printf("\nMensalidades e suas posicoes:\n");
                for (i = 0; i < MAX_MENSALIDADES; i++) {
                    printf("Posicao %d: %.2f\n", i + 1, mensalidades[i]);
                }
                break;

            case 4:
                // Somar
                
                for (i = 0; i < MAX_MENSALIDADES; i++) {
                    soma += mensalidades[i];
                }
                printf("Soma das mensalidades: %.2f\n", soma);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);
	
	system("pause");
	return 0;
}

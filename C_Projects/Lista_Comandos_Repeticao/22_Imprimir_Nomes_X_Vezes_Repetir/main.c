#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char nome[50];
    int repeticoes;
    int contador;
    int continuar;

    do {
        printf("Digite o nome: ");
        scanf("%s", nome);

        printf("Digite o numero de repeticoes: ");
        scanf("%d", &repeticoes);

        contador = 1;
        while (contador <= repeticoes) {
            printf("%d - %s\n", contador, nome);
            contador++;
        }

        printf("Deseja repetir o processamento? (0 = Nao; 1 = Sim): ");
        scanf("%d", &continuar);

    } while (continuar == 1);
	
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valores[4];
    int menor, maior;
    int divisivel1, divisivel2;
    int contador = 0;
    int soma = 0, i, j;

    printf("Digite 4 valores inteiros:\n");

    for (i = 0; i < 4; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);

        if (i == 0 || valores[i] < menor) {
            menor = valores[i];
        }

        if (i == 0 || valores[i] > maior) {
            maior = valores[i];
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Maior valor: %d\n", maior);

    printf("Digite os dois valores para verificar a divisibilidade:\n");
    printf("Valor 1: ");
    scanf("%d", &divisivel1);
    printf("Valor 2: ");
    scanf("%d", &divisivel2);

    if (divisivel1 == 0 || divisivel2 == 0) {
        printf("Um dos valores de divisao e zero, divisao por zero nao e permitida.\n");
    } else {
        for (j = menor; j <= maior; j++) {
            if (j % divisivel1 == 0 && j % divisivel2 == 0) {
                contador++;
                soma += j;
            }
        }

        printf("Quantidade de valores divisiveis por %d e %d: %d\n", divisivel1, divisivel2, contador);
        printf("Soma dos valores divisiveis: %d\n", soma);
    }
	
	system("pause");
	return 0;
}

#include <stdio.h>

int main() {
    int valores[4];
    int menor, maior;
    int divisivel1, divisivel2;
    int contador = 0;
    int soma = 0, i;

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
        printf("Um dos valores de divisão é zero, divisão por zero não é permitida.\n");
    } else {
        for (int i = menor; i <= maior; i++) {
            if (i % divisivel1 == 0 && i % divisivel2 == 0) {
                contador++;
                soma += i;
            }
        }

        printf("Quantidade de valores divisíveis por %d e %d: %d\n", divisivel1, divisivel2, contador);
        printf("Soma dos valores divisíveis: %d\n", soma);
    }

    return 0;
}

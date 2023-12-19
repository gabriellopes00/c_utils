#include <stdio.h>

int main() {
    int A, B, C;
    int contador = 0;
    int soma = 0, i;

    printf("Digite três valores inteiros (A, B e C):\n");
    scanf("%d %d %d", &A, &B, &C);

    printf("Valores divisíveis por %d entre %d e %d:\n", C, A, B);

    for (i = A; i <= B; i++) {
        if (i % C == 0) {
            printf("%d ", i);
            contador++;
            soma += i;
        }
    }

    printf("\nNúmero de valores divisíveis: %d\n", contador);
    printf("Soma dos valores divisíveis: %d\n", soma);

    return 0;
}

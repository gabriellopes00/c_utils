#include <stdio.h>

int main() {
    int A, B, C;
    int contador = 0;
    int soma = 0, i;

    printf("Digite tress valores inteiros (A, B e C):\n");
    scanf("%d %d %d", &A, &B, &C);

    printf("Valores divisiveis por %d entre %d e %d:\n", C, A, B);

    for (i = A; i <= B; i++) {
        if (i % C == 0) {
            printf("%d ", i);
            contador++;
            soma += i;
        }
    }

    printf("Numero de valores divisiveis: %d\n", contador);
    printf("Soma dos valores divisiveis: %d\n", soma);

    return 0;
}

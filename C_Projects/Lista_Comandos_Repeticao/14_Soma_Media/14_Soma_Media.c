#include <stdio.h>

int main() {
    int valores[6];
    int soma = 0, i;
    float media;

    printf("Digite 6 valores:\n");

    for (i = 0; i < 6; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);
        soma += valores[i];
    }

    media = (float)soma / 6;

    printf("Soma dos valores: %d\n", soma);
    printf("Média dos valores: %.2f\n", media);

    return 0;
}

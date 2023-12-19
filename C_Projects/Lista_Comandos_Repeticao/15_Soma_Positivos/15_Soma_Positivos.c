#include <stdio.h>

int main() {
    int valor;
    int soma = 0;
    int numero_de_valores = 0;
    float media;

    printf("Digite valores positivos (ou um valor negativo para sair):\n");

    while (1) {
        printf("Digite um valor: ");
        scanf("%d", &valor);

        if (valor < 0) {
            break; 
        }

        soma += valor;
        numero_de_valores++;
    }

    if (numero_de_valores > 0) {
        media = (float)soma / numero_de_valores;
        printf("Soma dos valores: %d\n", soma);
        printf("Número de valores somados: %d\n", numero_de_valores);
        printf("Média dos valores: %.2f\n", media);
    } else {
        printf("Nenhum valor positivo foi fornecido.\n");
    }

    return 0;
}

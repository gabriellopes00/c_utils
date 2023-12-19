#include <stdio.h>

int main() {
    int quadrado = 1; 
    long long int total_graos = 1; 

    printf("Tabuleiro de xadrez (8x8) - Número de grãos em cada quadrado:\n");

    while (quadrado <= 64) {
        printf("Quadrado %d: %lld grãos\n", quadrado, total_graos);

        total_graos *= 2;

        quadrado++;
    }

    printf("\nTotal de grãos no tabuleiro: %lld\n", total_graos);

    return 0;
}

#include <stdio.h>

unsigned long long int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    unsigned long long int soma = 0;
    int numero_de_impares = 0, i;

    printf("Soma dos fatoriais dos valores ímpares de 1 a 20:\n");

    for (i = 1; i <= 20; i += 2) {
        unsigned long long int fatorial_i = fatorial(i);
        soma += fatorial_i;
        numero_de_impares++;
        printf("%d! = %llu\n", i, fatorial_i);
    }

    printf("Soma dos fatoriais: %llu\n", soma);
    printf("Número de valores ímpares: %d\n", numero_de_impares);

    return 0;
}

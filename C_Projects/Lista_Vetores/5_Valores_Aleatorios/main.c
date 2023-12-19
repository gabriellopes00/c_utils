#include <stdio.h>

int main() {
    int A, B, C;
    int contador = 0;
    int soma = 0, i;

    printf("Digite três valores inteiros (A, B e C):\n");
    scanf("%d %d %d", &A, &B, &C);
    
    if(A < 0 | B < 0 | C < 0){
     printf("Valores menores que zero");
     return 0;
    }
    
    if (C < B){
	 printf("C e menor que B");
     return 0;
	}

    printf("Valores divisiveis por %d entre %d e %d:\n", C, A, B);

    for (i = A; i <= B; i++) {
        if (i % C == 0) {
            printf("%d ", i);
            contador++;
            soma += i;
        }
    }

    printf("numero de valores divisiveis: %d\n", contador);
    printf("Soma dos valores divisiveis: %d\n", soma);

    return 0;
}

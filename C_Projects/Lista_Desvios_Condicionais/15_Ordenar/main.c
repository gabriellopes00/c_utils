#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
	int valor1, valor2, valor3;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &valor3);

    if (valor1 > valor2) {
        trocar(&valor1, &valor2);
    }
    if (valor2 > valor3) {
        trocar(&valor2, &valor3);
    }
    if (valor1 > valor2) {
        trocar(&valor1, &valor2);
    }

    printf("Valores ordenados: %d, %d, %d\n", valor1, valor2, valor3);
	
	system("pause");
	return 0;
}

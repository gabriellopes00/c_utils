#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor, resultado;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    if (valor % 2 == 0) {
        resultado = valor * 2;
        printf("O resultado da operacao (par * 2) e: %d\n", resultado);
    } else {
        resultado = valor - 3;
        printf("O resultado da operacao (impar - 3) e: %d\n", resultado);
    }
	
	system("pause");
	return 0;
}

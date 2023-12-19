#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    if (valor <= 0) {
        valor = -valor;
    }

    printf("O valor positivo e: %d\n", valor);	
	
	system("pause");
	return 0;
}

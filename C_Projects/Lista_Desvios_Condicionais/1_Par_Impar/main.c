#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    if (valor % 2 == 0) {
        printf("%d e um valor par.\n", valor);
    } else {
        printf("%d e um valor impar.\n", valor);
    }
	
	system("pause");
	return 0;
}
